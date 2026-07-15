#include "Game/T6/Weapon/FlameTableLoaderT6.h"

#include "Game/T6/T6.h"
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
    TEST_CASE("FlameTableLoader(T6): Returns no action when file is missing", "[t6][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT6(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateSubAsset("debugflametable", context).HasBeenSuccessful());
    }

    TEST_CASE("FlameTableLoader(T6): Can parse float fields including T6-exclusive brightness fields", "[t6][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "weapons/debugflametable",
            R"(FLAMETABLEFILE\name\debugflametable\flameVar_streamChunkGravityStart\200\flameVar_fireLife\0.5\flameVar_fireBrightness\1.2\flameVar_dripsBrightness\0.7\flameVar_smokeMaxAlpha\0.8\fire\\smoke\\heat\\drips\\streamFuel\\streamFuel2\\streamFlame\\streamFlame2\\flameOffLoopSound\\flameIgniteSound\\flameOnLoopSound\\flameCooldownSound\)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateSubAsset("debugflametable", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* ft = reinterpret_cast<XAssetInfo<FlameTable>*>(result.GetAssetInfo())->Asset();

        REQUIRE(ft->name == "debugflametable"s);
        REQUIRE(ft->flameVar_streamChunkGravityStart == Approx(200.0f));
        REQUIRE(ft->flameVar_fireLife == Approx(0.5f));
        REQUIRE(ft->flameVar_fireBrightness == Approx(1.2f));
        REQUIRE(ft->flameVar_dripsBrightness == Approx(0.7f));
        REQUIRE(ft->flameVar_smokeMaxAlpha == Approx(0.8f));
        REQUIRE(ft->fire == nullptr);
        REQUIRE(ft->heat == nullptr);
        REQUIRE(ft->flameOffLoopSound == nullptr);
    }

    TEST_CASE("FlameTableLoader(T6): Stores sound name as string", "[t6][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "weapons/debugflametable",
            R"(FLAMETABLEFILE\fire\\smoke\\heat\\drips\\streamFuel\\streamFuel2\\streamFlame\\streamFlame2\\flameOffLoopSound\weap_flame_off\flameIgniteSound\\flameOnLoopSound\\flameCooldownSound\)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateSubAsset("debugflametable", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* ft = reinterpret_cast<XAssetInfo<FlameTable>*>(result.GetAssetInfo())->Asset();
        REQUIRE(ft->flameOffLoopSound == "weap_flame_off"s);
        REQUIRE(ft->flameIgniteSound == nullptr);
    }
} // namespace
