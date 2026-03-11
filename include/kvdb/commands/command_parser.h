#pragma once

#include <string> 
#include <string_view>
#include <vector>

#include "kvdb/commands/command.h"

namespace kvdb {

class CommandParser {
public:
  ParseResult Parse(std::string_view input) const;

private:
  static std::vector<std::string_view> Tokenize(std::string_view input, std::string* error);
  static CommandType ParseType(std::string_view command_str);
};

}  // namespace kvdb
