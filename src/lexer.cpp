#include "lexer.h"
#include <fstream>

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
}
