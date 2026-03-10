# KVDBProject (C++)

This repository is a scaffold for a distributed key-value database in C++.
It includes a starter CMake build, module boundaries, and placeholder interfaces.

## Layout
- `include/kvdb`: Public headers and module interfaces.
- `src`: Implementation sources.
- `tests`: Unit test stubs.
- `proto`: Protocol definitions (if using gRPC/Protobuf).
- `docs`: Design notes and RFCs.
- `tools`: Dev tooling helpers.
- `scripts`: Helper scripts.

## Build
```bash
cmake -S . -B build
cmake --build build
```

## Run
```bash
./build/kvdbproject
```

## Next Steps
- Define storage engine interface and initial in-memory implementation.
- Add Raft consensus module skeleton.
- Add RPC layer (gRPC, capnproto, or custom).
- Add tests.

