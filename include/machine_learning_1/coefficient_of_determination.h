#ifndef COEFFICIENT_OF_DETERMINATION_H
#define COEFFICIENT_OF_DETERMINATION_H

#include <vector>
#include <cmath>
#include <cstddef>
#include "ml_error.hpp"

namespace ml1 {

inline double coefficient_of_determination(
    const std::vector<double>& actual,
    const std::vector<double>& predicted)
{
    if (actual.empty() || predicted.empty()) {
        throw InvalidInputError("input vectors must not be empty");
    }

    if (actual.size() != predicted.size()) {
        throw InvalidInputError(
            "actual and predicted must have the same size "
            "(got " + std::to_string(actual.size()) +
            " vs " + std::to_string(predicted.size()) + ")");
    }

    const std::size_t n = actual.size();

    for (std::size_t i = 0; i < n; ++i) {
        if (!std::isfinite(actual[i]) || !std::isfinite(predicted[i])) {
            throw InvalidInputError(
                "input contains NaN or infinite value at index " +
                std::to_string(i));
        }
    }

    // ── mean of actual values ───────────────────────────
    double mean_actual = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        mean_actual += actual[i];
    }
    mean_actual /= static_cast<double>(n);

    // ── SS_res and SS_tot ───────────────────────────────
    double ss_res = 0.0;
    double ss_tot = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        const double residual  = actual[i] - predicted[i];
        ss_res += residual * residual;

        const double deviation = actual[i] - mean_actual;
        ss_tot += deviation * deviation;
    }

    // ── guard against divide-by-zero ────────────────────
    if (ss_tot == 0.0) {
        throw InvalidInputError(
            "all actual values are identical (SS_tot = 0); "
            "R² is undefined");
    }

    // ── Step 4: R² ──────────────────────────────────────────────
    return 1.0 - (ss_res / ss_tot);
}

} 

#endif 