#include "Game/T6/Menu/RawLoaderMenuDefT6.h"

#include "Game/T6/GameT6.h"
#include "SearchPath/MockSearchPath.h"
#include "Utils/MemoryManager.h"

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace T6;
using namespace Catch;
using namespace std::literals;

namespace
{
    constexpr unsigned WINDOW_FLAG_SCREEN_SPACE = 0x400000U;
    constexpr unsigned WINDOW_FLAG_DECORATION = 0x100000U;

    TEST_CASE("RawLoaderMenuDef(T6): Returns no action when file is missing", "[t6][menu][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuDefT6(memory, searchPath);
        REQUIRE_FALSE(loader->CreateAsset("test.menu", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderMenuDef(T6): Can parse basic menu def", "[t6][menu][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("test.menu", R"(
{
    menuDef
    {
        name "TestMenu"
        fullScreen 1
    }
}
)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuDefT6(memory, searchPath);
        const auto result = loader->CreateAsset("test.menu", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* menu = reinterpret_cast<XAssetInfo<menuDef_t>*>(result.GetAssetInfo())->Asset();
        REQUIRE(menu->window.name == "TestMenu"s);
        REQUIRE(menu->fullScreen == 1);
    }

    TEST_CASE("RawLoaderMenuDef(T6): Can parse menu def properties", "[t6][menu][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("test.menu", R"(
{
    menuDef
    {
        name "Props"
        fullScreen 0
        screenSpace
        decoration
        rect 10 20 320 240 1 2
        style 3
        border 1
        borderSize 2.5
        backColor 0.1 0.2 0.3 0.8
        foreColor 0.9 0.8 0.7 1
    }
}
)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuDefT6(memory, searchPath);
        const auto result = loader->CreateAsset("test.menu", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* menu = reinterpret_cast<XAssetInfo<menuDef_t>*>(result.GetAssetInfo())->Asset();
        REQUIRE(menu->window.name == "Props"s);
        REQUIRE(menu->fullScreen == 0);
        REQUIRE(menu->window.staticFlags & WINDOW_FLAG_SCREEN_SPACE);
        REQUIRE(menu->window.staticFlags & WINDOW_FLAG_DECORATION);
        REQUIRE_THAT(menu->window.rect.x, Approx(10.0f));
        REQUIRE_THAT(menu->window.rect.y, Approx(20.0f));
        REQUIRE_THAT(menu->window.rect.w, Approx(320.0f));
        REQUIRE_THAT(menu->window.rect.h, Approx(240.0f));
        REQUIRE(menu->window.rect.horzAlign == 1);
        REQUIRE(menu->window.rect.vertAlign == 2);
        REQUIRE(menu->window.style == 3);
        REQUIRE(menu->window.border == 1);
        REQUIRE_THAT(menu->window.borderSize, Approx(2.5f));
        REQUIRE_THAT(menu->window.backColor[0], Approx(0.1f));
        REQUIRE_THAT(menu->window.backColor[1], Approx(0.2f));
        REQUIRE_THAT(menu->window.backColor[2], Approx(0.3f));
        REQUIRE_THAT(menu->window.backColor[3], Approx(0.8f));
        REQUIRE_THAT(menu->window.foreColor[0], Approx(0.9f));
        REQUIRE_THAT(menu->window.foreColor[1], Approx(0.8f));
        REQUIRE_THAT(menu->window.foreColor[2], Approx(0.7f));
        REQUIRE_THAT(menu->window.foreColor[3], Approx(1.0f));
    }

    TEST_CASE("RawLoaderMenuDef(T6): Returns failure when file has no menuDef", "[t6][menu][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("test.menu", R"(
{
    loadMenu { "other.menu" }
}
)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = menu::CreateRawLoaderMenuDefT6(memory, searchPath);
        const auto result = loader->CreateAsset("test.menu", context);
        REQUIRE_FALSE(result.HasBeenSuccessful());
    }
} // namespace
