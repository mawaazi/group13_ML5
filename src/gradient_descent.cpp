#include "../include/machine_learning_1/gradient_descent.hpp" 
#include<vector>
#include<stdexcept>

using namespace std;
namespace LinearRegression{
    vector<double> computeGradientDescent(
        const vector<vector<double>>&x, 
        const vector<double>&y,
    vector <double> weights,
    double learningrate, int iterations)

    {
        const size_t m = x.size();
        if (m==0){
            return weights;
        }
        const size_t n = weights.size();
        if (y.size() !=m){
            throw std:: invalid_argument("x and y must contain the same number of samples.");
        }
        if (n==0) return weights;
        //weights[0] is the bias, weights[1],[2],.. are feature weights

        for (size_t i=0; i<m; i++) {
            if (x[i].size()+1 != n){
                throw std:: invalid_argument("The number of weights must equal the number of features plus 1 bias.");
            }
            }

            for (int it; it<iterations; ++it){
                vector<double> gradients (n,0.0);

                for(size_t i=0; i<m; ++i){
                    double prediction = weights[0]; //bias
                    for(size_t j=0; j<x[i].size(); ++j){
                        prediction += x[i][j] * weights[j+1];
                    }
                    const double error = prediction - y[i];
                    gradients[0] += error; //gradient for bias

                    for(size_t j=0; j<x[i].size(); ++j){
                        gradients[j+1] += error * x[i][j];
                    }
                }

                for(size_t j=0; j<n; ++j){
                    gradients[j] *= (2.0/ static_cast<double>(m));
                    weights[j]-= learningrate * gradients[j];
                }
            }

            return weights;
        }
    }