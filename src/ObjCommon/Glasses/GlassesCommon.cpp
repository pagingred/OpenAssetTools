#include "GlassesCommon.h"

#include <format>

namespace glasses
{
    std::string GetFileNameForAssetName(const std::string& assetName)
    {
        return std::format("glasses/{}", assetName);
    }
} // namespace glasses
