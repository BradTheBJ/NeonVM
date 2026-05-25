#pragma once

#include "VM.h"
#include "lexer.h"

namespace NeonVM
{
    class VM::Parser
    {
        public:
            Parser() = default;
            ~Parser() = default;
            void parse(std::vector<Token>);
        private:
            void peekAhead(const int& index);
    };
}
