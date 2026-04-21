#include "WeaponInfoStringDumperIW3.h"

#include "Game/IW3/InfoString/InfoStringFromStructConverter.h"
#include "Game/IW3/ObjConstantsIW3.h"
#include "Game/IW3/Weapon/WeaponFields.h"
#include "Weapon/WeaponCommon.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <type_traits>

using namespace IW3;

namespace
{
    class InfoStringFromWeaponDefConverter final : public InfoStringFromStructConverter
    {
    protected:
        void FillFromExtensionField(const cspField_t& field) override
        {
            assert(false);
        }

    public:
        InfoStringFromWeaponDefConverter(const WeaponDefInfo* structure,
                                          const cspField_t* fields,
                                          const size_t fieldCount,
                                          std::function<std::string(scr_string_t)> scriptStringValueCallback)
            : InfoStringFromStructConverter(structure, fields, fieldCount, std::move(scriptStringValueCallback))
        {
        }
    };

    void CopyToWeaponDefInfo(const WeaponDef* weaponDef, WeaponDefInfo* weaponDefInfo)
    {
        weaponDefInfo->sndAliasPrefix = weaponDef->sndAliasPrefix;
        weaponDefInfo->mass = weaponDef->mass;

        if (weaponDef->friction >= 3.40282e+38)
        {
            weaponDefInfo->isFrictionInfinity = 1;
            weaponDefInfo->friction = 0;
        }
        else
        {
            weaponDefInfo->isFrictionInfinity = 0;
            weaponDefInfo->friction = weaponDef->friction;
        }

        weaponDefInfo->bounce = weaponDef->bounce;
        weaponDefInfo->bulletForceScale = weaponDef->bulletForceScale;
        weaponDefInfo->explosiveForceScale = weaponDef->explosiveForceScale;
        weaponDefInfo->piecesSpreadFraction = weaponDef->piecesSpreadFraction;
        weaponDefInfo->piecesUpwardVelocity = weaponDef->piecesUpwardVelocity;
        weaponDefInfo->tempDefaultToCylinder = weaponDef->tempDefaultToCylinder;
    }

    InfoString CreateInfoString(const XAssetInfo<WeaponDef>& asset)
    {
        auto* weaponDefInfo = new WeaponDefInfo;
        CopyToWeaponDefInfo(asset.Asset(), weaponDefInfo);

        InfoStringFromWeaponDefConverter converter(weaponDefInfo,
                                                    weapon_fields,
                                                    std::extent_v<decltype(weapon_fields)>,
                                                    [asset](const scr_string_t scrStr) -> std::string
                                                    {
                                                        assert(scrStr < asset.m_zone->m_script_strings.Count());
                                                        if (scrStr >= asset.m_zone->m_script_strings.Count())
                                                            return "";

                                                        return asset.m_zone->m_script_strings[scrStr];
                                                    });

        return converter.Convert();
    }
} // namespace

namespace weapon
{
    void InfoStringDumperIW3::DumpAsset(AssetDumpingContext& context, const XAssetInfo<AssetWeapon::Type>& asset)
    {
        // Only dump raw when no gdt available
        if (context.m_gdt)
        {
            const auto infoString = CreateInfoString(asset);
            GdtEntry gdtEntry(asset.m_name, ObjConstants::GDF_FILENAME_VEHICLE);
            infoString.ToGdtProperties(ObjConstants::INFO_STRING_PREFIX_WEAPON, gdtEntry);
            context.m_gdt->WriteEntry(gdtEntry);
        }
        else
        {
            const auto assetFile = context.OpenAssetFile(GetFileNameForAssetName(asset.m_name));

            if (!assetFile)
                return;

            auto& stream = *assetFile;
            const auto infoString = CreateInfoString(asset);
            const auto stringValue = infoString.ToString(ObjConstants::INFO_STRING_PREFIX_WEAPON);
            stream.write(stringValue.c_str(), stringValue.size());
        }
    }
} // namespace weapon