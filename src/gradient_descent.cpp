#include "../include/machine_learning_1/gradient_descent.hpp" 
#include<vector>
#include<stdexcept>

using namespace std;
namespace LinearRegression{
    vector<double> computeGradientDescent(
        const vector<vector<double>>&x, 
        const vector<double>&y,
    vector <double> weights,
    double learningrate,
    int iterations)
    {
        int m= x.size(); //Number of data samples
        if (m==0){
            return weights;
        }
        int n= weights.size(); //Number of weights

        for (int it= 0; it < iterations; ++it) {
            std::vector<double> predictions(m, 0.0);
            std::vector<double> gradients(n, 0.0);

            // Calculate predictions: y_pred = x * weights
            for (int i = 0; i < m; ++i) {
                double prediction = 0.0;
                for (int j = 0; j < n; ++j) {
                    prediction += x[i][j] * weights[j];
                }
                predictions[i] = prediction;
            }

            // Compute gradients based on the error (prediction - actual y)
            for (int j = 0; j < n; ++j) {
                double gradientSum = 0.0;
                for (int i = 0; i < m; ++i) {
                    double error = predictions[i] - y[i];
                    
                    double featureVal = (j == 0) ? 1.0 : x[i][j - 1]; 
                    gradientSum += error * featureVal;
                }
                gradients[j] = (2.0 / m) * gradientSum;
            }

            // Update weights: weights = weights - (learningRate * gradients)
            for (int j = 0; j < n; ++j) {
                weights[j] -= learningrate * gradients[j];
            }
        }

        return weights;
        
    }
}