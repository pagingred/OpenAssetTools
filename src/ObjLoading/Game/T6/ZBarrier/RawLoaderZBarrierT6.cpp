#include "RawLoaderZBarrierT6.h"

#include "Game/T6/CommonT6.h"
#include "Game/T6/T6.h"
#include "Game/T6/ZBarrier/ZBarrierFields.h"
#include "ZBarrier/AbstractZBarrierLoader.h"

#include <string>
#include <unordered_map>

using namespace T6;

namespace
{
    class RawLoaderZBarrier final : public z_barrier::AbstractZBarrierLoader<AssetZBarrier>
    {
    public:
        RawLoaderZBarrier(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
            : AbstractZBarrierLoader(memory, searchPath),
              m_zone(zone)
        {
        }

    protected:
        bool FillFromTree(ZBarrierDef& zbarrier,
                          const std::string& assetName,
                          ZBarrierParser::ZBarrierContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<AssetZBarrier>& registration) override
        {
            zbarrier.name = m_memory.Dup(assetName.c_str());

            static const auto fieldLookup = []()
            {
                std::unordered_map<std::string, const cspField_t*> map;
                for (const auto& f : zbarrier_fields)
                    map[f.szName] = &f;
                return map;
            }();

            for (auto* pair : tree->pair())
            {
                const auto key = pair->key()->getText();
                const auto value = pair->value()->getText();

                const auto it = fieldLookup.find(key);
                if (it == fieldLookup.end())
                    continue;

                const auto& field = *it->second;
                auto* base = reinterpret_cast<uint8_t*>(&zbarrier) + field.iOffset;

                switch (static_cast<csParseFieldType_t>(field.iFieldType))
                {
                case CSPFT_FLOAT:
                    if (!value.empty())
                        *reinterpret_cast<float*>(base) = std::stof(value);
                    break;

                case CSPFT_UINT:
                    if (!value.empty())
                        *reinterpret_cast<unsigned int*>(base) = static_cast<unsigned int>(std::stoul(value));
                    break;

                case CSPFT_STRING:
                    *reinterpret_cast<const char**>(base) = m_memory.Dup(value.c_str());
                    break;

                case CSPFT_SCRIPT_STRING:
                {
                    const auto scrStr = m_zone.m_script_strings.AddOrGetScriptString(value);
                    registration.AddScriptString(scrStr);
                    *reinterpret_cast<scr_string_t*>(base) = scrStr;
                    break;
                }

                case CSPFT_SOUND_ALIAS_ID:
                    *reinterpret_cast<unsigned int*>(base) = Common::Com_HashString(value.c_str());
                    break;

                case CSPFT_XMODEL:
                {
                    if (value.empty())
                        break;
                    auto* xmodel = context.LoadDependency<AssetXModel>(value);
                    if (!xmodel)
                    {
                        con::error("Failed to load xmodel \"{}\" for zbarrier \"{}\"", value, assetName);
                        return false;
                    }
                    registration.AddDependency(xmodel);
                    *reinterpret_cast<XModel**>(base) = xmodel->Asset();
                    break;
                }

                case CSPFT_FX:
                {
                    if (value.empty())
                        break;
                    auto* fx = context.LoadDependency<AssetFx>(value);
                    if (!fx)
                    {
                        con::error("Failed to load fx \"{}\" for zbarrier \"{}\"", value, assetName);
                        return false;
                    }
                    registration.AddDependency(fx);
                    *reinterpret_cast<FxEffectDef**>(base) = fx->Asset();
                    break;
                }

                default:
                    break;
                }
            }

            zbarrier.numBoardsInBarrier = static_cast<int>(std::extent_v<decltype(ZBarrierDef::boards)>);
            for (auto i = 0u; i < std::extent_v<decltype(ZBarrierDef::boards)>; i++)
            {
                if (zbarrier.boards[i].pBoardModel == nullptr)
                {
                    zbarrier.numBoardsInBarrier = static_cast<int>(i);
                    break;
                }
            }

            return true;
        }

    private:
        Zone& m_zone;
    };
} // namespace

namespace z_barrier
{
    std::unique_ptr<AssetCreator<AssetZBarrier>> CreateRawLoaderT6(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
    {
        return std::make_unique<RawLoaderZBarrier>(memory, searchPath, zone);
    }
} // namespace z_barrier
