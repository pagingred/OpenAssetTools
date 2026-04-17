#pragma once

#include "Asset/IAssetCreator.h"
#include "Game/IW3/IW3.h"
#include "SearchPath/ISearchPath.h"
#include "Utils/MemoryManager.h"

#include <memory>

namespace menu_list
{
    std::unique_ptr<AssetCreator<IW3::AssetMenuList>> CreateLoaderIW3(MemoryManager& memory, ISearchPath& searchPath);
} // namespace string_table
