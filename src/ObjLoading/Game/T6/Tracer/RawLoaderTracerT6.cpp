#include "RawLoaderTracerT6.h"

#include "Game/T6/T6.h"
#include "Game/T6/Tracer/TracerFields.h"
#include "Tracer/AbstractTracerLoader.h"
#include "Utils/Logging/Log.h"

#include <string>

using namespace T6;

namespace
{
    class RawLoaderTracer final : public tracer::AbstractTracerLoader<AssetTracer>
    {
    public:
        using AbstractTracerLoader::AbstractTracerLoader;

    protected:
        bool FillFromTree(TracerDef& tracerDef,
                          const std::string& assetName,
                          TracerParser::TracerContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<AssetTracer>& registration) override
        {
            tracerDef.name = m_memory.Dup(assetName.c_str());

            for (auto* pair : tree->pair())
            {
                const auto key = pair->key()->getText();
                const auto value = pair->value()->getText();

                if (key == "type")
                {
                    bool found = false;
                    for (size_t i = 0; i < std::extent_v<decltype(tracerTypeNames)>; i++)
                    {
                        if (value == tracerTypeNames[i])
                        {
                            tracerDef.type = static_cast<tracerType_t>(i);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        con::error("Unknown tracer type \"{}\" for tracer \"{}\"", value, assetName);
                        return false;
                    }
                }
                else if (key == "material")
                {
                    if (!value.empty())
                    {
                        auto* mat = context.LoadDependency<AssetMaterial>(value);
                        if (mat == nullptr)
                        {
                            con::error("Failed to load material \"{}\" for tracer \"{}\"", value, assetName);
                            return false;
                        }
                        registration.AddDependency(mat);
                        tracerDef.material = mat->Asset();
                    }
                }
                else if (key == "drawInterval")
                    tracerDef.drawInterval = static_cast<unsigned int>(std::stoi(value));
                else if (key == "speed")
                    tracerDef.speed = std::stof(value);
                else if (key == "beamLength")
                    tracerDef.beamLength = std::stof(value);
                else if (key == "beamWidth")
                    tracerDef.beamWidth = std::stof(value);
                else if (key == "screwRadius")
                    tracerDef.screwRadius = std::stof(value);
                else if (key == "screwDist")
                    tracerDef.screwDist = std::stof(value);
                else if (key == "fadeTime")
                    tracerDef.fadeTime = std::stof(value);
                else if (key == "fadeScale")
                    tracerDef.fadeScale = std::stof(value);
                else if (key == "texRepeatRate")
                    tracerDef.texRepeatRate = std::stof(value);
                else if (key == "colorR0")
                    tracerDef.colors[0].r = std::stof(value);
                else if (key == "colorG0")
                    tracerDef.colors[0].g = std::stof(value);
                else if (key == "colorB0")
                    tracerDef.colors[0].b = std::stof(value);
                else if (key == "colorA0")
                    tracerDef.colors[0].a = std::stof(value);
                else if (key == "colorR1")
                    tracerDef.colors[1].r = std::stof(value);
                else if (key == "colorG1")
                    tracerDef.colors[1].g = std::stof(value);
                else if (key == "colorB1")
                    tracerDef.colors[1].b = std::stof(value);
                else if (key == "colorA1")
                    tracerDef.colors[1].a = std::stof(value);
                else if (key == "colorR2")
                    tracerDef.colors[2].r = std::stof(value);
                else if (key == "colorG2")
                    tracerDef.colors[2].g = std::stof(value);
                else if (key == "colorB2")
                    tracerDef.colors[2].b = std::stof(value);
                else if (key == "colorA2")
                    tracerDef.colors[2].a = std::stof(value);
                else if (key == "colorR3")
                    tracerDef.colors[3].r = std::stof(value);
                else if (key == "colorG3")
                    tracerDef.colors[3].g = std::stof(value);
                else if (key == "colorB3")
                    tracerDef.colors[3].b = std::stof(value);
                else if (key == "colorA3")
                    tracerDef.colors[3].a = std::stof(value);
                else if (key == "colorR4")
                    tracerDef.colors[4].r = std::stof(value);
                else if (key == "colorG4")
                    tracerDef.colors[4].g = std::stof(value);
                else if (key == "colorB4")
                    tracerDef.colors[4].b = std::stof(value);
                else if (key == "colorA4")
                    tracerDef.colors[4].a = std::stof(value);
            }

            return true;
        }
    };
} // namespace

namespace tracer
{
    std::unique_ptr<AssetCreator<AssetTracer>> CreateRawLoaderT6(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
    {
        return std::make_unique<RawLoaderTracer>(memory, searchPath);
    }
} // namespace tracer
