#pragma once
#pragma once

#include <string>

namespace kvdb {

enum class CommandType {
  Get,
  Put,
  Del,
  Unknown
};

struct Command {
  CommandType type = CommandType::Unknown;
  std::string key;
  std::string value;  // Only used for Put command
};

struct ParseResult {
  bool ok = false;
  std::string error;
  Command command;
};

}  // namespace kvdb
