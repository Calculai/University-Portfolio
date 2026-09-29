[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ysACTsNn)
# IPFCE Assignment 8

This repository includes automated testing for all programming exercises using GitHub Actions.

## How the Testing Works

When you push your code to GitHub, the automated tests will run and check:

1. **Exercise 2**: Implementation and testing
2. **Exercise 3**: Implementation and testing
3. **Exercise 4**: Implementation and testing

## Running Tests Locally

You can run the tests locally using the provided script:

```bash
./run_tests.sh
```

This will compile and test all your exercises on your local machine using the C compiler.

If a test fails, check the error message to understand what went wrong. Common issues:

- Compilation errors (syntax problems)
- Logic errors in your function implementation
- Missing `#include` statements or incorrect function signatures

## Tips for Students

1. Make sure your functions match the exact signatures specified in the exercise files
2. Test your functions thoroughly before submitting
3. Pay attention to edge cases and boundary conditions
4. Use proper memory management for dynamic data structures

## Assignment Structure

- `exercise2.c` - Exercise 2 implementation
- `exercise3.c` - Exercise 3 implementation
- `exercise4.c` - Exercise 4 implementation
- `include/` - Header files for data structures and function declarations
- `tests/` - Test files
- `run_tests.sh` - Script to run all tests locally

## Requirements

- GCC compiler
