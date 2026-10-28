
#include "closed_form.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Training data: hours studied and hours slept
    vector<vector<double>> X = {
        {1, 6},
        {2, 8},
        {3, 7},
        {4, 9}
    };

    // Actual exam scores
    vector<double> y = {40, 50, 60, 70};

    // Calculate the regression coefficients
    vector<double> coefficients = fit(X, y);

    cout << "Regression coefficients:" << endl;

    for (size_t i = 0; i < coefficients.size(); i++) {
        cout << "b" << i << " = "
             << coefficients[i] << endl;
    }

    // Predict the score for a student who studied 5 hours
    // and slept for 8 hours
    vector<double> new_student = {5, 8};

    double predicted_score = predict(coefficients, new_student);

    cout << "Predicted exam score: "
         << predicted_score << endl;

    return 0;
}
