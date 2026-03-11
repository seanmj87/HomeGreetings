#include "kvdb/commands/command_parser.h"
#include "kvdb/storage/in_memory_store.h"

#include <cassert>

static void TestInMemoryStore() {
  kvdb::InMemoryStore store;
  auto result = store.Put("key", "value");
  assert(result.success);
  auto value = store.Get("key");
  assert(value && *value == "value");
  auto del = store.Delete("key");
  assert(del.success);
}

static void TestCommandParser() {
  kvdb::CommandParser parser;

  {
    auto result = parser.Parse("GET alpha");
    assert(result.ok);
    assert(result.command.type == kvdb::CommandType::Get);
    assert(result.command.key == "alpha");
  }

  {
    auto result = parser.Parse("PUT beta gamma");
    assert(result.ok);
    assert(result.command.type == kvdb::CommandType::Put);
    assert(result.command.key == "beta");
    assert(result.command.value == "gamma");
  }

  {
    auto result = parser.Parse("DEL delta");
    assert(result.ok);
    assert(result.command.type == kvdb::CommandType::Del);
    assert(result.command.key == "delta");
  }

  {
    auto result = parser.Parse("UNKNOWN key");
    assert(!result.ok);
  }

  {
    auto result = parser.Parse("PUT only_key");
    assert(!result.ok);
  }

  {
    auto result = parser.Parse("   ");
    assert(!result.ok);
  }
}

int main() {
  TestInMemoryStore();
  TestCommandParser();
  return 0;
}
