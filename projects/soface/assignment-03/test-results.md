# Test results

The four test targets declared in `tests/CMakeLists.txt` were compiled and run directly with `g++` in a temporary build directory on Windows, preserving the original test sources.

- `calc_test` (`tests/src/test_int_calculator.cpp`): **passed**, 400 assertions.
- `tcalc_test` (`tests/src/test_template_calculator.cpp`): **passed**, 4 assertions.
- `logger_test` (`tests/src/test_logger.cpp`): **failed**, 1 assertion. The test observed duplicated file contents instead of the expected single `abcdef` line.
- `calc_bad_test` (`tests/src/test_int_calculator_bad.cpp`): **failed as expected for the intentionally bad implementation**. This is a mutation-style negative test, not evidence that the normal calculator implementation fails.

The original CMake target definitions are in `tests/CMakeLists.txt`.
