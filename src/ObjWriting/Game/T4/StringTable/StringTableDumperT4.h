#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T4/T4.h"

namespace string_table
{
    class DumperT4 final : public AbstractAssetDumper<T4::AssetStringTable>
    {
    protected:
        void DumpAsset(AssetDumpingContext& context, const XAssetInfo<T4::AssetStringTable::Type>& asset) override;
    };
} // namespace string_table
