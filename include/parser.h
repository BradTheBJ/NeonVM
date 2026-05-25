#pragma once

#include "VM.h"
#include "lexer.h"

namespace NeonVM
{
    class VM::Parser
    {
        public:
            Parser(std::vector<Token> tokens) : tokens(tokens) {}
            ~Parser() = default;
            void parse();
        private:
            std::vector<Token> tokens;
            Token peekAhead(const int& index, const int& length);
    };
}
