#include <iostream>
#include <vector>
#include "../include/machine_learning_1/gradient_descent.hpp"
using namespace std;

int main() {
    // Dataset: y = 2+ 3x1 + 4x2
    
    vector<vector<double>> x = {
        {1.0, 1.0},
        {2.0, 1.0},
        {1.0, 2.0},
        {2.0, 2.0},
        {3.0, 1.0}
    };
    
    // Target values y
    vector<double> y = {9.0, 12.0, 13.0, 16.0, 15.0};

    // Initial starting weights [bias, x1 weight, x2 weight]
    vector<double> initial_weights = {0.0, 0.0, 0.0};

    // Hyperparameters
    double learningRate = 0.01;
    int iterations = 5000;

    cout << "Running Gradient Descent test..." << std::endl;

    // Run the function
    vector<double> final_weights = LinearRegression::computeGradientDescent(
        x, y, initial_weights, learningRate, iterations
    );

    // Print the results
    std::cout << "Final Weights:" << std::endl;
    for (size_t i = 0; i < final_weights.size(); ++i) {
        std::cout << "Weight " << i << ": " << final_weights[i] << std::endl;
    }

    return 0;
}