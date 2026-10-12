#ifndef COEFFICIENT_OF_DETERMINATION_H
#define COEFFICIENT_OF_DETERMINATION_H

#include <vector>
#include <stdexcept>

inline double coefficient_of_determination(
    const std::vector<double>& actual,
    const std::vector<double>& predicted)
{
    if (actual.size() != predicted.size()) {
        throw std::invalid_argument("actual and predicted must be the same size");
    }

    const std::size_t n = actual.size();

    double mean_actual = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        mean_actual += actual[i];
    }
    mean_actual /= static_cast<double>(n);
    
    double ss_res = 0.0;  
    double ss_tot = 0.0;   
    for (std::size_t i = 0; i < n; ++i) {
        const double residual = actual[i] - predicted[i];
        ss_res += residual * residual;

        const double deviation = actual[i] - mean_actual;
        ss_tot += deviation * deviation;
    }

    return 1.0 - (ss_res / ss_tot);
}

#endif 