#include "Game/T4/Weapon/FlameTableLoaderT4.h"

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
    TEST_CASE("FlameTableLoader(T4): Returns no action when file is missing", "[t4][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT4(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateSubAsset("debugflametable", context).HasBeenSuccessful());
    }

    TEST_CASE("FlameTableLoader(T4): Can parse float fields", "[t4][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "weapons/debugflametable",
            R"(FLAMETABLEFILE\name\debugflametable\flameVar_streamChunkGravityStart\200\flameVar_streamChunkGravityEnd\150\flameVar_fireLife\0.5\flameVar_smokeMaxAlpha\0.8\flameVar_collisionSpeedScale\1.5\fire\\smoke\\heat\\drips\\streamFuel\\streamFuel2\\streamFlame\\streamFlame2\\flameOffLoopSound\\flameIgniteSound\\flameOnLoopSound\\flameCooldownSound\)");

        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT4(memory, searchPath, zone);
        auto result = loader->CreateSubAsset("debugflametable", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* ft = reinterpret_cast<XAssetInfo<FlameTable>*>(result.GetAssetInfo())->Asset();

        REQUIRE(ft->name == "debugflametable"s);
        REQUIRE(ft->flameVar_streamChunkGravityStart == Approx(200.0f));
        REQUIRE(ft->flameVar_streamChunkGravityEnd == Approx(150.0f));
        REQUIRE(ft->flameVar_fireLife == Approx(0.5f));
        REQUIRE(ft->flameVar_smokeMaxAlpha == Approx(0.8f));
        REQUIRE(ft->flameVar_collisionSpeedScale == Approx(1.5f));
        REQUIRE(ft->fire == nullptr);
        REQUIRE(ft->heat == nullptr);
        REQUIRE(ft->flameOffLoopSound.name == nullptr);
        REQUIRE(ft->flameCooldownSound.name == nullptr);
    }

    TEST_CASE("FlameTableLoader(T4): Stores sound name in SndAliasCustom", "[t4][flametable][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "weapons/debugflametable",
            R"(FLAMETABLEFILE\fire\\smoke\\heat\\drips\\streamFuel\\streamFuel2\\streamFlame\\streamFlame2\\flameOffLoopSound\weap_flame_off\flameIgniteSound\\flameOnLoopSound\\flameCooldownSound\)");

        Zone zone("MockZone", 0, GameId::T4, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = weapon::CreateFlameTableLoaderT4(memory, searchPath, zone);
        auto result = loader->CreateSubAsset("debugflametable", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* ft = reinterpret_cast<XAssetInfo<FlameTable>*>(result.GetAssetInfo())->Asset();
        REQUIRE(ft->flameOffLoopSound.name != nullptr);
        REQUIRE(ft->flameOffLoopSound.name->soundName == "weap_flame_off"s);
        REQUIRE(ft->flameIgniteSound.name == nullptr);
    }
} // namespace
