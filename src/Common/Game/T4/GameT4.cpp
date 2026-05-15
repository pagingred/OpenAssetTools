#include "GameT4.h"

#include "T4.h"

#include <algorithm>

using namespace T4;

namespace
{
    constexpr const char* ASSET_TYPE_NAMES[]{
        "xmodelpieces", "physpreset",  "physconstraints", "destructibledef", "xanim",            "xmodel",      "material",
        "techniqueset", "image",       "sound",           "loadedsound",     "clipmap_unused",   "clipmap",     "comworld",
        "gameworldsp",  "gameworldmp", "mapents",         "gfxworld",        "lightdef",         "uimap",       "font",
        "menulist",     "menu",        "localize",        "weapon",          "snddriverglobals", "fx",          "fximpacttable", 
        "aitype",       "mptype",      "character",       "xmodelalias",     "rawfile",          "stringtable", "packindex",
    };
    static_assert(std::extent_v<decltype(ASSET_TYPE_NAMES)> == ASSET_TYPE_COUNT);

    constexpr const char* SUB_ASSET_TYPE_NAMES[]{
        "technique",
        "vertexdecl",
        "vertexshader",
        "pixelshader",
    };
    static_assert(std::extent_v<decltype(SUB_ASSET_TYPE_NAMES)> == SUB_ASSET_TYPE_COUNT);
} // namespace

namespace T4
{
    Game::Game()
        : AbstractGame(ASSET_TYPE_NAMES, std::extent_v<decltype(ASSET_TYPE_NAMES)>, SUB_ASSET_TYPE_NAMES, std::extent_v<decltype(SUB_ASSET_TYPE_NAMES)>)
    {
        AddAssetTypeNameAlias<AssetTechniqueSet>("techset");
        AddAssetTypeNameAlias<AssetLightDef>("gfxlightdef");
    }

    GameId Game::GetId() const
    {
        return GameId::T4;
    }

    const std::string& Game::GetFullName() const
    {
        static std::string fullName = "Call Of Duty: Black Ops";
        return fullName;
    }

    const std::string& Game::GetShortName() const
    {
        static std::string shortName = "T4";
        return shortName;
    }

    const std::vector<GameLanguagePrefix>& Game::GetLanguagePrefixes() const
    {
        static std::vector<GameLanguagePrefix> prefixes{
            {GameLanguage::LANGUAGE_ENGLISH,    "en_"},
            {GameLanguage::LANGUAGE_FRENCH,     "fr_"},
            {GameLanguage::LANGUAGE_FRENCH_CAN, "fc_"},
            {GameLanguage::LANGUAGE_GERMAN,     "ge_"},
            {GameLanguage::LANGUAGE_AUSTRIAN,   "ge_"},
            {GameLanguage::LANGUAGE_ITALIAN,    "it_"},
            {GameLanguage::LANGUAGE_SPANISH,    "sp_"},
            {GameLanguage::LANGUAGE_BRITISH,    "br_"},
            {GameLanguage::LANGUAGE_RUSSIAN,    "ru_"},
            {GameLanguage::LANGUAGE_POLISH,     "po_"},
            {GameLanguage::LANGUAGE_KOREAN,     "ko_"},
            {GameLanguage::LANGUAGE_JAPANESE,   "ja_"},
            {GameLanguage::LANGUAGE_CZECH,      "cz_"},
        };

        return prefixes;
    }
} // namespace T4
