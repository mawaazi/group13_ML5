#include <iostream>
#include <vector>
#include "../include/machine_learning_1/smote.hpp"

using namespace ml1;

int main() {
    // 3 points in 2D space
    // Point 0: (1, 1)
    // Point 1: (2, 2)
    // Point 2: (10, 10)
    std::vector<std::vector<double>> features = {
        {1.0, 1.0},
        {2.0, 2.0},
        {10.0, 10.0}
    };

    // All 3 points are considered minority class for this test
    std::vector<std::size_t> minority_indices = {0, 1, 2};

    // Let's find the 1 nearest neighbor for point 0
    std::size_t target = 0;
    std::size_t k = 1;

    std::vector<std::size_t> neighbors = find_k_nearest_neighbors(target, features, minority_indices, k);

    std::cout << "Nearest neighbor to point 0 is point: " << neighbors[0] << "\n";

    // Test distance between (1,1) and (2,2) -> sqrt(1^2 + 1^2) = sqrt(2) = 1.414
    double dist = euclidean_distance(features[0], features[1]);
    std::cout << "Distance between point 0 and point 1: " << dist << "\n";

    return 0;
}