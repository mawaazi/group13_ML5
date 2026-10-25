# Week 1 Personal Report — BORIT DERRICK SIWA
**Branch:** BORITDERRICKSIWA
**Function assigned:** Coefficient of Determination (R²)
**Date:** 7/10/2026

---

## 1. Assignment
Implement the Coefficient of Determination (R²) for the group 9 ML1 C++ library.

Formula used:
    R² = 1 - (SS_res / SS_tot)

Where:
- SS_res = Σ (y_i - ŷ_i)²   (residual sum of squares)
- SS_tot = Σ (y_i - ȳ)²     (total sum of squares)
- ȳ = mean of the actual values

Interpretation:
- R² = 1.0 → perfect predictions
- R² = 0.0 → predictions equal to the mean
- R² < 0.0 → predictions worse than the mean

---

## 2. What I did this week
- Cloned the group repo (`git clone`) and pulled the latest `main`.
- Created my working branch: `BORITDERRICKSIWA`.
- Implemented `coefficient_of_determination()` in
  `include/coefficient_of_determination.h` as an `inline` header-only function.
- Wrote the algorithm in three steps:
  1. Compute mean of actual values.
  2. Compute SS_res and SS_tot in a single loop.
  3. Return `1 - SS_res / SS_tot`.
- Added a basic size-mismatch guard (throws `std::invalid_argument`).
- Wrote a demo in `examples/test_r2.cpp` and compiled it with:
      g++ -std=c++23 examples/test_r2.cpp -o examples/test_r2
- Ran the demo successfully and got the expected R² value.

---

## 3. Key design decisions
- **Header-only / inline** so teammates can `#include` it with no extra build step.
- **`std::vector<double>`** for inputs — most natural for numerical data.
  (Templating planned for Week 3.)
- **Two-pass algorithm** for readability — optimize in Week 4.
- **Basic validation only** — full validation with a custom exception in Week 2.

---

## 4. Testing
Test data:
    actual    = {1.0, 2.0, 3.0, 4.0, 5.0}
    predicted = {1.1, 1.9, 3.2, 3.8, 5.1}

Command:
    g++ -std=c++23 examples/test_r2.cpp -o examples/test_r2
    .\examples\test_r2.exe

Output:
    R^2 = 0.978

---

## 5. Next week (Week 2)
- Add full input validation:
  - empty vectors
  - size mismatch (already partially handled)
  - SS_tot == 0 (constant actual values)
- Introduce a custom exception class `MLError` for the library.

---

## 6. Time spent
[Fill in, e.g., ~2 hours]

## 7. Blockers
None.