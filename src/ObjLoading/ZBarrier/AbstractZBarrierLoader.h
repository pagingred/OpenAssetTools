#pragma once

#include "Asset/AssetCreationContext.h"
#include "Asset/AssetRegistration.h"
#include "Asset/IAssetCreator.h"
#include "SearchPath/ISearchPath.h"
#include "Utils/Logging/Log.h"
#include "Utils/MemoryManager.h"
#include "ZBarrier/ZBarrierCommon.h"
#include "ZBarrier/ZBarrierLexer.h"
#include "ZBarrier/ZBarrierParser.h"

#include <antlr4-runtime.h>
#include <string>

namespace z_barrier
{
    class ZBarrierErrorListener final : public antlr4::BaseErrorListener
    {
    public:
        explicit ZBarrierErrorListener(const std::string& fileName)
            : m_file_name(fileName),
              m_has_errors(false)
        {
        }

        void syntaxError(antlr4::Recognizer*, antlr4::Token*, size_t line, size_t charPos, const std::string& msg, std::exception_ptr) override
        {
            con::error("{}:{}:{}: {}", m_file_name, line, charPos, msg);
            m_has_errors = true;
        }

        bool HasErrors() const
        {
            return m_has_errors;
        }

    private:
        std::string m_file_name;
        bool m_has_errors;
    };

    template<typename AssetT> class AbstractZBarrierLoader : public AssetCreator<AssetT>
    {
    public:
        AbstractZBarrierLoader(MemoryManager& memory, ISearchPath& searchPath)
            : m_memory(memory),
              m_search_path(searchPath)
        {
        }

        AssetCreationResult CreateAsset(const std::string& assetName, AssetCreationContext& context) final
        {
            const auto fileName = z_barrier::GetFileNameForAssetName(assetName);
            const auto file = m_search_path.Open(fileName);
            if (!file.IsOpen())
                return AssetCreationResult::NoAction();

            antlr4::ANTLRInputStream input(*file.m_stream);
            ZBarrierLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            ZBarrierParser parser(&tokens);

            ZBarrierErrorListener errorListener(fileName);
            lexer.removeErrorListeners();
            lexer.addErrorListener(&errorListener);
            parser.removeErrorListeners();
            parser.addErrorListener(&errorListener);

            auto* tree = parser.zBarrier();

            if (errorListener.HasErrors())
            {
                con::error("Failed to parse zbarrier: \"{}\"", fileName);
                return AssetCreationResult::Failure();
            }

            auto* zbarrier = m_memory.Alloc<typename AssetT::Type>();
            AssetRegistration<AssetT> registration(assetName, zbarrier);

            if (!FillFromTree(*zbarrier, assetName, tree, context, registration))
            {
                con::error("Failed to convert zbarrier: \"{}\"", assetName);
                return AssetCreationResult::Failure();
            }

            return AssetCreationResult::Success(context.AddAsset(std::move(registration)));
        }

    protected:
        MemoryManager& m_memory;
        ISearchPath& m_search_path;

        virtual bool FillFromTree(typename AssetT::Type& zbarrier,
                                   const std::string& assetName,
                                   ZBarrierParser::ZBarrierContext* tree,
                                   AssetCreationContext& context,
                                   AssetRegistration<AssetT>& registration) = 0;
    };
} // namespace z_barrier
