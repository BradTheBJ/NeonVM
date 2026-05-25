#pragma once

#include <string>
#include <unordered_map>
#include <any>

namespace NeonVM
{
    class VM
    {
        public:
            VM() = default;
            ~VM() = default;
        private:
            class Lexer;
            class Parser;
            std::unordered_map<std::string, std::any> registers;
    };
}
