# Test results

The declared test is `tests/src/test_matrix.cpp`. A direct Windows `g++` build was attempted in a temporary directory using the original test source.

- `test_matrix`: **not compiled**. The implementation's `std::thread` call passes iterator arguments that are not invocable after conversion to rvalues, so the compiler rejects `multiply_partitioned` before the test can run.

This is recorded as a build failure, not a passing or failing test result.
