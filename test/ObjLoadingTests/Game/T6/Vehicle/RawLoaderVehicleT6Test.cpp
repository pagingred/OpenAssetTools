#include "Game/T6/Vehicle/RawLoaderVehicleT6.h"

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
    TEST_CASE("RawLoaderVehicle(T6): Returns no action when file is missing", "[t6][vehicle][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = vehicle::CreateRawLoaderT6(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateAsset("hind", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderVehicle(T6): Can parse basic vehicle fields", "[t6][vehicle][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "vehicles/hind",
            R"(VEHICLEFILE\cameraMode\chase\numberOfSeats\4\maxSpeed\60\cameraFOV\65.0\remoteControl\1)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = vehicle::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("hind", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* def = reinterpret_cast<XAssetInfo<VehicleDef>*>(result.GetAssetInfo())->Asset();

        REQUIRE(def->name == "hind"s);
        REQUIRE(def->cameraMode == 1); // "chase" is index 1
        REQUIRE(def->numberOfSeats == 4);
        REQUIRE(def->maxSpeed == Approx(60.0f * 17.6f));
        REQUIRE(def->cameraFOV == Approx(65.0f));
        REQUIRE(def->remoteControl == 1);
    }

    TEST_CASE("RawLoaderVehicle(T6): Can parse vehicle type including space in value", "[t6][vehicle][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("vehicles/car", R"(VEHICLEFILE\type\4 wheel)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = vehicle::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("car", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* def = reinterpret_cast<XAssetInfo<VehicleDef>*>(result.GetAssetInfo())->Asset();
        REQUIRE(def->type == 0); // "4 wheel" is index 0
    }

    TEST_CASE("RawLoaderVehicle(T6): Converts mph to inches per second", "[t6][vehicle][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("vehicles/hind", R"(VEHICLEFILE\maxSpeed\100\accel\50)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = vehicle::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("hind", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* def = reinterpret_cast<XAssetInfo<VehicleDef>*>(result.GetAssetInfo())->Asset();
        REQUIRE(def->maxSpeed == Approx(100.0f * 17.6f));
        REQUIRE(def->accel == Approx(50.0f * 17.6f));
    }

    TEST_CASE("RawLoaderVehicle(T6): Can parse traction type", "[t6][vehicle][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("vehicles/tank", R"(VEHICLEFILE\nitrous_traction_type\TRACTION_TYPE_ALL_WD)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = vehicle::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("tank", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* def = reinterpret_cast<XAssetInfo<VehicleDef>*>(result.GetAssetInfo())->Asset();
        REQUIRE(def->nitrousVehParams.m_traction_type == TRACTION_TYPE_ALL_WD);
    }
} // namespace
