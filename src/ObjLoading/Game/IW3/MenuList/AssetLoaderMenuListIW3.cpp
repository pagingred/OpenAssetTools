#include "AssetLoaderMenuListIW3.h"

#include "Game/IW3/IW3.h"

#include <cstring>

using namespace IW3;

namespace
{
    class MenuListLoader final : public AssetCreator<AssetMenuList>
    {
    public:
        MenuListLoader(MemoryManager& memory, ISearchPath& searchPath)
            : m_memory(memory),
              m_search_path(searchPath)
        {
        }

        AssetCreationResult CreateAsset(const std::string& assetName, AssetCreationContext& context) override
        {
            const auto file = m_search_path.Open(assetName);
            if (!file.IsOpen())
                return AssetCreationResult::NoAction();

            return AssetCreationResult::Failure();

            //return AssetCreationResult::Success(context.AddAsset<AssetStringTable>(assetName, stringTable));
        }

    private:
        MemoryManager& m_memory;
        ISearchPath& m_search_path;
    };
} // namespace

namespace menu_list
{
    std::unique_ptr<AssetCreator<AssetMenuList>> CreateLoaderIW3(MemoryManager& memory, ISearchPath& searchPath)
    {
        return std::make_unique<MenuListLoader>(memory, searchPath);
    }
} // namespace string_table
