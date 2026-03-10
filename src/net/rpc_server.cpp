#include "kvdb/net/rpc_server.h"

namespace kvdb {

bool RpcServer::Start(const std::string& address, int port) {
  (void)address;
  (void)port;
  return true;
}

void RpcServer::Stop() {
}

}  // namespace kvdb
