#include "RawLoaderVehicleT6.h"

#include "Game/T6/T6.h"
#include "Game/T6/Vehicle/VehicleFields.h"
#include "Utils/Logging/Log.h"
#include "Vehicle/AbstractVehicleLoader.h"
#include "Vehicle/VehicleParser.h"

#include <cassert>
#include <cstring>
#include <string>
#include <type_traits>
#include <unordered_map>

using namespace T6;

namespace
{
    const std::unordered_map<std::string, const cspField_t*>& GetVehicleFieldMap()
    {
        static std::unordered_map<std::string, const cspField_t*> fieldMap = []()
        {
            std::unordered_map<std::string, const cspField_t*> map;
            for (const auto& field : vehicle_fields)
                map.emplace(field.szName, &field);
            return map;
        }();
        return fieldMap;
    }

    bool ApplyField(VehicleDef& vehicleDef,
                    const cspField_t& field,
                    const std::string& value,
                    ZoneScriptStrings& zoneScriptStrings,
                    MemoryManager& memory,
                    AssetCreationContext& context,
                    AssetRegistration<AssetVehicle>& registration)
    {
        auto base = reinterpret_cast<uintptr_t>(&vehicleDef);

        switch (static_cast<csParseFieldType_t>(field.iFieldType))
        {
        case CSPFT_STRING:
            *reinterpret_cast<const char**>(base + field.iOffset) = memory.Dup(value.c_str());
            return true;

        case CSPFT_INT:
        {
            char* endPtr;
            *reinterpret_cast<int*>(base + field.iOffset) = static_cast<int>(strtol(value.c_str(), &endPtr, 0));
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as int for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case CSPFT_BOOL:
        {
            char* endPtr;
            *reinterpret_cast<bool*>(base + field.iOffset) = strtol(value.c_str(), &endPtr, 0) != 0;
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as bool for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case CSPFT_QBOOLEAN:
        {
            char* endPtr;
            *reinterpret_cast<int*>(base + field.iOffset) = strtol(value.c_str(), &endPtr, 0) != 0 ? 1 : 0;
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as qboolean for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case CSPFT_FLOAT:
        {
            char* endPtr;
            *reinterpret_cast<float*>(base + field.iOffset) = strtof(value.c_str(), &endPtr);
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as float for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case CSPFT_FX:
        {
            if (value.empty())
            {
                *reinterpret_cast<FxEffectDef**>(base + field.iOffset) = nullptr;
                return true;
            }
            auto* fx = context.LoadDependency<AssetFx>(value);
            if (!fx)
            {
                con::error("Failed to load fx asset \"{}\"", value);
                return false;
            }
            registration.AddDependency(fx);
            *reinterpret_cast<FxEffectDef**>(base + field.iOffset) = fx->Asset();
            return true;
        }

        case CSPFT_XMODEL:
        {
            if (value.empty())
            {
                *reinterpret_cast<XModel**>(base + field.iOffset) = nullptr;
                return true;
            }
            auto* xmodel = context.LoadDependency<AssetXModel>(value);
            if (!xmodel)
            {
                con::error("Failed to load xmodel asset \"{}\"", value);
                return false;
            }
            registration.AddDependency(xmodel);
            *reinterpret_cast<XModel**>(base + field.iOffset) = xmodel->Asset();
            return true;
        }

        case CSPFT_SCRIPT_STRING:
        {
            auto scrStr = zoneScriptStrings.AddOrGetScriptString(value);
            registration.AddScriptString(scrStr);
            *reinterpret_cast<scr_string_t*>(base + field.iOffset) = scrStr;
            return true;
        }

        default:
            break;
        }

        switch (static_cast<VehicleFieldType>(field.iFieldType))
        {
        case VFT_TYPE:
        {
            for (auto i = 0u; i < std::extent_v<decltype(s_vehicleClassNames)>; i++)
            {
                if (value == s_vehicleClassNames[i])
                {
                    *reinterpret_cast<int*>(base + field.iOffset) = static_cast<int>(i);
                    return true;
                }
            }
            con::error("Not a valid vehicle type: \"{}\"", value);
            return false;
        }

        case VFT_CAMERAMODE:
        {
            for (auto i = 0u; i < std::extent_v<decltype(s_vehicleCameraModes)>; i++)
            {
                if (value == s_vehicleCameraModes[i])
                {
                    *reinterpret_cast<int*>(base + field.iOffset) = static_cast<int>(i);
                    return true;
                }
            }
            con::error("Not a valid vehicle camera mode: \"{}\"", value);
            return false;
        }

        case VFT_TRACTION_TYPE:
        {
            for (auto i = 0u; i < std::extent_v<decltype(s_tractionTypeNames)>; i++)
            {
                if (value == s_tractionTypeNames[i])
                {
                    *reinterpret_cast<int*>(base + field.iOffset) = static_cast<int>(i);
                    return true;
                }
            }
            con::error("Not a valid traction type: \"{}\"", value);
            return false;
        }

        case VFT_MPH_TO_INCHES_PER_SECOND:
        {
            char* endPtr;
            *reinterpret_cast<float*>(base + field.iOffset) = strtof(value.c_str(), &endPtr) * 17.6f;
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as mph for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case VFT_POUNDS_TO_GAME_MASS:
        {
            char* endPtr;
            *reinterpret_cast<float*>(base + field.iOffset) = strtof(value.c_str(), &endPtr) * 0.001f;
            if (endPtr != &value[value.size()])
            {
                con::error("Failed to parse value \"{}\" as pounds for field \"{}\"", value, field.szName);
                return false;
            }
            return true;
        }

        case VFT_TEAM:
        {
            if (value == "axis")
            {
                *reinterpret_cast<int*>(base + field.iOffset) = TEAM_AXIS;
                return true;
            }
            if (value == "allies")
            {
                *reinterpret_cast<int*>(base + field.iOffset) = TEAM_ALLIES;
                return true;
            }
            if (value == "neutral")
            {
                *reinterpret_cast<int*>(base + field.iOffset) = TEAM_FOUR;
                return true;
            }
            *reinterpret_cast<int*>(base + field.iOffset) = TEAM_BAD;
            con::error("Failed to parse value \"{}\" as team", value);
            return false;
        }

        case VFT_KEY_BINDING:
        case VFT_GRAPH:
        case VFT_WIIUCONTROLOVERRIDE:
        default:
            assert(false);
            return false;
        }
    }

    class RawLoaderVehicle final : public vehicle::AbstractVehicleLoader<AssetVehicle>
    {
    public:
        RawLoaderVehicle(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
            : AbstractVehicleLoader(memory, searchPath),
              m_zone(zone)
        {
        }

    protected:
        bool FillFromTree(VehicleDef& vehicleDef,
                          const std::string& assetName,
                          VehicleParser::VehicleContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<AssetVehicle>& registration) override
        {
            vehicleDef.name = m_memory.Dup(assetName.c_str());

            const auto& fieldMap = GetVehicleFieldMap();

            for (auto* pair : tree->pair())
            {
                const auto key = pair->key()->getText();
                const auto rawValue = pair->value()->getText();
                const auto lastNonSpace = rawValue.find_last_not_of(" \t\r\n");
                const auto value = lastNonSpace == std::string::npos ? std::string() : rawValue.substr(0, lastNonSpace + 1);

                const auto it = fieldMap.find(key);
                if (it == fieldMap.end())
                    continue;

                if (!ApplyField(vehicleDef, *it->second, value, m_zone.m_script_strings, m_memory, context, registration))
                    return false;
            }

            return true;
        }

    private:
        Zone& m_zone;
    };
} // namespace

namespace vehicle
{
    std::unique_ptr<AssetCreator<AssetVehicle>> CreateRawLoaderT6(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
    {
        return std::make_unique<RawLoaderVehicle>(memory, searchPath, zone);
    }
} // namespace vehicle
