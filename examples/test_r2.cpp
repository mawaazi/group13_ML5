#include <iostream>
#include <vector>
#include <cmath>
#include "../include/machine_learning_1/coefficient_of_determination.h"

using ml1::coefficient_of_determination;
using ml1::MLError;

static void print_result(const std::string& label,
                         const std::vector<double>& actual,
                         const std::vector<double>& predicted)
{
    try {
        double r2 = coefficient_of_determination(actual, predicted);
        std::cout << label << " -> R^2 = " << r2 << "\n";
    } catch (const MLError& e) {
        std::cout << label << " -> ERROR: " << e.what() << "\n";
    }
}

int main() {
    // ── Happy path ─────────────────────────────────────────────
    print_result("Perfect fit",
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {1.0, 2.0, 3.0, 4.0, 5.0});

    print_result("Good fit",
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {1.1, 1.9, 3.2, 3.8, 5.1});

    print_result("Bad fit (reversed)",
        {1.0, 2.0, 3.0, 4.0, 5.0},
        {5.0, 4.0, 3.0, 2.0, 1.0});

    // ── Edge cases (should print ERROR) ────────────────────────
    print_result("Empty vectors",      {},                        {});
    print_result("Size mismatch",      {1.0, 2.0},                {1.0});
    print_result("Constant actual",    {3.0, 3.0, 3.0},           {1.0, 2.0, 3.0});
    print_result("NaN present",
        {1.0, std::nan(""), 3.0},
        {1.0, 2.0, 3.0});

    return 0;
}