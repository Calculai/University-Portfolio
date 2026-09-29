# 270191U025-Software-Architecture-assignment-3

In this exercise we will see how the concepts learned until now can be used to help us design software that adheres to the SOLID principles.

<div style="text-align:center">
<img src="calculator_uml.svg">
</div>

As a example we use an Calculator which has the following two operations:

1. sum: calculates the sum of two numbers.
2. multiply: calculates the product of two numbers.

In addition to doing the calculations the calculator must also log these operations and their results, as illustrated in the figure above.
We will now see how this can be done without hard coding the logging functionality inside the calculator itself.

## Exercise 1. Dependency Injection

The `IntCalculatorBad.cpp` source file shows how logging can be added to the methods of the class.

```cpp
int IntCalculatorBad::sum(int a, int b)
{

    int res = a + b;

    std::cout << "taking the sum of: " << a << " and " << b << " which is " << res << std::endl;

    return res;
}
```
Note that in C++ it is common to use `std::cout` and the `left-shift` operator `<<` to print output, rather than `printf`.
Using `std::cout` is argueably less ergonomic than `printf` but it has the benefit that it can print different types without having to specify a format string manually, which will especially useful when we use templates later.

A nasty thing about this piece of code is that it is difficult to:

1. test the logging behavior
2. disable the logging
3. reuse the logging functionality

These are the symptoms of bad design. Ask yourself is this code violating any of the SOLID principles?

### Extract Logging Functionality

A fundamental technique in software development is `dependency injection`.
In this case we wish to inject the a pointer to a logger object into the Calculator.

Implement the IntCalculator class declared in `int_calculator.hpp`.
The constructor takes a pointer to a Logger class as a parameter.

This means that you sould implement the sum and multiply methods in `int_calculator.cpp`
In addition to doing the computations the function should write their results to the log in the format:

Addition:

```
taking the sum of: 'a' and 'b' which is 'a+b'
```

Multiplication:

```
taking the product of: 'a' and 'b' which is 'a*b'
```

Use the test defined in `test_int_calculator.cpp` to check that the class works as expected.

### Logging to files

Now we wish to change our logging mechanism such that it writes to a file instead of the console.
We wish to extend the program, but we do not wish to modify any of the existing code (Open-closed principle).

Implement the FileLogger class from `file_logger.cpp`
The class should work in a similar way to the PrintLogger, only that it instead writes to a file specified when the logger was constructed.
For inspiration on how to write to files see [cplusplus](https://www.cplusplus.com/doc/tutorial/files/).

To test the code we **could** replace the logger in the test case and compare the resulting log file with some very long string.

```cpp
TEST_CASE("IntCalculator")
{

    DummyLogger logger; // <- replace with FileLogger
    IntCalculator calc(&logger);
    ...
```

```
taking the sum of: 0 and 0 which is 0
taking the sum of: 0 and 1 which is 1
taking the sum of: 0 and 2 which is 2
...
taking the sum of: 10 and 10 which is 10
```

However, a test based on comparing string is prone to break as soon as the formatting changes the slightest.
Since the logging no longer depends on the calculator it can be tested seperately as shown in `test_logger.cpp`.

Run the test defined in `test_logger.cpp` to verify that the logging functionality is correct.

By delegating the responsibility of how to log to the concrete implementation of the logger we have implemented the `strategy` design pattern.
In this case we are selecting the behaviour when the calculator object is constructed, but it would also be possible to switch it out at runtime by implementing a method for setting the logger like `set_logger(Logger* log)`.

## Exercise 2. Template Classes

One weakness of the `IntCalculator` is that it can only do arithmetic with integers.

We now wish to implement the template class TemplateCalculator in `template_calculator.hpp`, which performs arithmetic on any type for which addition and multiplication is defined. Implement TemplateCalculator as a template class. 

It should work in a similar way to the IntCalculator class, only that its type can be specified at
compile time.

Rerun the test defined in `test_template_calculator.cpp` to verify the implmentation.
