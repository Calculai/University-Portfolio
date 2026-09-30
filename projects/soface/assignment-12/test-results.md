# Test results

The declared test is `tests/src/test_wargame.cpp`. A direct Windows `g++` build was attempted in a temporary directory using the original test source and implementation sources.

- `test_wargame`: **not compiled**. Required headers such as `unit.hpp` and `observer.hpp` are supplied by the `core` include directory, but the direct command could not resolve that directory. The repository's CMake structure adds `core` as a subdirectory, so this result is a build-environment limitation rather than a test result.
