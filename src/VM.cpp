#include "VM.h"
#include "lexer.h"
#include "parser.h"
#include <iostream>

namespace NeonVM
{
    void VM::run(const std::filesystem::path& filePath)
    {
        Lexer lexer;
        std::vector<Token> tokens = lexer.Lex(filePath);
        Parser parser(tokens, *this);
        parser.parse();
    }

    void VM::printRegisters() const
    {
        std::cout << "--- Register State ---" << std::endl;
        if (registers.empty())
        {
            std::cout << "(No registers set)" << std::endl;
            return;
        }
        for (const auto& [reg, val] : registers)
        {
            if (val.type() == typeid(std::string))
            {
                std::cout << reg << ": " << std::any_cast<std::string>(val) << std::endl;
            }
            else
            {
                std::cout << reg << ": [unknown type]" << std::endl;
            }
        }
        std::cout << "----------------------" << std::endl;
    }
}