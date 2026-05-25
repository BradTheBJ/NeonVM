#pragma once

#include <vector>
#include <string>
#include "VM.h"

namespace NeonVM
{
    enum class Tokens; // Forward declare

    struct Token
    {
        Tokens type;
        std::string content;
    };

    class VM::Lexer
    {
    public:
        Lexer() = default;
        ~Lexer() = default;
        std::vector<Token> Lex();

    private:
        enum class TokenTypes
        {
            // These tokens are somewhat based of x86 NASM/Intel style Assembely
            REG_TOKEN,
            MOV_TOKEN,
            FUNCTION_TOKEN, // To be implmented later
        };
    };
}