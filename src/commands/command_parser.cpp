#include "kvdb/commands/command_parser.h"

#include <cctype>

namespace kvdb {

ParseResult CommandParser::Parse(const std::string_view input) const {
  std::string error;
  auto tokens = Tokenize(input, &error);
  if (!error.empty()) {
    return {false, error, {}};
  }

  if (tokens.empty()) {
    return {false, "Empty command", {}};
  }

  CommandType type = ParseType(tokens[0]);
  if (type == CommandType::Unknown) {
    return {false, "Unknown command type: " + std::string(tokens[0]), {}};
  }

  Command command{type, "", ""};

  if (type == CommandType::Get || type == CommandType::Del) {
    if (tokens.size() != 2) {
      return {false, "Invalid number of arguments for " + std::string(tokens[0]) + " command", {}};
    }
    command.key = std::string(tokens[1]);
  } else if (type == CommandType::Put) {
    if (tokens.size() != 3) {
      return {false, "Invalid number of arguments for Put command", {}};
    }
    command.key = std::string(tokens[1]);
    command.value = std::string(tokens[2]);
  }

  return {true, "", command};
}

std::vector<std::string_view> CommandParser::Tokenize(std::string_view input, std::string* error) {
  std::vector<std::string_view> tokens;
  size_t start = 0;
  while (start < input.size()) {
    // Skip leading whitespace
    while (start < input.size() &&
           std::isspace(static_cast<unsigned char>(input[start])) != 0) {
      ++start;
    }
    if (start >= input.size()) {
      break;
    }

    size_t end = start;
    while (end < input.size() &&
           std::isspace(static_cast<unsigned char>(input[end])) == 0) {
      ++end;
    }
    tokens.emplace_back(input.substr(start, end - start));
    start = end;
  }
  (void)error;
  return tokens;
}

CommandType CommandParser::ParseType(std::string_view command_str) {
  if (command_str == "GET") {
    return CommandType::Get;
  }
  if (command_str == "PUT") {
    return CommandType::Put;
  }
  if (command_str == "DEL") {
    return CommandType::Del;
  }
  return CommandType::Unknown;
}

}
