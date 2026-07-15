#pragma once

#include "Asset/AssetCreationContext.h"
#include "Asset/AssetRegistration.h"
#include "Asset/IAssetCreator.h"
#include "PhysConstraints/PhysConstraintsCommon.h"
#include "PhysConstraints/PhysConstraintsLexer.h"
#include "PhysConstraints/PhysConstraintsParser.h"
#include "SearchPath/ISearchPath.h"
#include "Utils/Logging/Log.h"
#include "Utils/MemoryManager.h"

#include <antlr4-runtime.h>
#include <string>

namespace phys_constraints
{
    class PhysConstraintsErrorListener final : public antlr4::BaseErrorListener
    {
    public:
        explicit PhysConstraintsErrorListener(const std::string& fileName)
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

    template<typename AssetT> class AbstractPhysConstraintsLoader : public AssetCreator<AssetT>
    {
    public:
        AbstractPhysConstraintsLoader(MemoryManager& memory, ISearchPath& searchPath)
            : m_memory(memory),
              m_search_path(searchPath)
        {
        }

        AssetCreationResult CreateAsset(const std::string& assetName, AssetCreationContext& context) final
        {
            const auto fileName = phys_constraints::GetFileNameForAssetName(assetName);
            const auto file = m_search_path.Open(fileName);
            if (!file.IsOpen())
                return AssetCreationResult::NoAction();

            antlr4::ANTLRInputStream input(*file.m_stream);
            PhysConstraintsLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            PhysConstraintsParser parser(&tokens);

            PhysConstraintsErrorListener errorListener(fileName);
            lexer.removeErrorListeners();
            lexer.addErrorListener(&errorListener);
            parser.removeErrorListeners();
            parser.addErrorListener(&errorListener);

            auto* tree = parser.physConstraints();

            if (errorListener.HasErrors())
            {
                con::error("Failed to parse phys constraints: \"{}\"", fileName);
                return AssetCreationResult::Failure();
            }

            auto* physConstraints = m_memory.Alloc<typename AssetT::Type>();
            AssetRegistration<AssetT> registration(assetName, physConstraints);

            if (!FillFromTree(*physConstraints, assetName, tree, context, registration))
            {
                con::error("Failed to convert phys constraints: \"{}\"", assetName);
                return AssetCreationResult::Failure();
            }

            return AssetCreationResult::Success(context.AddAsset(std::move(registration)));
        }

    protected:
        MemoryManager& m_memory;
        ISearchPath& m_search_path;

        virtual bool FillFromTree(typename AssetT::Type& physConstraints,
                                  const std::string& assetName,
                                  PhysConstraintsParser::PhysConstraintsContext* tree,
                                  AssetCreationContext& context,
                                  AssetRegistration<AssetT>& registration) = 0;
    };
} // namespace phys_constraints
