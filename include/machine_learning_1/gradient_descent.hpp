#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <vector>

namespace LinearRegression {
    // Function declaration for standard gradient descent
    std::vector<double> computeGradientDescent(
        const std::vector<std::vector<double>>& X, 
        const std::vector<double>& y, 
        std::vector<double> weights, 
        double learningRate, 
        int iterations
    );
}

#endif