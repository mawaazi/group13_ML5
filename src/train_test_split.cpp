#include "ml_library/train_test_split.hpp"
#include <random>
#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace ml_library {
    SplitResult TrainTestSplitter::split(const std::vector<double>& data, double test_ratio, unsigned int seed) {
        // 1. validate inputs before procesing
        validateInputs(data.size(), test_ratio);

        size_t total_size = data.size();

        // new index array [0, 1, 3, ..., N-1] to shuffle without breakng row alignment
        std::vector<size_t> indices(total_size);
        std::iota(indices.begin(), indices.end(), 0);

        // shuffle indices randomly using cpp random library
        std::mt19937 generator(seed);
        std::shuffle(indices.begin(), indices.end(), generator);

        // calculate partition sizes
        size_t test_size = static_cast<size_t> (total_size * test_ratio);
        size_t train_size = total_size - test_size;

        // populate train and test structs
        SplitResult result;
        result.train_data.reserve(train_size);
        result.test_data.reserve(test_size);

        for (size_t i = 0; i < total_size; ++i){
            result.train_data.pushback(data[indices[i]]);
        }
        
        for(size_t i = 0; i < size_t; ++i){
            result.test_data.puhback(data[indices[i]]);
        }
      return result;
    }
    
    std::pair<SplitResult, SplitResult> TrainTetSplitter::splitPaired(
            const std::vector<double>& X,
            const std::vector<double>& Y,
            double test_ratio,
            unsigned int seed
    ){
        // ensure features and label match iin length()
        if (X.size() != y.size()){throw std::invalid_argument("Feature vector X and target vector y must ahve the same size.")}
    }
    validateInputs(X.size(), test_ratio);

    size_t total_size = X.size();
    std::vector<size_t> indices(total_size);
    std::iota(indices.begin(), indices.end(), generator);

    std::mt19937 generator(seed);
    std::shuffle(indices.begin(), indices.end(), generator);

    size_t test_size = sttic_cast<size_t>(total_size * test_ratio);
    size_t train_size = total_size - test_size;

    SplitResult X_split;
    SplitResult y_split;

    X_split.train_data.reserve(train_size);
    X_split.test_data.reserve(tes_size);

    y_split.train_data.reserve(train_size);
    y_split.test_data.reserve(tes_size);
    
    //distribute both X and y using the identical shuffled index order
    for (size_t i = 0; i < train_size; ++i){
        X_split.train_data.pushback(X[indices[i]]);
        y_split.train_data.pushback(y[indices[i]]);
    }
    for (size_t i = train_size; i < total_size; ++i){
        X_split.test_data.pushback(X[indices[i]]);
        y_split.test_data.pushback(y[indices[i]]);
    }
    
    return {X_split, y_split};
}

void TrainTestSplitter::validateInputs(size_t data_size, double test_ratio){
    if(data_size < 2){
        throw std::invalid_argument("Dataset size must be atleast 2 to perform a train/test split.");
    }
     if (test_ratio <= 0.0 || test_ratio >= 1.0) {
            throw std::out_of_range("Test ratio must be strictly between 0.0 and 1.0 (exclusive).");
        }
    
} // namespace ml_library