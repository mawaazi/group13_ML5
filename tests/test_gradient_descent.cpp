#include <iostream>
#include <vector>
#include "../include/machine_learning_1/gradient_descent.hpp"
using namespace std;

int main() {
    // Create a tiny dummy dataset: y = 2 * x1
    // x has 3 rows, 1 feature column
    vector<vector<double>> x = {
        {1.0},
        {2.0},
        {3.0}
    };
    
    // Target values y
    vector<double> y = {2.0, 4.0, 6.0};

    // Initial starting weights [bias, weight_for_x1]
    vector<double> initial_weights = {0.0, 0.0};

    // Hyperparameters
    double learningRate = 0.01;
    int iterations = 1000;

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