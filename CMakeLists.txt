cmake_minimum_required(VERSION 3.20)
project(KVDBProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(KVDB_BUILD_TESTS "Build unit tests" ON)

add_library(kvdbproject_lib
  src/kvdb.cpp
  src/storage/in_memory_store.cpp
  src/raft/raft_node.cpp
  src/replication/replicator.cpp
  src/net/rpc_server.cpp
)

target_include_directories(kvdbproject_lib PUBLIC include)

add_executable(kvdbproject src/main.cpp)

target_link_libraries(kvdbproject PRIVATE kvdbproject_lib)

if (KVDB_BUILD_TESTS)
  enable_testing()
  add_executable(kvdbproject_tests tests/kvdb_tests.cpp)
  target_link_libraries(kvdbproject_tests PRIVATE kvdbproject_lib)
  add_test(NAME kvdbproject_tests COMMAND kvdbproject_tests)
endif()
