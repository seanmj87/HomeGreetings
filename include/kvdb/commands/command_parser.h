#pragma once 

#include <string> 
#include <string_view>
#include <vector>

#include "kvdb/commands/command.h"

namespace kvdb {
    
    class CommandParser {
    public:
        ParseResult Parse(const std::string_view input) const;
    

    private:
        std::vector<std::string_view> Tokenize(const std::string_view input, std::string* error) const;

        static CommandType ParseType(const std::string_view command_str);
    };
}