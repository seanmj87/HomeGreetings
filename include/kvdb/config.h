#pragma once

#include <cstdint>
#include <string>

namespace kvdb {

struct NodeConfig {
  std::string node_id;
  std::string bind_address;
  uint16_t port = 7000;
};

}  // namespace kvdb
