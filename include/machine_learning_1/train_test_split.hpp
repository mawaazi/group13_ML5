#ifndef TRAIN_TEST_SPLIT_HPP_INCLUDED
#define TRAIN_TEST_SPLIT_HPP_INCLUDED

#include <vector>
#include <utility>

/// @brief creating a new namespace so i can freely name classes and functions
namespace ml_library {
    
    /// @brief this struct is for holding the trainng and testing dataa partions
    struct SplitResult {
        std::vector<double> train_data;
        std::vector<double> test_data;
    };

    /// @brief this class splits datasets into training and testing subsets
    class TrainTestSplitter {
        public:
            /// @brief this function splits a single dataset vector into train and test subsets
            /// @param data the complete input dataset
            /// @param test_ratio fraction of data reserrved for testing e.g 0.2 for 20%
            /// @param seed he optional random seed for reproducible shuffling
            /// @return SplitResult containing train aand test vectors
            static SplitResult split(const std::vector<double>& data, double test_ratio, unsigned int seed = 42);
            
            /// @brief Splits paired feature vectors (X) and target vectors (y) simultaneously.
            /// Keeps features and labels synchronized for machine learning models 
            static std::pair<SplitResult, Splitresult> splitPaired(
                const std::vector<double>& X,
                const std::vector<double>& Y,
                unsigned int seed = 42
            );
        
        private:
        /// @brief this helper function validates the size and test dataset ratios
        static void validateInputs(size_t data_size, double test_ratio);    
    };


} // namespace ml_library
#endif // ML_LIBRARY_TRAIN_TEST_SPLIT_HPP