#include "RawLoaderPhysConstraintsT6.h"

#include "Game/T6/PhysConstraints/PhysConstraintsFields.h"
#include "Game/T6/T6.h"
#include "PhysConstraints/AbstractPhysConstraintsLoader.h"
#include "Utils/Logging/Log.h"

#include <cctype>
#include <string>
#include <string_view>

using namespace T6;

namespace
{
    void CalculatePhysConstraintsFields(PhysConstraints& physConstraints, Zone& zone, AssetRegistration<AssetPhysConstraints>& registration)
    {
        for (auto& constraint : physConstraints.data)
        {
            constraint.targetname = zone.m_script_strings.AddOrGetScriptString("");
            constraint.target_ent1 = zone.m_script_strings.AddOrGetScriptString("");
            constraint.target_ent2 = zone.m_script_strings.AddOrGetScriptString("");
            constraint.attach_point_type1 = ATTACH_POINT_BONE;
            constraint.attach_point_type2 = ATTACH_POINT_BONE;
            constraint.target_bone1 = "";
            constraint.target_bone2 = "";
        }

        bool foundEnd = false;
        for (auto i = 0u; i < std::extent_v<decltype(PhysConstraints::data)>; i++)
        {
            if (physConstraints.data[i].type == CONSTRAINT_NONE)
            {
                foundEnd = true;
                physConstraints.count = i;
                break;
            }
        }
        if (!foundEnd)
            physConstraints.count = std::extent_v<decltype(PhysConstraints::data)>;

        registration.AddScriptString(zone.m_script_strings.AddOrGetScriptString(""));
    }

    class RawLoaderPhysConstraints final : public phys_constraints::AbstractPhysConstraintsLoader<AssetPhysConstraints>
    {
    public:
        RawLoaderPhysConstraints(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
            : AbstractPhysConstraintsLoader(memory, searchPath),
              m_zone(zone)
        {
        }

    protected:
        bool FillFromTree(PhysConstraints& pc,
                          const std::string& assetName,
                          PhysConstraintsParser::PhysConstraintsContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<AssetPhysConstraints>& registration) override
        {
            pc.name = m_memory.Dup(assetName.c_str());

            for (auto* pair : tree->pair())
            {
                const auto key = pair->key()->getText();
                const auto value = pair->value()->getText();

                // All keys have the form c{N}_field where N is 1-4 (mapped to index 0-3)
                if (key.size() < 3 || key[0] != 'c' || !std::isdigit(static_cast<unsigned char>(key[1])) || key[2] != '_')
                    continue;

                const int idx = key[1] - '1';
                if (idx < 0 || idx >= 4)
                    continue;

                const auto field = std::string_view(key).substr(3);
                auto& c = pc.data[static_cast<size_t>(idx)];

                if (field == "type")
                {
                    bool found = false;
                    for (size_t i = 0; i < std::extent_v<decltype(s_constraintTypeNames)>; i++)
                    {
                        if (value == s_constraintTypeNames[i])
                        {
                            c.type = static_cast<ConstraintType>(i);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        con::error("Unknown constraint type \"{}\" for phys constraints \"{}\"", value, assetName);
                        return false;
                    }
                }
                else if (field == "bone1_name")
                    c.target_bone1 = m_memory.Dup(value.c_str());
                else if (field == "bone2_name")
                    c.target_bone2 = m_memory.Dup(value.c_str());
                else if (field == "offsetX")
                    c.offset.x = std::stof(value);
                else if (field == "offsetY")
                    c.offset.y = std::stof(value);
                else if (field == "offsetZ")
                    c.offset.z = std::stof(value);
                else if (field == "timeout")
                    c.timeout = std::stoi(value);
                else if (field == "min_health")
                    c.min_health = std::stoi(value);
                else if (field == "max_health")
                    c.max_health = std::stoi(value);
                else if (field == "damp")
                    c.damp = std::stof(value);
                else if (field == "power")
                    c.power = std::stof(value);
                else if (field == "spin_scale")
                    c.spin_scale = std::stof(value);
                else if (field == "shakescalex" || field == "pitch")
                    c.scale.x = std::stof(value);
                else if (field == "shakescaley" || field == "yaw")
                    c.scale.y = std::stof(value);
                else if (field == "shakescalez")
                    c.scale.z = std::stof(value);
                else if (field == "min_angle")
                    c.minAngle = std::stof(value);
                else if (field == "max_angle")
                    c.maxAngle = std::stof(value);
            }

            CalculatePhysConstraintsFields(pc, m_zone, registration);

            return true;
        }

    private:
        Zone& m_zone;
    };
} // namespace

namespace phys_constraints
{
    std::unique_ptr<AssetCreator<AssetPhysConstraints>> CreateRawLoaderT6(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
    {
        return std::make_unique<RawLoaderPhysConstraints>(memory, searchPath, zone);
    }
} // namespace phys_constraints
