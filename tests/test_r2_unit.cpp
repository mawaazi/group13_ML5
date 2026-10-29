#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "../include/machine_learning_1/coefficient_of_determination.h"

using namespace ml1;

void run_tests() {
    // Test 1: Perfect fit (R² should be exactly 1.0)
    {
        std::vector<double> actual = {1.0, 2.0, 3.0, 4.0, 5.0};
        std::vector<double> predicted_perfect = {1.0, 2.0, 3.0, 4.0, 5.0};
        assert(coefficient_of_determination(actual, predicted_perfect) == 1.0);
        std::cout << "[PASS] Perfect fit R^2 == 1.0\n";

        // Test 2: Float template test
        std::vector<float> f_actual = {1.0f, 2.0f, 3.0f};
        std::vector<float> f_pred = {1.0f, 2.0f, 3.0f};
        assert(coefficient_of_determination(f_actual, f_pred) == 1.0);
        std::cout << "[PASS] Templating works for float\n";

        // Test 3: Empty vector should throw InvalidInputError
        bool threw_error = false;
        try {
            std::vector<double> empty;
            coefficient_of_determination(empty, empty);
        } catch (const InvalidInputError& e) {
            threw_error = true;
        }
        assert(threw_error);
        std::cout << "[PASS] Throws error on empty vectors\n";

        // Test 4: Mismatched sizes should throw InvalidInputError
        threw_error = false;
        try {
            std::vector<double> a = {1.0, 2.0, 3.0};
            std::vector<double> p = {1.0, 2.0};
            coefficient_of_determination(a, p);
        } catch (const InvalidInputError& e) {
            threw_error = true;
        }
        assert(threw_error);
        std::cout << "[PASS] Throws error on mismatched vector sizes" << std::endl;

        // Test 5: Constant data should throw InvalidInputError (SS_tot = 0)
        threw_error = false;
        try {
            std::vector<double> a = {2.0, 2.0, 2.0, 2.0};
            std::vector<double> p = {1.0, 2.0, 3.0, 4.0};
            coefficient_of_determination(a, p);
        } catch (const InvalidInputError& e) {
            threw_error = true;
        }
        assert(threw_error);
        std::cout << "[PASS] Throws error on constant data (SS_tot = 0)" << std::endl;

        std::cout << "\nAll unit tests passed successfully!" << std::endl;
    }
}

int main() {
    std::cout << "---Running R^2 Unit Tests---" << std::endl;
    run_tests();
    return 0;
}   
