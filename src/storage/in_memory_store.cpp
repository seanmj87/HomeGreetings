#include "kvdb/kvdb.h"
#include "kvdb/storage/in_memory_store.h"

#include <iostream>

namespace kvdb {

std::optional<std::string> InMemoryStore::Get(const std::string& key) {
  std::scoped_lock lock(mutex_);
  auto it = data_.find(key);
  if (it == data_.end()) {
    return std::nullopt;
  }
  return it->second;
}

PutResult InMemoryStore::Put(const std::string& key, const std::string& value) {
  std::scoped_lock lock(mutex_);
  data_[key] = value;
  return {true, "stored"};
}

DeleteResult InMemoryStore::Delete(const std::string& key) {
  std::scoped_lock lock(mutex_);
  auto erased = data_.erase(key);
  if (erased == 0) {
    return {false, "missing"};
  }
  return {true, "deleted"};
}

}  // namespace kvdb
