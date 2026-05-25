#include "lexer.h"
#include <fstream>
#include <print>

namespace NeonVM
{
    std::string VM::Lexer::fileToString(const std::filesystem::path& filePath)
    {
        std::ifstream file;
        // Make sure ifstream throws an exception if it cant open a file
        file.exceptions(std::ios::failbit | std::ios::badbit);
        file.open(filePath.string());

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::vector<Token> VM::Lexer::Lex(const std::filesystem::path& filePath)
    {
        std::string fileString{fileToString(filePath)};
        std::string buffer{""};
        std::vector<Token> tokens;
        buffer.reserve(fileString.size());

        for (size_t i = 0; i < fileString.size(); i++)
        {
            char c = fileString[i];

            if (std::isspace(c))
            {
                buffer.clear();
                continue;
            }

            buffer += c;

            if (buffer == "mov")
            {
                tokens.push_back(Token(TokenTypes::MOV_TOKEN, buffer));
                buffer.clear();
            }
            else if (c == 'r' && buffer == "r")
            {
                std::string reg = "r";

                i++;

                while (i < fileString.size() && !std::isspace(fileString[i]))
                {
                    reg += fileString[i];
                    i++;
                }

                tokens.push_back(Token(TokenTypes::REG_TOKEN, reg));

                buffer.clear();

                while (i < fileString.size() && fileString[i] != '\n')
                {
                    buffer += fileString[i];
                    i++;
                }
                tokens.push_back(Token(TokenTypes::VALUE_TOKEN, buffer));
                buffer.clear();
            }
        }
        return tokens;
    }
}
