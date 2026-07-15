#include "Game/T6/PhysConstraints/RawLoaderPhysConstraintsT6.h"

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
    TEST_CASE("RawLoaderPhysConstraints(T6): Returns no action when file is missing", "[t6][physconstraints][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = phys_constraints::CreateRawLoaderT6(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateAsset("test_constraints", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderPhysConstraints(T6): Can parse phys constraints", "[t6][physconstraints][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "physconstraints/test_constraints",
            R"(PHYSCONSTRAINTS\c1_type\hinge\c1_bone1_name\tag_origin\c1_bone2_name\tag_body\c1_offsetX\10\c1_offsetY\-5\c1_offsetZ\2\c1_timeout\5000\c1_min_health\0\c1_max_health\100\c1_damp\0.8\c1_power\1500\c1_spin_scale\0.5\c1_shakescalex\1\c1_shakescaley\2\c1_shakescalez\3\c1_min_angle\-45\c1_max_angle\45)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = phys_constraints::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("test_constraints", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* pc = reinterpret_cast<XAssetInfo<PhysConstraints>*>(result.GetAssetInfo())->Asset();

        REQUIRE(pc->name == "test_constraints"s);
        REQUIRE(pc->count == 1u);
        REQUIRE(pc->data[0].type == CONSTRAINT_HINGE);
        REQUIRE(pc->data[0].offset.x == Approx(10.0f));
        REQUIRE(pc->data[0].offset.y == Approx(-5.0f));
        REQUIRE(pc->data[0].offset.z == Approx(2.0f));
        REQUIRE(pc->data[0].timeout == 5000);
        REQUIRE(pc->data[0].min_health == 0);
        REQUIRE(pc->data[0].max_health == 100);
        REQUIRE(pc->data[0].damp == Approx(0.8f));
        REQUIRE(pc->data[0].power == Approx(1500.0f));
        REQUIRE(pc->data[0].spin_scale == Approx(0.5f));
        REQUIRE(pc->data[0].scale.x == Approx(1.0f));
        REQUIRE(pc->data[0].scale.y == Approx(2.0f));
        REQUIRE(pc->data[0].scale.z == Approx(3.0f));
        REQUIRE(pc->data[0].minAngle == Approx(-45.0f));
        REQUIRE(pc->data[0].maxAngle == Approx(45.0f));

        // Post-processing resets bone names regardless of what was in the file
        REQUIRE(std::string(pc->data[0].target_bone1) == ""s);
        REQUIRE(std::string(pc->data[0].target_bone2) == ""s);

        // Post-processing initializes script string fields
        const auto emptyStr = zone.m_script_strings.AddOrGetScriptString("");
        REQUIRE(pc->data[0].targetname == emptyStr);
        REQUIRE(pc->data[0].target_ent1 == emptyStr);
        REQUIRE(pc->data[0].target_ent2 == emptyStr);
        REQUIRE(pc->data[0].attach_point_type1 == ATTACH_POINT_BONE);
        REQUIRE(pc->data[0].attach_point_type2 == ATTACH_POINT_BONE);
    }

    TEST_CASE("RawLoaderPhysConstraints(T6): Counts active constraints correctly", "[t6][physconstraints][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = phys_constraints::CreateRawLoaderT6(memory, searchPath, zone);

        SECTION("zero constraints when no type set")
        {
            searchPath.AddFileData("physconstraints/test_constraints", R"(PHYSCONSTRAINTS\c1_offsetX\5)");
            auto result = loader->CreateAsset("test_constraints", context);
            REQUIRE(result.HasBeenSuccessful());
            REQUIRE(reinterpret_cast<XAssetInfo<PhysConstraints>*>(result.GetAssetInfo())->Asset()->count == 0u);
        }

        SECTION("two constraints when c1 and c2 are set")
        {
            searchPath.AddFileData("physconstraints/test_constraints", R"(PHYSCONSTRAINTS\c1_type\point\c2_type\hinge)");
            auto result = loader->CreateAsset("test_constraints", context);
            REQUIRE(result.HasBeenSuccessful());
            const auto* pc = reinterpret_cast<XAssetInfo<PhysConstraints>*>(result.GetAssetInfo())->Asset();
            REQUIRE(pc->count == 2u);
            REQUIRE(pc->data[0].type == CONSTRAINT_POINT);
            REQUIRE(pc->data[1].type == CONSTRAINT_HINGE);
        }
    }

    TEST_CASE("RawLoaderPhysConstraints(T6): Parses yaw and pitch aliases", "[t6][physconstraints][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("physconstraints/test_constraints", R"(PHYSCONSTRAINTS\c1_type\joint\c1_yaw\1.5\c1_pitch\2.5)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = phys_constraints::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("test_constraints", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* pc = reinterpret_cast<XAssetInfo<PhysConstraints>*>(result.GetAssetInfo())->Asset();
        // yaw aliases scale.y, pitch aliases scale.x
        REQUIRE(pc->data[0].scale.y == Approx(1.5f));
        REQUIRE(pc->data[0].scale.x == Approx(2.5f));
    }
} // namespace
