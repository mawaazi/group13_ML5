#ifndef SMOTE_HPP
#define SMOTE_HPP

#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "ml_error.hpp"

namespace ml1 {

    //A simple structure to hold our dataset.
    struct Dataset {
        std::vector<std::vector<double>> features; // The X values
        std::vector<int> labels; // The y values
    };

    /**
     * calculates the Euclidean distance between two points in n-dimensional space.
     */
    inline double euclidean_distance(
        const std::vector<double>& a, 
        const std::vector<double>& b) 
    {
        if (a.size() != b.size()) {
            throw InvalidInputError("Vectors must be of the same length to calculate Euclidean distance.");
        }
        
        double sum = 0.0;
        for (std::size_t i = 0; i < a.size(); ++i) {
            double diff = a[i] - b[i];
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
 

/**
 * Finds the k-nearest neighbors for a specific point within a subset of data.
 * 
 * @param target_idx The index of the point we are finding neighbors for.
 * @param features The full feature matrix.
 * @param indices The indices of the minority class (we only search within these).
 * @param k The number of neighbors to find.
 * @return A vector of indices representing the k-nearest neighbors.
 */
inline std::vector<std::size_t> find_k_nearest_neighbors(
    std::size_t target_idx,
    const std::vector<std::vector<double>>& features,
    const std::vector<std::size_t>& minority_indices,
    std::size_t k)
{
    if (k >= minority_indices.size()) {
        throw InvalidInputError("k must be less than the number of minority samples.");
    }

    std::vector<std::pair<double, std::size_t>> distances;
    
    // Calculate distance to all OTHER minority points
    for (std::size_t idx : minority_indices) {
        if (idx == target_idx) continue; // Don't include the point itself
        double dist = euclidean_distance(features[target_idx], features[idx]);
        distances.push_back({dist, idx});
    }

    // Sort by distance (ascending)
    std::sort(distances.begin(), distances.end());

    // Extract the top k indices
    std::vector<std::size_t> neighbors;
    for (std::size_t i = 0; i < k; ++i) {
        neighbors.push_back(distances[i].second);
    }

    return neighbors;
}

} // namespace ml1

#endif // SMOTE_HPP