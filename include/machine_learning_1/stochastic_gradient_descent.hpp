#ifndef STOCHASTIC_GRADIENT_DESCENT_HPP
#define STOCHASTIC_GRADIENT_DESCENT_HPP

#include<vector>

namespace LinearRegression{

    std:: vector<double> computeStochasticGradientDescent(
        const std:: vector< std::vector<double>> &x,
        const std:: vector<double> &y,
        std:: vector<double> weights,
        double learningRate,
        int iterations
    );

}
#endif