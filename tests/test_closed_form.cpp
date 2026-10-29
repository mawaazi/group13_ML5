
#include "closed_form.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int main() {
    // Training data
    vector<vector<double>> X = {
        {1, 6},
        {2, 8},
        {3, 7},
        {4, 9}
    };

    vector<double> y = {40, 50, 60, 70};

    // Test 1: Calculate the coefficients
    vector<double> coefficients = fit(X, y);

    if (coefficients.size() != 3) {
        cout << "Test 1 failed: Wrong number of coefficients." << endl;
        return 1;
    }

    cout << "Test 1 passed: Coefficients calculated." << endl;

    // Test 2: Check the predicted score
    vector<double> new_student = {5, 8};
    double prediction = predict(coefficients, new_student);

    if (abs(prediction - 80.0) > 1e-6) {
        cout << "Test 2 failed: Prediction is incorrect." << endl;
        return 1;
    }

    cout << "Test 2 passed: Prediction is correct." << endl;

    // Test 3: Check invalid feature count
    try {
        vector<double> wrong_features = {5};
        predict(coefficients, wrong_features);

        cout << "Test 3 failed: Invalid features were accepted." << endl;
        return 1;
    } catch (const invalid_argument&) {
        cout << "Test 3 passed: Invalid features rejected." << endl;
    }

    cout << "All tests passed!" << endl;

    return 0;
}
