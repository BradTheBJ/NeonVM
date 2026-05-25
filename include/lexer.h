#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "VM.h"

namespace NeonVM
{
    enum class TokenTypes
    {
        // These tokens are somewhat based of x86 NASM/Intel style Assembely
        REG_TOKEN,
        MOV_TOKEN,
        VALUE_TOKEN,
        FUNCTION_TOKEN, // To be implmented later
    };

    struct Token
    {
        Token(TokenTypes type, std::string content) : type(type), content(content) {};
        TokenTypes type;
        std::string content;
    };

    class VM::Lexer
    {
    public:
        Lexer() = default;
        ~Lexer() = default;
        std::vector<Token> Lex(const std::filesystem::path& filePath);

    private:
        std::string fileToString(const std::filesystem::path& filePath);

    };
}