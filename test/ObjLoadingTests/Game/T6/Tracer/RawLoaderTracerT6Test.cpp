#include "Game/T6/Tracer/RawLoaderTracerT6.h"

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
    TEST_CASE("RawLoaderTracer(T6): Returns no action when file is missing", "[t6][tracer][assetloader]")
    {
        MockSearchPath searchPath;
        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = tracer::CreateRawLoaderT6(memory, searchPath, zone);
        REQUIRE_FALSE(loader->CreateAsset("default_tracer", context).HasBeenSuccessful());
    }

    TEST_CASE("RawLoaderTracer(T6): Can parse tracer", "[t6][tracer][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData(
            "tracer/default_tracer",
            R"(TRACER\type\Laser\material\\drawInterval\16\speed\700\beamLength\120\beamWidth\4\screwRadius\0.5\screwDist\1\fadeTime\0.3\fadeScale\2\texRepeatRate\0.5\colorR0\1\colorG0\0\colorB0\0\colorA0\1\colorR1\0.8\colorG1\0.5\colorB1\0.2\colorA1\0.9\colorR2\0\colorG2\0\colorB2\0\colorA2\0\colorR3\0\colorG3\0\colorB3\0\colorA3\0\colorR4\0\colorG4\0\colorB4\0\colorA4\0)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = tracer::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("default_tracer", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* td = reinterpret_cast<XAssetInfo<TracerDef>*>(result.GetAssetInfo())->Asset();

        REQUIRE(td->name == "default_tracer"s);
        REQUIRE(td->type == TRACERTYPE_LASER);
        REQUIRE(td->material == nullptr);
        REQUIRE(td->drawInterval == 16u);
        REQUIRE(td->speed == Approx(700.0f));
        REQUIRE(td->beamLength == Approx(120.0f));
        REQUIRE(td->beamWidth == Approx(4.0f));
        REQUIRE(td->screwRadius == Approx(0.5f));
        REQUIRE(td->screwDist == Approx(1.0f));
        REQUIRE(td->fadeTime == Approx(0.3f));
        REQUIRE(td->fadeScale == Approx(2.0f));
        REQUIRE(td->texRepeatRate == Approx(0.5f));
        REQUIRE(td->colors[0].r == Approx(1.0f));
        REQUIRE(td->colors[0].g == Approx(0.0f));
        REQUIRE(td->colors[0].b == Approx(0.0f));
        REQUIRE(td->colors[0].a == Approx(1.0f));
        REQUIRE(td->colors[1].r == Approx(0.8f));
        REQUIRE(td->colors[1].g == Approx(0.5f));
        REQUIRE(td->colors[1].b == Approx(0.2f));
        REQUIRE(td->colors[1].a == Approx(0.9f));
    }

    TEST_CASE("RawLoaderTracer(T6): Parses Smoke type", "[t6][tracer][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("tracer/smoke_tracer", R"(TRACER\type\Smoke\drawInterval\8)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = tracer::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("smoke_tracer", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* td = reinterpret_cast<XAssetInfo<TracerDef>*>(result.GetAssetInfo())->Asset();
        REQUIRE(td->type == TRACERTYPE_SMOKE);
        REQUIRE(td->drawInterval == 8u);
    }

    TEST_CASE("RawLoaderTracer(T6): Empty material value leaves material null", "[t6][tracer][assetloader]")
    {
        MockSearchPath searchPath;
        searchPath.AddFileData("tracer/null_mat", R"(TRACER\material\\speed\500)");

        Zone zone("MockZone", 0, GameId::T6, GamePlatform::PC);
        MemoryManager memory;
        AssetCreatorCollection creatorCollection(zone);
        IgnoredAssetLookup ignoredAssetLookup;
        AssetCreationContext context(zone, &creatorCollection, &ignoredAssetLookup);

        auto loader = tracer::CreateRawLoaderT6(memory, searchPath, zone);
        auto result = loader->CreateAsset("null_mat", context);
        REQUIRE(result.HasBeenSuccessful());

        const auto* td = reinterpret_cast<XAssetInfo<TracerDef>*>(result.GetAssetInfo())->Asset();
        REQUIRE(td->material == nullptr);
        REQUIRE(td->speed == Approx(500.0f));
    }
} // namespace
