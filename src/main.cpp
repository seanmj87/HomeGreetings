#include "kvdb/storage/in_memory_store.h"
#include <iostream>
#include <string>
#include <optional>

int main() {
  kvdb::InMemoryStore store;
  store.Put("hello", "world");
  auto value = store.Get("hello");
  if (value) {
    std::cout << "value=" << *value << "\n";
  }
  return 0;
}
