#pragma once

#include <unordered_map>
#include <mutex>
#include "kvdb/kvdb.h"

namespace kvdb {

class InMemoryStore final : public KeyValueStore {
public:
  std::optional<std::string> Get(const std::string& key) override;
  PutResult Put(const std::string& key, const std::string& value) override;
  DeleteResult Delete(const std::string& key) override;

private:
  std::unordered_map<std::string, std::string> data_;
  std::mutex mutex_;
};

}  // namespace kvdb
