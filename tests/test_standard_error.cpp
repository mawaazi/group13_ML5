#include "../include/machine_learning_1/standard_error_estimation.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;


// Check whether two numbers are approximately equal.
bool approximatelyEqual(
    double a,
    double b,
    double tolerance = 0.0001
)
{
    return fabs(a - b) < tolerance;
}


int main(){

    cout << "Standard Error of Estimation Test" << endl;

    cout << "\nTest 1: Perfect Regression" << endl;

     // Model:
    //
    // y = 2 + 3*x1 + 4*x2
    //

    vector<vector<double>> X1 = {
        {1, 1},
        {2, 1},
        {1, 2},
        {3, 2},
        {2, 3},
        {4, 3}
    };

    
    vector<double> y1 = {
        9,
        12,
        13,
        19,
        20,
        26
    };

    // Exact coefficients.
    //
    // beta0 = 2
    // beta1 = 3
    // beta2 = 4
    vector<double> coefficients1 = {
        2.0,
        3.0,
        4.0
    };

    double result1 =
        calculateStandardError(
            X1,
            y1,
            coefficients1
        );

         cout << "Calculated SEE: "
         << result1
         << endl;


    if (approximatelyEqual(result1, 0.0)) {

        cout << "Test 1 PASSED." << endl;

    }
    else {

        cout << "Test 1 FAILED." << endl;

    }

    
    cout << "\nTest 2: Regression With Error" << endl;

    vector<vector<double>> X2 = {
        {1, 1},
        {2, 1},
        {1, 2},
        {3, 2},
        {2, 3},
        {4, 3}
    };

    vector<double> y2 = {
        9.2,
        11.7,
        13.4,
        18.6,
        20.3,
        26.1
    };


    vector<double> coefficients2 = {
        2.0,
        3.0,
        4.0
    };

    double result2 =
        calculateStandardError(
            X2,
            y2,
            coefficients2
        );


    cout << "Calculated SEE: "
         << result2
         << endl;

    // Expected value:
    //
    // Residuals:
    //
    // 0.2, -0.3, 0.4, -0.4, 0.3, 0.1
    //
    // SSE = 0.55
    //
    // n = 6
    // p = 3
    //
    // SEE = sqrt(0.55 / (6 - 3))
    //     ≈ 0.42817

    double expected2 = 0.42817;


    if (approximatelyEqual(result2, expected2, 0.0001)) {

        cout << "Test 2 PASSED." << endl;

    }
    else {

        cout << "Test 2 FAILED." << endl;

    }


    cout << "\nTest 3: Invalid Input" << endl;

    vector<vector<double>> X3 = {
        {1},
        {2},
        {3}
    };

    // Wrong number of y values.
    vector<double> y3 = {
        3,
        5
    };

    vector<double> coefficients3 = {
        1.0,
        2.0
    };


    try {

        calculateStandardError(
            X3,
            y3,
            coefficients3
        );

        cout << "Test 3 FAILED: "
             << "Exception was not thrown."
             << endl;

    }
    catch (const invalid_argument& error) {

        cout << "Test 3 PASSED: "
             << error.what()
             << endl;

    }

    cout << "\nTESTING COMPLETE"
         << endl;


    return 0;

}