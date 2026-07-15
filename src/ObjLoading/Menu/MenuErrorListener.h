#pragma once

#include "Utils/Logging/Log.h"

#include <antlr4-runtime.h>
#include <string>

namespace menu
{
    class MenuErrorListener final : public antlr4::BaseErrorListener
    {
    public:
        explicit MenuErrorListener(const std::string& fileName)
            : m_file_name(fileName),
              m_has_errors(false)
        {
        }

        void syntaxError(antlr4::Recognizer*, antlr4::Token*, size_t line, size_t charPos, const std::string& msg, std::exception_ptr) override
        {
            con::error("{}:{}:{}: {}", m_file_name, line, charPos, msg);
            m_has_errors = true;
        }

        [[nodiscard]] bool HasErrors() const
        {
            return m_has_errors;
        }

    private:
        std::string m_file_name;
        bool m_has_errors;
    };
} // namespace menu
