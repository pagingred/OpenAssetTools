#include "Game/T4/Menu/RawLoaderMenuListT4.h"

#include "Game/T4/GameT4.h"
#include "SearchPath/MockSearchPath.h"
#include "Utils/MemoryManager.h"

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace T4;
using namespace Catch;
using namespace std::literals;

namespace
{
    constexpr unsigned WINDOW_FLAG_SCREEN_SPACE = 0x400000U;

    TEST_CASE("RawLoaderMenuList(T4): Returns no action when file is missing", "[t4][menulist][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuListT4(memory, searchPath);
        REQUIRE_FALSE(loader->CreateAsset("ui/test.menu", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderMenuList(T4): Can load menu list with one menu", "[t4][menulist][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("ui/test.menu", R"(
{
    menuDef
    {
        name "TestMenu"
        fullScreen 1
    }
}
)");

        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuListT4(memory, searchPath);
        const auto result = loader->CreateAsset("ui/test.menu", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* menuList = reinterpret_cast<XAssetInfo<MenuList>*>(result.GetAssetInfo())->Asset();
        REQUIRE(menuList->name == "ui/test.menu"s);
        REQUIRE(menuList->menuCount == 1);
        REQUIRE(menuList->menus != nullptr);

        const auto* menuAsset = zone.m_pools.GetAsset(ASSET_TYPE_MENU, "TestMenu");
        REQUIRE(menuAsset != nullptr);
        const auto* menu = static_cast<menuDef_t*>(menuAsset->m_ptr);
        REQUIRE(menu->window.name == "TestMenu"s);
        REQUIRE(menu->fullScreen == 1);
        REQUIRE(menuList->menus[0] == menu);
    }

    TEST_CASE("RawLoaderMenuList(T4): Can load menu list with multiple menus", "[t4][menulist][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("ui/test.menu", R"(
{
    menuDef
    {
        name "Menu1"
        fullScreen 1
    }
    menuDef
    {
        name "Menu2"
        fullScreen 0
        screenSpace
    }
}
)");

        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuListT4(memory, searchPath);
        const auto result = loader->CreateAsset("ui/test.menu", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* menuList = reinterpret_cast<XAssetInfo<MenuList>*>(result.GetAssetInfo())->Asset();
        REQUIRE(menuList->menuCount == 2);
        REQUIRE(menuList->menus != nullptr);

        const auto* menu1 = static_cast<menuDef_t*>(zone.m_pools.GetAsset(ASSET_TYPE_MENU, "Menu1")->m_ptr);
        const auto* menu2 = static_cast<menuDef_t*>(zone.m_pools.GetAsset(ASSET_TYPE_MENU, "Menu2")->m_ptr);

        REQUIRE(menu1->window.name == "Menu1"s);
        REQUIRE(menu1->fullScreen == 1);
        REQUIRE(menu2->window.name == "Menu2"s);
        REQUIRE(menu2->window.staticFlags & WINDOW_FLAG_SCREEN_SPACE);
    }

    TEST_CASE("RawLoaderMenuList(T4): Can load empty menu list", "[t4][menulist][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("ui/test.menu", R"(
{
}
)");

        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuListT4(memory, searchPath);
        const auto result = loader->CreateAsset("ui/test.menu", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* menuList = reinterpret_cast<XAssetInfo<MenuList>*>(result.GetAssetInfo())->Asset();
        REQUIRE(menuList->menuCount == 0);
        REQUIRE(menuList->menus == nullptr);
    }
} // namespace
