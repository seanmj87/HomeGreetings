#pragma once

#include <string>
#include <optional>

namespace kvdb {

struct PutResult {
  bool success;
  std::string message;
};

struct DeleteResult {
  bool success;
  std::string message;
};

class KeyValueStore {
public:
  virtual ~KeyValueStore() = default;

  virtual std::optional<std::string> Get(const std::string& key) = 0;
  virtual PutResult Put(const std::string& key, const std::string& value) = 0;
  virtual DeleteResult Delete(const std::string& key) = 0;
};

}  // namespace kvdb
