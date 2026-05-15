#include "ObjWriterT4.h"

#include "Game/T4/Material/MaterialJsonDumperT4.h"
#include "Game/T4/Techset/TechsetDumperT4.h"
#include "Game/T4/XModel/XModelDumperT4.h"
#include "Image/ImageDumperT4.h"
#include "Localize/LocalizeDumperT4.h"
#include "PhysPreset/PhysPresetInfoStringDumperT4.h"
#include "RawFile/RawFileDumperT4.h"
#include "StringTable/StringTableDumperT4.h"

using namespace T4;

void ObjWriter::RegisterAssetDumpers(AssetDumpingContext& context)
{
    RegisterAssetDumper(std::make_unique<phys_preset::InfoStringDumperT4>());
    // REGISTER_DUMPER(AssetDumperPhysConstraints, m_phys_constraints)
    // REGISTER_DUMPER(AssetDumperDestructibleDef, m_destructible_def)
    // REGISTER_DUMPER(AssetDumperXAnimParts, m_xanim_parts)
    RegisterAssetDumper(std::make_unique<xmodel::DumperT4>());
    RegisterAssetDumper(std::make_unique<material::JsonDumperT4>());
    RegisterAssetDumper(std::make_unique<techset::DumperT4>(
#ifdef TECHSET_DEBUG
        true
#else
        false
#endif
        ));
    RegisterAssetDumper(std::make_unique<image::DumperT4>());
    // REGISTER_DUMPER(AssetDumperSound, m_sound)
    // REGISTER_DUMPER(AssetDumperLoadedSound, m_loaded_sound)
    // REGISTER_DUMPER(AssetDumperClipMap, m_clip_map)
    // REGISTER_DUMPER(AssetDumperComWorld, m_com_world)
    // REGISTER_DUMPER(AssetDumperGameWorldSp, m_game_world_sp)
    // REGISTER_DUMPER(AssetDumperGameWorldMp, m_game_world_mp)
    // REGISTER_DUMPER(AssetDumperMapEnts, m_map_ents)
    // REGISTER_DUMPER(AssetDumperGfxWorld, m_gfx_world)
    // REGISTER_DUMPER(AssetDumperGfxLightDef, m_gfx_light_def)
    // REGISTER_DUMPER(AssetDumperFont, m_font)
    // REGISTER_DUMPER(AssetDumperMenuList, m_menu_list)
    // REGISTER_DUMPER(AssetDumperMenuDef, m_menu_def)
    RegisterAssetDumper(std::make_unique<localize::DumperT4>());
    // REGISTER_DUMPER(AssetDumperWeapon, m_weapon)
    // REGISTER_DUMPER(AssetDumperSndDriverGlobals, m_snd_driver_globals)
    // REGISTER_DUMPER(AssetDumperFxEffectDef, m_fx)
    // REGISTER_DUMPER(AssetDumperFxImpactTable, m_fx_impact_table)
    RegisterAssetDumper(std::make_unique<raw_file::DumperT4>());
    RegisterAssetDumper(std::make_unique<string_table::DumperT4>());
    // REGISTER_DUMPER(AssetDumperPackIndex, m_pack_index)
}
