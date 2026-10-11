#ifndef TRAIN_TEST_SPLIT_HPP_INCLUDED
#define TRAIN_TEST_SPLIT_HPP_INCLUDED

#include <vector>
#include <utility>
#include <stdexcept>

namespace ml_library {

template <typename T>
struct traintestsplitresult {

    std::vector <T> xtrain;
    std::vector <T> xtest;
    std::vector <T> ytrain;
    std::vector <T> ytest;
};

template <typename T>
traintestsplitresult <T> traintestsplit(
    const std::vector<T>& x, 
    const std::vector<T>& y,
    double testratio = 0.2,
    unsigned int randomseed = 42
);
}
#endif