#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "../include/machine_learning_1/coefficient_of_determination.h"

using ml1::coefficient_of_determination;
using ml1::MLError;

template <typename T>
void test(const std::string& name, const std::vector<T>& a, const std::vector<T>& p) {
    try {
        double r2 = coefficient_of_determination(a, p);
        std::cout << name << " -> R^2 = " << r2 << "\n";
    } catch (const MLError& e) {
        std::cout << name << " -> ERROR: " << e.what() << "\n";
    }
}

int main() {
    std::cout << "--- Templating Test ---\n";
    test("double       ", std::vector<double>{1.0, 2.0, 3.0, 4.0, 5.0}, std::vector<double>{1.1, 1.9, 3.2, 3.8, 5.1});
    test("float        ", std::vector<float>{1.0f, 2.0f, 3.0f, 4.0f, 5.0f}, std::vector<float>{1.1f, 1.9f, 3.2f, 3.8f, 5.1f});
    test("long double  ", std::vector<long double>{1.0L, 2.0L, 3.0L}, std::vector<long double>{1.1L, 2.0L, 2.9L});

    std::cout << "\n--- Edge Cases ---\n";
    test("Empty vectors", std::vector<double>{}, std::vector<double>{});
    test("Constant data", std::vector<double>{5.0, 5.0, 5.0}, std::vector<double>{1.0, 2.0, 3.0});

    return 0;
}