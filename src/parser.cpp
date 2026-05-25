#include "parser.h"

#include <iostream>

#include "VM.h"

namespace NeonVM
{
    Token VM::Parser::peekAhead(const int& index, const int& length)
    {
        if (index + length < 0 || index + length >= static_cast<int>(tokens.size()))
        {
            return Token(TokenTypes::VALUE_TOKEN, "");
        }
        return tokens[index + length];
    }

    void VM::Parser::parse()
    {
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            switch (tokens[i].type)
            {
            case TokenTypes::MOV_TOKEN:
                {
                    if (i + 2 < tokens.size())
                    {
                        Token reg = tokens[i + 1];
                        Token val = tokens[i + 2];

                        if (reg.type == TokenTypes::REG_TOKEN && val.type == TokenTypes::VALUE_TOKEN)
                        {
                            // Clean leading/trailing spaces from value
                            std::string valStr = val.content;
                            valStr.erase(0, valStr.find_first_not_of(" \t\r\n"));
                            valStr.erase(valStr.find_last_not_of(" \t\r\n") + 1);

                            vm.registers[reg.content] = valStr;
                        }
                        i += 2; // skip past register and value tokens
                    }
                    break;
                }
            default:
                std::cerr << tokens[i].content << std::endl;
            }
        }
    }
}