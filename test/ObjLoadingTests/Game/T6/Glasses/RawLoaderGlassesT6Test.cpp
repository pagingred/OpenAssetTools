#include "Game/T6/Glasses/RawLoaderGlassesT6.h"

#include "Game/T6/GameT6.h"
#include "SearchPath/MockSearchPath.h"
#include "Utils/MemoryManager.h"

#include <catch2/catch_test_macros.hpp>
#include <string>

using namespace T6;
using namespace std::literals;

namespace
{
    TEST_CASE("RawLoaderGlasses(T6): Returns no action when file is missing", "[t6][glasses][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = glasses::CreateRawLoaderT6(memory, searchPath);
        REQUIRE_FALSE(loader->CreateAsset("mp_nuketown_2025", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderGlasses(T6): Can parse glasses file", "[t6][glasses][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "glasses/mp_nuketown_2025",
            "# verbose\n"
            "\n"
            "common,18000\n"
            "\n"
            "smallAllocatorBlocks,200,5,160,10,120,50,100,100\n"
            "groups,10\n"
            "shards,50\n"
            "physics,30\n"
            "shardMemory,11000\n"
            "freeCmd,40\n"
            "slots,20\n"
            "verts,1600,5,1024,20\n"
            "\n"
            "# These are values from sizeof()\n"
            "ShardGroupSize,92\n"
            "ShardSize,176\n"
            "PhysicsSize,160\n");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = glasses::CreateRawLoaderT6(memory, searchPath);
        auto result = loader->CreateAsset("mp_nuketown_2025", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* g = reinterpret_cast<XAssetInfo<Glasses>*>(result.GetAssetInfo())->Asset();

        REQUIRE(g->name == "mp_nuketown_2025"s);
        REQUIRE(g->workMemorySize == 18000u);
        REQUIRE(g->smallAllocatorBlocks == 200u);
        REQUIRE(g->maxGroups == 10u);
        REQUIRE(g->maxShards == 50u);
        REQUIRE(g->maxPhysics == 30u);
        REQUIRE(g->shardMemorySize == 11000u);
        REQUIRE(g->maxFreeCmd == 40u);
        REQUIRE(g->numSlots == 20u);
        REQUIRE(g->numVerts == 1600u);
    }

    TEST_CASE("RawLoaderGlasses(T6): Empty values produce zero", "[t6][glasses][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "glasses/mp_nuketown_2025",
            "groups,\n"
            "shards,\n"
            "physics,\n"
            "freeCmd,\n");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = glasses::CreateRawLoaderT6(memory, searchPath);
        auto result = loader->CreateAsset("mp_nuketown_2025", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* g = reinterpret_cast<XAssetInfo<Glasses>*>(result.GetAssetInfo())->Asset();

        REQUIRE(g->maxGroups == 0u);
        REQUIRE(g->maxShards == 0u);
        REQUIRE(g->maxPhysics == 0u);
        REQUIRE(g->maxFreeCmd == 0u);
    }

    TEST_CASE("RawLoaderGlasses(T6): Unknown keys are ignored", "[t6][glasses][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "glasses/mp_nuketown_2025",
            "ShardGroupSize,92\n"
            "ShardSize,176\n"
            "PhysicsSize,160\n"
            "slots,20\n");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = glasses::CreateRawLoaderT6(memory, searchPath);
        auto result = loader->CreateAsset("mp_nuketown_2025", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* g = reinterpret_cast<XAssetInfo<Glasses>*>(result.GetAssetInfo())->Asset();
        REQUIRE(g->numSlots == 20u);
    }
} // namespace
