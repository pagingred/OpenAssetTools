#include "RawLoaderGlassesT6.h"

#include "Game/T6/T6.h"
#include "Glasses/AbstractGlassesLoader.h"

#include <string>

using namespace T6;

namespace
{
    class RawLoaderGlasses final : public glasses::AbstractGlassesLoader<AssetGlasses>
    {
    public:
        using AbstractGlassesLoader::AbstractGlassesLoader;

    protected:
        bool FillFromTree(Glasses& glasses, const std::string& assetName, GlassesParser::GlassesFileContext* tree) override
        {
            glasses.name = m_memory.Dup(assetName.c_str());

            for (auto* entry : tree->entry())
            {
                if (!entry->key())
                    continue;

                const auto key = entry->key()->getText();
                const auto* firstValue = entry->firstValue();
                const auto value = (firstValue && firstValue->INTEGER())
                                       ? static_cast<unsigned int>(std::stoul(firstValue->INTEGER()->getText()))
                                       : 0u;

                if (key == "common")
                    glasses.workMemorySize = value;
                else if (key == "smallAllocatorBlocks")
                    glasses.smallAllocatorBlocks = value;
                else if (key == "groups")
                    glasses.maxGroups = value;
                else if (key == "shards")
                    glasses.maxShards = value;
                else if (key == "physics")
                    glasses.maxPhysics = value;
                else if (key == "shardMemory")
                    glasses.shardMemorySize = value;
                else if (key == "freeCmd")
                    glasses.maxFreeCmd = value;
                else if (key == "slots")
                    glasses.numSlots = value;
                else if (key == "verts")
                    glasses.numVerts = value;
            }

            return true;
        }
    };
} // namespace

namespace glasses
{
    std::unique_ptr<AssetCreator<AssetGlasses>> CreateRawLoaderT6(MemoryManager& memory, ISearchPath& searchPath)
    {
        return std::make_unique<RawLoaderGlasses>(memory, searchPath);
    }
} // namespace glasses
