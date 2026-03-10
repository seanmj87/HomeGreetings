#include "kvdb/raft/raft_node.h"

namespace kvdb {

void RaftNode::Start() {
}

void RaftNode::Stop() {
}

void RaftNode::AppendEntries(const std::vector<LogEntry>& entries) {
  (void)entries;
}

}  // namespace kvdb
