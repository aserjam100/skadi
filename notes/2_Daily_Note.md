# Skadi — Day 2 Notes

**Date:** 3 September 2026

## 1. What We Built and Why

### Dimension Validation

Skadi now checks whether two vectors have the same number of dimensions before comparing them.

Example:

    [1, 2, 3]
    [4, 5]

This is invalid because the vectors have different dimensions.

Skadi now throws:

    std::invalid_argument

instead of accidentally accessing invalid memory.

### Automated Tests

Created:

    tests/vector_math_test.cpp

Tests currently verify:

- Dot product produces the correct result.
- Euclidean distance produces the correct result.
- Mismatched dimensions produce an exception.

This means we no longer need to manually verify everything through `main.cpp`.

### Skadi Core Library

We reorganized CMake conceptually into:

    vector_math.cpp
          |
          v
      skadi_core
       /      \
      /        \
    skadi      tests

Both the application and tests now use the same Skadi library code.

---

## 2. C++ Concepts Used

### Undefined Behavior

`std::vector` access using:

    vector[i]

does not automatically check whether `i` is valid.

We accidentally accessed:

    b[2]

when `b` only contained two elements.

The program still ran, but this was undefined behavior.

Undefined behavior can:

- Appear to work.
- Produce incorrect values.
- Crash.
- Behave differently on another machine or compiler.

### Throwing Exceptions

We used:

    throw std::invalid_argument(
        "Vectors must have the same dimensions"
    );

This tells the caller that invalid input was provided.

### `try` and `catch`

We learned that exceptions can be handled:

    try {
        // operation
    }
    catch (...) {
        // handle error
    }

If an exception is not caught, the program can terminate.

### `e.what()`

Exceptions contain an error message.

It can be accessed using:

    e.what()

### `assert()`

Assertions allow us to automatically verify assumptions.

Example:

    assert(result == 32.0F);

If the condition is true:

    test continues

If the condition is false:

    test fails immediately

### Floating-Point Comparison

Floating-point calculations should generally not be compared directly using `==`.

Instead of:

    result == 5.19615

we used a tolerance:

    std::abs(result - 5.19615F) < 0.00001F

The allowed difference is commonly called an:

    epsilon
    or
    tolerance

### Testing Exceptions

We used a boolean to verify that an exception actually occurred:

    exception_thrown = false

If the expected exception occurs:

    exception_thrown = true

Then:

    assert(exception_thrown);

This lets us automatically test error handling.

### Libraries vs Executables

Skadi now has a reusable library:

    skadi_core

The main application and tests both link against it.

Conceptually:

    skadi_core
       |
       +---- skadi executable
       |
       +---- vector_math_test executable

CMake is supporting infrastructure.

The important thing to understand is how the pieces relate; we do not need to memorize CMake syntax.

---

## 3. Interesting Things Learned

### Vector Dimensions Must Match

A vector search engine cannot normally compare:

    384-dimensional vector

with:

    768-dimensional vector

using Euclidean distance or dot product.

This means a vector index will normally have a fixed dimension.

Skadi will eventually work roughly like:

    VectorIndex dimension = 768

Then:

    add 768-dimensional vector -> accepted
    add 384-dimensional vector -> rejected

### Bugs Can Look Like Correct Programs

One of today's most important observations was that our invalid memory access did NOT crash.

The program produced:

    14
    5.19615

This looked like a working program.

But it was actually reading memory it was not allowed to read.

A program running successfully does not necessarily mean the program is correct.

### Tests Protect Future Work

As Skadi becomes more complicated, we may change its internal implementation.

Tests allow us to check that existing behavior still works.

For example:

    change vector storage
            |
            v
    run existing tests
            |
       +----+----+
       |         |
      pass      fail
       |         |
    probably   investigate
     safe

This is called regression testing.

---

## Current Skadi Capabilities

Skadi can currently:

- Calculate dot products.
- Calculate Euclidean distances.
- Detect mismatched vector dimensions.
- Throw meaningful errors for invalid input.
- Automatically test its vector mathematics.
- Automatically test its dimension validation.

---

## Next — Day 3

Start building the first major Skadi abstraction:

    VectorIndex

We will learn:

- C++ classes.
- Constructors.
- `public` vs `private`.
- Object state.
- Fixed index dimensions.
- Adding vectors to an index.

The goal is to reach something conceptually like:

    skadi::VectorIndex index(3);

    index.add({1, 2, 3});
    index.add({4, 5, 6});

and reject:

    index.add({1, 2});

because the dimensions do not match the index.
