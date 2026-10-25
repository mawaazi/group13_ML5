
#include "closed_form.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

using namespace std;

// Solve the system of equations A * result = b
static vector<double> solve_system(
    vector<vector<double>> A,
    vector<double> b
) {
    int n = b.size();

    // Eliminate values below each pivot
    for (int i = 0; i < n; i++) {
        int pivot = i;

        for (int r = i + 1; r < n; r++) {
            if (abs(A[r][i]) > abs(A[pivot][i])) {
                pivot = r;
            }
        }

        if (abs(A[pivot][i]) < 1e-12) {
            throw runtime_error("No unique solution exists.");
        }

        swap(A[i], A[pivot]);
        swap(b[i], b[pivot]);

        for (int r = i + 1; r < n; r++) {
            double factor = A[r][i] / A[i][i];

            for (int j = i; j < n; j++) {
                A[r][j] -= factor * A[i][j];
            }

            b[r] -= factor * b[i];
        }
    }

    // Work backwards to find the answers
    vector<double> result(n);

    for (int i = n - 1; i >= 0; i--) {
        result[i] = b[i];

        for (int j = i + 1; j < n; j++) {
            result[i] -= A[i][j] * result[j];
        }

        result[i] /= A[i][i];
    }

    return result;
}


// Calculate the coefficients for simple and multiple linear regression
vector<double> fit(
    const vector<vector<double>>& X,
    const vector<double>& y
) {
    if (X.empty() || X.size() != y.size() || X[0].empty()) {
        throw invalid_argument("Invalid training data.");
    }

    int n = X.size();
    int p = X[0].size() + 1;

    for (int i = 0; i < n; i++) {
        if (X[i].size() + 1 != p) {
            throw invalid_argument("Inconsistent features.");
        }
    }

    vector<vector<double>> A(p, vector<double>(p, 0));
    vector<double> b(p, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            double xj = (j == 0) ? 1.0 : X[i][j - 1];

            b[j] += xj * y[i];

            for (int k = 0; k < p; k++) {
                double xk = (k == 0) ? 1.0 : X[i][k - 1];

                A[j][k] += xj * xk;
            }
        }
    }

    return solve_system(A, b);
}


// Predict an answer using the calculated coefficients
double predict(
    const vector<double>& coefficients,
    const vector<double>& features
) {
    if (coefficients.empty()) {
        throw logic_error("Calculate coefficients first.");
    }

    if (features.size() + 1 != coefficients.size()) {
        throw invalid_argument("Wrong number of features.");
    }

    double answer = coefficients[0];

    for (size_t i = 0; i < features.size(); i++) {
        answer += coefficients[i + 1] * features[i];
    }

    return answer;
}
