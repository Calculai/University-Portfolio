[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/We0HA7u2)
# IPFCE Assignment 7

This repository includes automated testing for all programming exercises using GitHub Actions.

## How the Testing Works

When you push your code to GitHub, the automated tests will run and check:

1. **Taylor Sine Function**: Unit tests for the `taylor_sine` function implementation
2. **Stack Implementation**: Unit tests for stack functions using linked list

## Running Tests Locally

You can run the tests locally using the provided script:

```bash
./run_tests.sh
```

This will compile and test all your exercises on your local machine using Catch2 testing framework.

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

- `exercise1.c` - Taylor sine function implementation
- `exercise2.c` - Stack implementation using linked list
- `include/` - Header files for data structures and function declarations
- `tests/` - Test files
- `run_tests.sh` - Script to run all tests locally

## Requirements

- GCC compiler
