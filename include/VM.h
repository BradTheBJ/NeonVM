#pragma once

#include <string>
#include <unordered_map>
#include <any>
#include <filesystem>

namespace NeonVM
{
    class VM
    {
        public:
            VM() = default;
            ~VM() = default;
            void run(const std::filesystem::path& filePath);
            void printRegisters() const;
        private:
            class Lexer;
            class Parser;
            std::unordered_map<std::string, std::any> registers;
    };
}
