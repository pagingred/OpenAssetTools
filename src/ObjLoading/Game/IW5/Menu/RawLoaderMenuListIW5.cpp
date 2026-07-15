#include "RawLoaderMenuListIW5.h"

#include "Game/IW5/IW5.h"
#include "Menu/AbstractMenuListLoader.h"
#include "Utils/Logging/Log.h"

#include <algorithm>
#include <string>
#include <vector>

using namespace IW5;

namespace
{
    static std::string GetPropertyString(MenuParser::PropertyValueContext* pv)
    {
        if (auto* s = dynamic_cast<MenuParser::StringPropertyValueContext*>(pv))
        {
            const auto raw = s->STRING()->getText();
            return raw.size() >= 2 ? raw.substr(1, raw.size() - 2) : raw;
        }
        if (auto* id = dynamic_cast<MenuParser::IdentifierPropertyValueContext*>(pv))
            return id->IDENTIFIER()->getText();
        return {};
    }

    static float GetPropertyFloat(MenuParser::PropertyValueContext* pv)
    {
        if (auto* f = dynamic_cast<MenuParser::FloatPropertyValueContext*>(pv))
            return std::stof(f->FLOAT()->getText());
        if (auto* i = dynamic_cast<MenuParser::IntegerPropertyValueContext*>(pv))
            return std::stof(i->INTEGER()->getText());
        return 0.0f;
    }

    static int GetPropertyInt(MenuParser::PropertyValueContext* pv)
    {
        if (auto* i = dynamic_cast<MenuParser::IntegerPropertyValueContext*>(pv))
            return std::stoi(i->INTEGER()->getText());
        if (auto* f = dynamic_cast<MenuParser::FloatPropertyValueContext*>(pv))
            return static_cast<int>(std::stof(f->FLOAT()->getText()));
        return 0;
    }

    static void FindMenuDefsInPart(MenuParser::MenuFilePartContext* part, std::vector<MenuParser::MenuDefContext*>& result)
    {
        if (auto* p = dynamic_cast<MenuParser::MenuDefMenuFilePartContext*>(part))
            result.push_back(p->menuDef());
        else if (auto* p = dynamic_cast<MenuParser::WrapperMenuFilePartContext*>(part))
            for (auto* nested : p->menuFilePart())
                FindMenuDefsInPart(nested, result);
    }

    static std::vector<MenuParser::MenuDefContext*> FindAllMenuDefs(MenuParser::MenuFileContext* tree)
    {
        std::vector<MenuParser::MenuDefContext*> result;
        for (auto* part : tree->menuFilePart())
            FindMenuDefsInPart(part, result);
        return result;
    }

    class RawLoaderMenuList final : public menu::AbstractMenuListLoader<AssetMenuList>
    {
    public:
        using AbstractMenuListLoader::AbstractMenuListLoader;

    protected:
        bool FillFromTree(MenuList& menuList,
                          const std::string& assetName,
                          MenuParser::MenuFileContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<AssetMenuList>& registration) override
        {
            menuList.name = m_memory.Dup(assetName.c_str());

            const auto menuDefs = FindAllMenuDefs(tree);
            std::vector<menuDef_t*> menus;
            menus.reserve(menuDefs.size());

            for (auto* defCtx : menuDefs)
            {
                auto* menuDef = m_memory.Alloc<menuDef_t>();
                if (!FillMenuDef(*menuDef, defCtx))
                    return false;

                const std::string menuName = menuDef->window.name ? menuDef->window.name : assetName;
                AssetRegistration<AssetMenu> menuReg(menuName, menuDef);
                auto* menuAssetInfo = context.AddAsset(std::move(menuReg));
                if (menuAssetInfo)
                    registration.AddDependency(menuAssetInfo);

                menus.push_back(menuDef);
            }

            menuList.menuCount = static_cast<int>(menus.size());
            if (menuList.menuCount > 0)
            {
                menuList.menus = m_memory.Alloc<menuDef_t*>(static_cast<size_t>(menuList.menuCount));
                for (auto i = 0; i < menuList.menuCount; i++)
                    menuList.menus[i] = menus[i];
            }
            else
                menuList.menus = nullptr;

            return true;
        }

    private:
        bool FillMenuDef(menuDef_t& menuDef, MenuParser::MenuDefContext* ctx)
        {
            for (auto* item : ctx->menuItem())
            {
                auto* propItem = dynamic_cast<MenuParser::PropertyMenuItemContext*>(item);
                if (!propItem)
                    continue;

                const auto key = propItem->IDENTIFIER()->getText();
                const auto& values = propItem->propertyValue();

                if (key == "name" && !values.empty())
                {
                    menuDef.window.name = m_memory.Dup(GetPropertyString(values[0]).c_str());
                }
                else if (key == "fullScreen" && !values.empty())
                {
                    menuDef.fullScreen = GetPropertyInt(values[0]);
                }
                else if (key == "screenSpace")
                {
                    menuDef.window.staticFlags |= WINDOW_FLAG_SCREEN_SPACE;
                }
                else if (key == "decoration")
                {
                    menuDef.window.staticFlags |= WINDOW_FLAG_DECORATION;
                }
                else if (key == "outOfBoundsClick")
                {
                    menuDef.window.staticFlags |= WINDOW_FLAG_OUT_OF_BOUNDS_CLICK;
                }
                else if (key == "popup")
                {
                    menuDef.window.staticFlags |= WINDOW_FLAG_POPUP;
                }
                else if (key == "rect" && values.size() >= 4)
                {
                    menuDef.window.rect.x = GetPropertyFloat(values[0]);
                    menuDef.window.rect.y = GetPropertyFloat(values[1]);
                    menuDef.window.rect.w = GetPropertyFloat(values[2]);
                    menuDef.window.rect.h = GetPropertyFloat(values[3]);
                    if (values.size() >= 5)
                        menuDef.window.rect.horzAlign = static_cast<unsigned char>(GetPropertyInt(values[4]));
                    if (values.size() >= 6)
                        menuDef.window.rect.vertAlign = static_cast<unsigned char>(GetPropertyInt(values[5]));
                }
                else if (key == "style" && !values.empty())
                {
                    menuDef.window.style = GetPropertyInt(values[0]);
                }
                else if (key == "border" && !values.empty())
                {
                    menuDef.window.border = GetPropertyInt(values[0]);
                }
                else if (key == "borderSize" && !values.empty())
                {
                    menuDef.window.borderSize = GetPropertyFloat(values[0]);
                }
                else if (key == "backColor" && !values.empty())
                {
                    for (auto i = 0u; i < std::min(values.size(), std::size_t(4)); i++)
                        menuDef.window.backColor[i] = GetPropertyFloat(values[i]);
                }
                else if (key == "foreColor" && !values.empty())
                {
                    for (auto i = 0u; i < std::min(values.size(), std::size_t(4)); i++)
                        menuDef.window.foreColor[i] = GetPropertyFloat(values[i]);
                }
                else if (key == "focusColor" && !values.empty())
                {
                    for (auto i = 0u; i < std::min(values.size(), std::size_t(4)); i++)
                        menuDef.focusColor[i] = GetPropertyFloat(values[i]);
                }
                else if (key == "soundLoop" && !values.empty())
                {
                    menuDef.soundName = m_memory.Dup(GetPropertyString(values[0]).c_str());
                }
                else if (key == "allowedBinding" && !values.empty())
                {
                    menuDef.allowedBinding = m_memory.Dup(GetPropertyString(values[0]).c_str());
                }
                else if (key == "blurWorld" && !values.empty())
                {
                    menuDef.blurRadius = GetPropertyFloat(values[0]);
                }
            }

            return true;
        }
    };
} // namespace

namespace menu
{
    std::unique_ptr<AssetCreator<IW5::AssetMenuList>> CreateRawLoaderMenuListIW5(MemoryManager& memory, ISearchPath& searchPath)
    {
        return std::make_unique<RawLoaderMenuList>(memory, searchPath);
    }
} // namespace menu
