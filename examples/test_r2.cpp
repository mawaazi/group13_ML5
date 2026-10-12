#include <iostream>
#include <vector>
#include "../include/machine_learning_1/coefficient_of_determination.h"

int main() {
    std::vector<double> actual    = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> predicted = {1.1, 1.9, 3.2, 3.8, 5.1};

    std::cout << "R^2 = "
              << coefficient_of_determination(actual, predicted)
              << "\n";
    return 0;
}