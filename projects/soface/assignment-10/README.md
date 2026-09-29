# 270191U025-Software-Architecture-assignment-10

During this hand-in you will practice the following:

- analyze cyclomatic complexity of a program by hand
- Implement unit-tests that ensures full coverage based on this analysis

## Cyclomatic Complexity

Cyclomatic Complexity is a metric that can be used as a proxy for the complexity of a program.
Specifically, the metric measures the number of independent paths through a piece of software, i.e. how many different combinations of unique actions are made possible by the conditional statements of a program.

The concept of cyclomatic complexity is closely tied to the concept of a _program control graph_ which is a way to represent the structure of a computer program using directed graphs.
Each node of the graph represents a block of code that is executed sequentially, such as assignment statements or performing arithmetic.
Nodes corresponding to conditionals cause the graph to split into different paths.

Conditionals in C/C++ include:

- `if`, `if else`, and `else`
- `while`
- `do while`
- `switch`

A short summary of the different construct can be seen in the image below:

<img src="docs/cyclomatic_complexity_summary.png">

### Common Confusion Points

- if statements always have implicit else

  ```cpp
  if (sum > threshold)
  {
     sum = threshold
  }
  else
  {
     // do nothing
  }

  // is equivalent to
  if (sum > threshold)
  {
     sum = threshold
  }
  // else is omitted since it does nothing
  ```

- Edge from terminal to start node should _not_ be counted in the V(g) formula, this is introduced when counting cycles.
- Compound statements
- V(g) can be calculated for different portions of a program, like a single function. Traditionally, you would not count the complexity of other functions being called.

### References

The following material may be useful:

- <a href="file:///docs/mcabe.pdf">Original paper</a>.
- <a href="https://www.guru99.com/cyclomatic-complexity.html">Summary of rules</a>.
- <a href="https://www.froglogic.com/blog/tip-of-the-week/what-is-cyclomatic-complexity/">Additional examples </a>.

### Exercise

**For drawing I recommend using <a href="www.diagrams.net">drawio</a>.**

For **each** of the following functions defined in `snippets.hpp`:

- `min`
- `SortedVector::insert`
- `SortedVector::contains`
- `SortedVector::binary_search`
- `SortedVector::binary_insert`

Do the following:

- Draw the control graph
- Calculate V(g) using the formula
- Calculate V(g) by listing the number of independent cyclic paths
- Save image as `[name of function].png`,

**Ensure that each image clearly indicates the calculations**