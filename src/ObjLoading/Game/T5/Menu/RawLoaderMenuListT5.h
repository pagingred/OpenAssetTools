#pragma once

#include "Asset/IAssetCreator.h"
#include "Game/T5/T5.h"
#include "SearchPath/ISearchPath.h"
#include "Utils/MemoryManager.h"

#include <memory>

namespace menu
{
    std::unique_ptr<AssetCreator<T5::AssetMenuList>> CreateRawLoaderMenuListT5(MemoryManager& memory, ISearchPath& searchPath);
} // namespace menu
