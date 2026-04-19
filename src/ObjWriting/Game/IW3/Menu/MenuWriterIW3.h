#pragma once

#include "Game/IW3/IW3.h"
#include "Menu/IMenuWriter.h"

#include <memory>
#include <string>

namespace menu
{
    class IWriterIW3 : public IWriter
    {
    public:
        virtual void WriteFunctionDef(const std::string& functionName, const IW3::statement_s& statement) = 0;
        virtual void WriteMenu(const IW3::menuDef_t& menu) = 0;
    };

    std::unique_ptr<IWriterIW3> CreateMenuWriterIW3(std::ostream& stream);
} // namespace menu
