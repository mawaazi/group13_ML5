# group9_ML1
This is Group 9's project repository. We will be taking on Machine Learning 1 (Linear regression from scratch).


## (A) Closed-Form Equations Module

### Overview

This module implements three mathematical formulas for calculating the sum of a sequence of numbers. Instead of adding every term one by one, the formulas calculate the total directly.

### 1. Sum of Natural Numbers

This function calculates the sum of the first n natural numbers.

**Formula:**

S = n * (n + 1) / 2

**Function:** `sum_natural_numbers(int n)`

**Example:** For n = 10:

S = 10 * (10 + 1) / 2 = 55

### 2. Arithmetic Series Sum

An arithmetic series is a sequence in which the difference between consecutive terms is constant.

**Formula:**

S = n * (2 * a + (n - 1) * d) / 2

Where:
- n = number of terms
- a = first term
- d = common difference

**Function:** `arithmetic_series_sum(int n, double a, double d)`

**Example:** For n = 5, a = 5, and d = 3:

S = 5 * (2 * 5 + (5 - 1) * 3) / 2 = 55

The sequence is 5, 8, 11, 14, 17.

### 3. Geometric Series Sum

A geometric series is a sequence in which each term is obtained by multiplying the previous term by a constant ratio.

**Formula when r is not equal to 1:**

S = a * (1 - r^n) / (1 - r)

When r = 1, the formula becomes:

S = n * a

Where:
- n = number of terms
- a = first term
- r = common ratio

**Function:** `geometric_series_sum(int n, double a, double r)`

**Example:** For n = 4, a = 2, and r = 3:

S = 2 * (1 - 3^4) / (1 - 3) = 80

The sequence is 2, 6, 18, 54.

### Project Files

- `include/closed_form.hpp` — contains the function declarations.
- `src/closed_form.cpp` — contains the calculations.
- `examples/closed_form_example.cpp` — demonstrates how to use the functions.
- `tests/test_closed_form.cpp` — checks whether the functions produce the expected results.

### Input Validation

The functions reject negative values of n by throwing an `invalid_argument` exception.




