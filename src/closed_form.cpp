#include "closed_form.hpp"

#include<stdexcept>
#include<cmath>

namespace closed_form{
    double sum_natural_numbers(int n){
        if (n < 0) {
            throw std::invalid_argument("n cannot be negative");
        }
        return static_cast<double>(n) * (n + 1) / 2.0;
    }

    double arithmetic_series_sum(int n, double a, double d){
        if (n < 0) {
            throw std::invalid_argument("n cannot be negative");
        }
        return (n) * (2 * a + (n - 1) * d) / 2.0;
    }

    double geometric_series_sum(int n, double a, double r){
        if (n < 0) {
            throw std::invalid_argument("n cannot be negative");
        }
        if (std::abs(r - 1.0) < 1e-12) { // Handle the case when r is approximately 1
            return n * a;
        }
        return a * (1 - std::pow(r, n)) / (1 - r);
    }
}