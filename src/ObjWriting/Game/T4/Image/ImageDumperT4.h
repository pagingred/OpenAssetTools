#pragma once

#include "Dumping/AbstractAssetDumper.h"
#include "Game/T4/T4.h"
#include "Image/ImageWriter.h"

#include <memory>

namespace image
{
    class DumperT4 final : public AbstractAssetDumper<T4::AssetImage>
    {
    public:
        DumperT4();

    protected:
        void DumpAsset(AssetDumpingContext& context, const XAssetInfo<T4::AssetImage::Type>& asset) override;

    private:
        std::unique_ptr<ImageWriter> m_writer;
    };
} // namespace image
