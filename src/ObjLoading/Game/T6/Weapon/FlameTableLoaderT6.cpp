#include "FlameTableLoaderT6.h"

#include "FlameTable/AbstractFlameTableLoader.h"
#include "FlameTable/FlameTableParser.h"
#include "Game/T6/T6.h"
#include "Utils/Logging/Log.h"

#include <string>
#include <unordered_map>

using namespace T6;

namespace
{
    class FlameTableLoaderT6 final : public flame_table::AbstractFlameTableLoader<SubAssetFlameTable>
    {
    public:
        using AbstractFlameTableLoader::AbstractFlameTableLoader;

    protected:
        bool FillFromTree(FlameTable& ft,
                          const std::string& assetName,
                          FlameTableParser::FlameTableContext* tree,
                          AssetCreationContext& context,
                          AssetRegistration<SubAssetFlameTable>& registration) override
        {
            ft.name = m_memory.Dup(assetName.c_str());

            using FT = FlameTable;
            static const std::unordered_map<std::string, float FT::*> floatFields{
                {"flameVar_streamChunkGravityStart",           &FT::flameVar_streamChunkGravityStart          },
                {"flameVar_streamChunkGravityEnd",             &FT::flameVar_streamChunkGravityEnd            },
                {"flameVar_streamChunkMaxSize",                &FT::flameVar_streamChunkMaxSize               },
                {"flameVar_streamChunkStartSize",              &FT::flameVar_streamChunkStartSize             },
                {"flameVar_streamChunkEndSize",                &FT::flameVar_streamChunkEndSize               },
                {"flameVar_streamChunkStartSizeRand",          &FT::flameVar_streamChunkStartSizeRand         },
                {"flameVar_streamChunkEndSizeRand",            &FT::flameVar_streamChunkEndSizeRand           },
                {"flameVar_streamChunkDistScalar",             &FT::flameVar_streamChunkDistScalar            },
                {"flameVar_streamChunkDistSwayScale",          &FT::flameVar_streamChunkDistSwayScale         },
                {"flameVar_streamChunkDistSwayVelMax",         &FT::flameVar_streamChunkDistSwayVelMax        },
                {"flameVar_streamChunkSpeed",                  &FT::flameVar_streamChunkSpeed                 },
                {"flameVar_streamChunkDecel",                  &FT::flameVar_streamChunkDecel                 },
                {"flameVar_streamChunkVelocityAddScale",       &FT::flameVar_streamChunkVelocityAddScale      },
                {"flameVar_streamChunkDuration",               &FT::flameVar_streamChunkDuration              },
                {"flameVar_streamChunkDurationScaleMaxVel",    &FT::flameVar_streamChunkDurationScaleMaxVel   },
                {"flameVar_streamChunkDurationVelScalar",      &FT::flameVar_streamChunkDurationVelScalar     },
                {"flameVar_streamChunkSizeSpeedScale",         &FT::flameVar_streamChunkSizeSpeedScale        },
                {"flameVar_streamChunkSizeAgeScale",           &FT::flameVar_streamChunkSizeAgeScale          },
                {"flameVar_streamChunkSpawnFireIntervalStart", &FT::flameVar_streamChunkSpawnFireIntervalStart},
                {"flameVar_streamChunkSpawnFireIntervalEnd",   &FT::flameVar_streamChunkSpawnFireIntervalEnd  },
                {"flameVar_streamChunkSpawnFireMinLifeFrac",   &FT::flameVar_streamChunkSpawnFireMinLifeFrac  },
                {"flameVar_streamChunkSpawnFireMaxLifeFrac",   &FT::flameVar_streamChunkSpawnFireMaxLifeFrac  },
                {"flameVar_streamChunkFireMinLifeFrac",        &FT::flameVar_streamChunkFireMinLifeFrac       },
                {"flameVar_streamChunkFireMinLifeFracStart",   &FT::flameVar_streamChunkFireMinLifeFracStart  },
                {"flameVar_streamChunkFireMinLifeFracEnd",     &FT::flameVar_streamChunkFireMinLifeFracEnd    },
                {"flameVar_streamChunkDripsMinLifeFrac",       &FT::flameVar_streamChunkDripsMinLifeFrac      },
                {"flameVar_streamChunkDripsMinLifeFracStart",  &FT::flameVar_streamChunkDripsMinLifeFracStart },
                {"flameVar_streamChunkDripsMinLifeFracEnd",    &FT::flameVar_streamChunkDripsMinLifeFracEnd   },
                {"flameVar_streamChunkRotationRange",          &FT::flameVar_streamChunkRotationRange         },
                {"flameVar_streamSizeRandSinWave",             &FT::flameVar_streamSizeRandSinWave            },
                {"flameVar_streamSizeRandCosWave",             &FT::flameVar_streamSizeRandCosWave            },
                {"flameVar_streamDripsChunkInterval",          &FT::flameVar_streamDripsChunkInterval         },
                {"flameVar_streamDripsChunkMinFrac",           &FT::flameVar_streamDripsChunkMinFrac          },
                {"flameVar_streamDripsChunkRandFrac",          &FT::flameVar_streamDripsChunkRandFrac         },
                {"flameVar_streamSmokeChunkInterval",          &FT::flameVar_streamSmokeChunkInterval         },
                {"flameVar_streamSmokeChunkMinFrac",           &FT::flameVar_streamSmokeChunkMinFrac          },
                {"flameVar_streamSmokeChunkRandFrac",          &FT::flameVar_streamSmokeChunkRandFrac         },
                {"flameVar_streamChunkCullDistSizeFrac",       &FT::flameVar_streamChunkCullDistSizeFrac      },
                {"flameVar_streamChunkCullMinLife",            &FT::flameVar_streamChunkCullMinLife           },
                {"flameVar_streamChunkCullMaxLife",            &FT::flameVar_streamChunkCullMaxLife           },
                {"flameVar_streamFuelSizeStart",               &FT::flameVar_streamFuelSizeStart              },
                {"flameVar_streamFuelSizeEnd",                 &FT::flameVar_streamFuelSizeEnd                },
                {"flameVar_streamFuelLength",                  &FT::flameVar_streamFuelLength                 },
                {"flameVar_streamFuelNumSegments",             &FT::flameVar_streamFuelNumSegments            },
                {"flameVar_streamFuelAnimLoopTime",            &FT::flameVar_streamFuelAnimLoopTime           },
                {"flameVar_streamFlameSizeStart",              &FT::flameVar_streamFlameSizeStart             },
                {"flameVar_streamFlameSizeEnd",                &FT::flameVar_streamFlameSizeEnd               },
                {"flameVar_streamFlameLength",                 &FT::flameVar_streamFlameLength                },
                {"flameVar_streamFlameNumSegments",            &FT::flameVar_streamFlameNumSegments           },
                {"flameVar_streamFlameAnimLoopTime",           &FT::flameVar_streamFlameAnimLoopTime          },
                {"flameVar_streamPrimaryLightRadius",          &FT::flameVar_streamPrimaryLightRadius         },
                {"flameVar_streamPrimaryLightRadiusFlutter",   &FT::flameVar_streamPrimaryLightRadiusFlutter  },
                {"flameVar_streamPrimaryLightR",               &FT::flameVar_streamPrimaryLightR              },
                {"flameVar_streamPrimaryLightG",               &FT::flameVar_streamPrimaryLightG              },
                {"flameVar_streamPrimaryLightB",               &FT::flameVar_streamPrimaryLightB              },
                {"flameVar_streamPrimaryLightFlutterR",        &FT::flameVar_streamPrimaryLightFlutterR       },
                {"flameVar_streamPrimaryLightFlutterG",        &FT::flameVar_streamPrimaryLightFlutterG       },
                {"flameVar_streamPrimaryLightFlutterB",        &FT::flameVar_streamPrimaryLightFlutterB       },
                {"flameVar_fireLife",                          &FT::flameVar_fireLife                         },
                {"flameVar_fireLifeRand",                      &FT::flameVar_fireLifeRand                     },
                {"flameVar_fireSpeedScale",                    &FT::flameVar_fireSpeedScale                   },
                {"flameVar_fireSpeedScaleRand",                &FT::flameVar_fireSpeedScaleRand               },
                {"flameVar_fireVelocityAddZ",                  &FT::flameVar_fireVelocityAddZ                 },
                {"flameVar_fireVelocityAddZRand",              &FT::flameVar_fireVelocityAddZRand             },
                {"flameVar_fireVelocityAddSideways",           &FT::flameVar_fireVelocityAddSideways          },
                {"flameVar_fireGravity",                       &FT::flameVar_fireGravity                      },
                {"flameVar_fireGravityEnd",                    &FT::flameVar_fireGravityEnd                   },
                {"flameVar_fireMaxRotVel",                     &FT::flameVar_fireMaxRotVel                    },
                {"flameVar_fireFriction",                      &FT::flameVar_fireFriction                     },
                {"flameVar_fireEndSizeAdd",                    &FT::flameVar_fireEndSizeAdd                   },
                {"flameVar_fireStartSizeScale",                &FT::flameVar_fireStartSizeScale               },
                {"flameVar_fireEndSizeScale",                  &FT::flameVar_fireEndSizeScale                 },
                {"flameVar_fireBrightness",                    &FT::flameVar_fireBrightness                   },
                {"flameVar_dripsLife",                         &FT::flameVar_dripsLife                        },
                {"flameVar_dripsLifeRand",                     &FT::flameVar_dripsLifeRand                    },
                {"flameVar_dripsSpeedScale",                   &FT::flameVar_dripsSpeedScale                  },
                {"flameVar_dripsSpeedScaleRand",               &FT::flameVar_dripsSpeedScaleRand              },
                {"flameVar_dripsVelocityAddZ",                 &FT::flameVar_dripsVelocityAddZ                },
                {"flameVar_dripsVelocityAddZRand",             &FT::flameVar_dripsVelocityAddZRand            },
                {"flameVar_dripsVelocityAddSideways",          &FT::flameVar_dripsVelocityAddSideways         },
                {"flameVar_dripsGravity",                      &FT::flameVar_dripsGravity                     },
                {"flameVar_dripsGravityEnd",                   &FT::flameVar_dripsGravityEnd                  },
                {"flameVar_dripsMaxRotVel",                    &FT::flameVar_dripsMaxRotVel                   },
                {"flameVar_dripsFriction",                     &FT::flameVar_dripsFriction                    },
                {"flameVar_dripsEndSizeAdd",                   &FT::flameVar_dripsEndSizeAdd                  },
                {"flameVar_dripsStartSizeScale",               &FT::flameVar_dripsStartSizeScale              },
                {"flameVar_dripsEndSizeScale",                 &FT::flameVar_dripsEndSizeScale                },
                {"flameVar_dripsBrightness",                   &FT::flameVar_dripsBrightness                  },
                {"flameVar_smokeLife",                         &FT::flameVar_smokeLife                        },
                {"flameVar_smokeLifeRand",                     &FT::flameVar_smokeLifeRand                    },
                {"flameVar_smokeSpeedScale",                   &FT::flameVar_smokeSpeedScale                  },
                {"flameVar_smokeVelocityAddZ",                 &FT::flameVar_smokeVelocityAddZ                },
                {"flameVar_smokeGravity",                      &FT::flameVar_smokeGravity                     },
                {"flameVar_smokeGravityEnd",                   &FT::flameVar_smokeGravityEnd                  },
                {"flameVar_smokeMaxRotation",                  &FT::flameVar_smokeMaxRotation                 },
                {"flameVar_smokeMaxRotVel",                    &FT::flameVar_smokeMaxRotVel                   },
                {"flameVar_smokeFriction",                     &FT::flameVar_smokeFriction                    },
                {"flameVar_smokeEndSizeAdd",                   &FT::flameVar_smokeEndSizeAdd                  },
                {"flameVar_smokeStartSizeAdd",                 &FT::flameVar_smokeStartSizeAdd                },
                {"flameVar_smokeOriginSizeOfsZScale",          &FT::flameVar_smokeOriginSizeOfsZScale         },
                {"flameVar_smokeOriginOfsZ",                   &FT::flameVar_smokeOriginOfsZ                  },
                {"flameVar_smokeFadein",                       &FT::flameVar_smokeFadein                      },
                {"flameVar_smokeFadeout",                      &FT::flameVar_smokeFadeout                     },
                {"flameVar_smokeMaxAlpha",                     &FT::flameVar_smokeMaxAlpha                    },
                {"flameVar_smokeBrightness",                   &FT::flameVar_smokeBrightness                  },
                {"flameVar_smokeOriginOffset",                 &FT::flameVar_smokeOriginOffset                },
                {"flameVar_collisionSpeedScale",               &FT::flameVar_collisionSpeedScale              },
                {"flameVar_collisionVolumeScale",              &FT::flameVar_collisionVolumeScale             },
            };

            for (auto* pair : tree->pair())
            {
                const auto key = pair->key()->getText();
                const auto value = pair->value()->getText();

                if (const auto floatIt = floatFields.find(key); floatIt != floatFields.end())
                {
                    if (!value.empty())
                        ft.*(floatIt->second) = std::stof(value);
                }
                else if (key == "name")
                {
                    // name is always taken from the asset name, not the file
                }
                else if (key == "fire" || key == "smoke" || key == "heat" || key == "drips" || key == "streamFuel"
                         || key == "streamFuel2" || key == "streamFlame" || key == "streamFlame2")
                {
                    Material** mat = nullptr;
                    if (key == "fire")
                        mat = &ft.fire;
                    else if (key == "smoke")
                        mat = &ft.smoke;
                    else if (key == "heat")
                        mat = &ft.heat;
                    else if (key == "drips")
                        mat = &ft.drips;
                    else if (key == "streamFuel")
                        mat = &ft.streamFuel;
                    else if (key == "streamFuel2")
                        mat = &ft.streamFuel2;
                    else if (key == "streamFlame")
                        mat = &ft.streamFlame;
                    else
                        mat = &ft.streamFlame2;

                    if (value.empty())
                    {
                        *mat = nullptr;
                    }
                    else
                    {
                        auto* material = context.LoadDependency<AssetMaterial>(value);
                        if (material == nullptr)
                        {
                            con::error("Failed to load material \"{}\" for flame table \"{}\"", value, assetName);
                            return false;
                        }
                        registration.AddDependency(material);
                        *mat = material->Asset();
                    }
                }
                else if (key == "flameOffLoopSound" || key == "flameIgniteSound" || key == "flameOnLoopSound"
                         || key == "flameCooldownSound")
                {
                    const char** snd = nullptr;
                    if (key == "flameOffLoopSound")
                        snd = &ft.flameOffLoopSound;
                    else if (key == "flameIgniteSound")
                        snd = &ft.flameIgniteSound;
                    else if (key == "flameOnLoopSound")
                        snd = &ft.flameOnLoopSound;
                    else
                        snd = &ft.flameCooldownSound;

                    *snd = value.empty() ? nullptr : m_memory.Dup(value.c_str());
                }
            }

            return true;
        }
    };
} // namespace

namespace weapon
{
    std::unique_ptr<ISubAssetCreator> CreateFlameTableLoaderT6(MemoryManager& memory, ISearchPath& searchPath, Zone& zone)
    {
        return std::make_unique<FlameTableLoaderT6>(memory, searchPath);
    }
} // namespace weapon
