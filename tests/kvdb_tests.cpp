#include "kvdb/storage/in_memory_store.h"
#include <cassert>

int main() {
  kvdb::InMemoryStore store;
  auto result = store.Put("key", "value");
  assert(result.success);
  auto value = store.Get("key");
  assert(value && *value == "value");
  auto del = store.Delete("key");
  assert(del.success);
  return 0;
}
