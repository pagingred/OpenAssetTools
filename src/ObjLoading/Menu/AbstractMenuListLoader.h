#pragma once

#include "Asset/AssetCreationContext.h"
#include "Asset/AssetRegistration.h"
#include "Asset/IAssetCreator.h"
#include "Menu/MenuErrorListener.h"
#include "Menu/MenuLexer.h"
#include "Menu/MenuParser.h"
#include "SearchPath/ISearchPath.h"
#include "Utils/Logging/Log.h"
#include "Utils/MemoryManager.h"

#include <antlr4-runtime.h>
#include <string>

namespace menu
{
    template<typename AssetT> class AbstractMenuListLoader : public AssetCreator<AssetT>
    {
    public:
        AbstractMenuListLoader(MemoryManager& memory, ISearchPath& searchPath)
            : m_memory(memory),
              m_search_path(searchPath)
        {
        }

        AssetCreationResult CreateAsset(const std::string& assetName, AssetCreationContext& context) final
        {
            const auto file = m_search_path.Open(assetName);
            if (!file.IsOpen())
                return AssetCreationResult::NoAction();

            antlr4::ANTLRInputStream input(*file.m_stream);
            MenuLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            MenuParser parser(&tokens);

            MenuErrorListener errorListener(assetName);
            lexer.removeErrorListeners();
            lexer.addErrorListener(&errorListener);
            parser.removeErrorListeners();
            parser.addErrorListener(&errorListener);

            auto* tree = parser.menuFile();

            if (errorListener.HasErrors())
            {
                con::error("Failed to parse menu list file: \"{}\"", assetName);
                return AssetCreationResult::Failure();
            }

            auto* menuListAsset = m_memory.Alloc<typename AssetT::Type>();
            AssetRegistration<AssetT> registration(assetName, menuListAsset);

            if (!FillFromTree(*menuListAsset, assetName, tree, context, registration))
            {
                con::error("Failed to convert menu list: \"{}\"", assetName);
                return AssetCreationResult::Failure();
            }

            return AssetCreationResult::Success(context.AddAsset(std::move(registration)));
        }

    protected:
        MemoryManager& m_memory;
        ISearchPath& m_search_path;

        virtual bool FillFromTree(typename AssetT::Type& menuList,
                                  const std::string& assetName,
                                  MenuParser::MenuFileContext* tree,
                                  AssetCreationContext& context,
                                  AssetRegistration<AssetT>& registration) = 0;
    };
} // namespace menu
