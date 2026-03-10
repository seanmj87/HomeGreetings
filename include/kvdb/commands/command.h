#pragma once
#include <string>

enum class CommandType {
    Get, 
    Put,
    Del,
    Unknown
};

struct Command {
    CommandType type;
    std::string key;
    std::string value; // Only used for Put command
};

struct ParseResult {
    bool ok; 
    std::string error; 
    Command command;
};
