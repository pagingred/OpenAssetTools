#include "Game/T6/ZBarrier/RawLoaderZBarrierT6.h"

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
    TEST_CASE("RawLoaderZBarrier(T6): Returns no action when file is missing", "[t6][zbarrier][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = z_barrier::CreateRawLoaderT6(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateAsset("entrance", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderZBarrier(T6): Can parse zbarrier", "[t6][zbarrier][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "zbarrier/entrance",
            R"(ZBARRIER\delayBetweenGeneralRepSounds\0.5\earthquakeMaxDuration\2.0\earthquakeMaxScale\1.5\earthquakeMinDuration\0.25\earthquakeMinScale\0.3\earthquakeOnRepair\1\earthquakeRadius\100.0\useDelayBetweenGeneralRepSounds\1\taunts\1\reachThroughAttacks\0\numAttackSlots\4\attackSpotHorzOffset\12.5\autoHideOpenPieces\0\pauseBetweenRepSoundsMax1\3.0\pauseBetweenRepSoundsMin1\1.5)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = z_barrier::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("entrance", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* zb = reinterpret_cast<XAssetInfo<ZBarrierDef>*>(result.GetAssetInfo())->Asset();

        REQUIRE(zb->name == "entrance"s);
        REQUIRE(zb->delayBetweenRepSoundsDuration == Approx(0.5f));
        REQUIRE(zb->earthquakeMaxDuration == Approx(2.0f));
        REQUIRE(zb->earthquakeMaxScale == Approx(1.5f));
        REQUIRE(zb->earthquakeMinDuration == Approx(0.25f));
        REQUIRE(zb->earthquakeMinScale == Approx(0.3f));
        REQUIRE(zb->earthquakeOnRepair == 1u);
        REQUIRE(zb->earthquakeRadius == Approx(100.0f));
        REQUIRE(zb->delayBetweenRepSounds == 1u);
        REQUIRE(zb->taunts == 1u);
        REQUIRE(zb->reachThroughAttacks == 0u);
        REQUIRE(zb->numAttackSlots == 4);
        REQUIRE(zb->attackSpotHorzOffset == Approx(12.5f));
        REQUIRE(zb->autoHideOpenPieces == 0u);
        REQUIRE(zb->boards[0].maxPause == Approx(3.0f));
        REQUIRE(zb->boards[0].minPause == Approx(1.5f));
    }

    TEST_CASE("RawLoaderZBarrier(T6): Calculates numBoardsInBarrier from board models", "[t6][zbarrier][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = z_barrier::CreateRawLoaderT6(memory, searchPath, zone);

        SECTION("numBoardsInBarrier is 0 when no board models are set")
        {
            searchPath.AddFileData("zbarrier/entrance", R"(ZBARRIER\earthquakeRadius\50.0)");
            auto result = loader->CreateAsset("entrance", context);
            REQUIRE(result.HasBeenSuccessful());
            REQUIRE(reinterpret_cast<XAssetInfo<ZBarrierDef>*>(result.GetAssetInfo())->Asset()->numBoardsInBarrier == 0);
        }
    }

    TEST_CASE("RawLoaderZBarrier(T6): Stores script strings for anim states", "[t6][zbarrier][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("zbarrier/entrance", R"(ZBARRIER\zombieTauntAnimState\zomb_idle\zombieReachThroughAnimState\zomb_reach)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = z_barrier::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("entrance", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* zb = reinterpret_cast<XAssetInfo<ZBarrierDef>*>(result.GetAssetInfo())->Asset();

        REQUIRE(zone.m_script_strings[zb->zombieTauntAnimState] == "zomb_idle"s);
        REQUIRE(zone.m_script_strings[zb->zombieReachThroughAnimState] == "zomb_reach"s);
    }
} // namespace
