#pragma once

#include <string>

namespace kvdb {

class RpcServer {
public:
  bool Start(const std::string& address, int port);
  void Stop();
};

}  // namespace kvdb
