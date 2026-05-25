#pragma once

#include "VM.h"
#include "lexer.h"

namespace NeonVM
{
    class VM::Parser
    {
        public:
            Parser(std::vector<Token> tokens, VM& vm) : tokens(tokens), vm(vm) {}
            ~Parser() = default;
            void parse();
        private:
            std::vector<Token> tokens;
            VM& vm;
            Token peekAhead(const int& index, const int& length);
    };
}
