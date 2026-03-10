#pragma once

#include <string>
#include <vector>

namespace kvdb {

struct LogEntry {
  uint64_t index = 0;
  uint64_t term = 0;
  std::string command;
};

class RaftNode {
public:
  void Start();
  void Stop();
  void AppendEntries(const std::vector<LogEntry>& entries);
};

}  // namespace kvdb
