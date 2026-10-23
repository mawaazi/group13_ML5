# Week 3 & 4 Personal Report — BORIT DERRICK SIWA 25/U/07927/PS
**Function:** Coefficient of Determination (R²)
**Focus:** Templatization & Performance Optimization

## 1. Goal
Upgrade the R² function to support multiple floating-point types (float, double, long double) and optimize the algorithm from a two-pass to a single-pass O(n) loop.

## 2. Implementation Details
- **Templating:** Converted the function to `template <typename T>`.
- **Type Safety:** Used `static_assert(std::is_floating_point_v<T>)` so the compiler blocks integers (which don't make sense for R²) at compile time.
- **Performance:** Replaced the two-pass mean/residual loops with a single-pass algebraic derivation:
  - `SS_tot = Σy² - (Σy)²/n`
  - `SS_res = Σy² - 2Σ(y·ŷ) + Σŷ²`
  This cuts the execution time almost in half for large datasets.
- **Precision:** Used `long double` for intermediate accumulation to prevent floating-point drift on massive arrays.

## 3. Testing
Tested with `float`, `double`, and `long double` arrays to verify the template deduction works correctly. Edge cases (empty, constant values) still throw the correct `MLError`.