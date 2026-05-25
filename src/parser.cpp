#include "parser.h"

#include <iostream>

#include "VM.h"

namespace NeonVM
{
    Token VM::Parser::peekAhead(const int& index, const int& length)
    {
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
                    Token next = peekAhead(i, 1);

                    registers.insert(tokens[i].content, next);
                    break;
                }
            default:
                std::cerr << tokens[i].content << std::endl;
            }
        }
    }
}