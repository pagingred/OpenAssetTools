#pragma once

#include "ObjWriter.h"

namespace T4
{
    class ObjWriter final : public IObjWriter
    {
    public:
        void RegisterAssetDumpers(AssetDumpingContext& context) override;
    };
} // namespace T4
