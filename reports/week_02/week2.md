# Week 2 Personal Report — BORIT DERRICK SIWA
**Function:** Coefficient of Determination (R²)
**Branch:** week2-boritderricksiwa
**Date:** 12/10/2026

---

## 1. Goal for this week
Harden the R² function with full input validation and introduce a
shared library-wide exception type for the ML1 C++ library.

## 2. What I did
- Created `include/machine_learning_1/ml_error.hpp` defining:
  - `ml1::MLError` — base library exception (derived from std::runtime_error)
  - `ml1::InvalidInputError` — specific to invalid input data
- Rewrote `coefficient_of_determination.h` with:
  - Namespace `ml1::` to match the team's structure.
  - Empty-vector check.
  - Size-mismatch check (improved message showing both sizes).
  - NaN / infinite-value check with index reporting.
  - SS_tot == 0 guard (all actual values identical → R² undefined).
- Rewrote `examples/test_r2.cpp` to exercise every new error path
  and report errors via `catch (const ml1::MLError&)`.

## 3. Key decisions
- **Custom exception (`MLError`)** instead of `std::invalid_argument`
  so users can catch `ml1::MLError` to know the error came from our library.
- **Two-level exception design:**
  - `MLError` — base type (catch-all for the library).
  - `InvalidInputError` — derived (catch-specific).
- **Namespace `ml1::`** to prevent collisions with user code and
  teammates' functions.
- Kept the function **inline** and header-only for easy integration.
- Guarded against division by zero (SS_tot == 0) instead of returning
  NaN silently — clearer for library users.

## 4. Testing
Compiled with:
    g++ -std=c++23 examples/test_r2.cpp -o examples/test_r2
Ran:
    .\examples\test_r2.exe

Output:
| Case                     | Result                          |
|--------------------------|---------------------------------|
| Perfect fit              | R² = 1                          |
| Good fit                 | R² = 0.989                      |
| Bad fit (reversed)       | R² = -3                         |
| Empty vectors            | MLError: input vectors empty    |
| Size mismatch            | MLError: sizes differ (2 vs 1)  |
| Constant actual values   | MLError: SS_tot = 0             |
| NaN in input             | MLError: NaN at index 1         |

All 7 cases passed. ✅

## 5. Next week (Week 3)
- Templatize the R² function so it works with `float`,
  `long double`, and possibly `int` inputs.
- Preserve identical behavior for `double`.

## 6. Time spent
[Fill in]

## 7. Blockers
None.