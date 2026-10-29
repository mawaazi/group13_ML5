#include "machine_learning_1/correlation_coefficient.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

int checks = 0;
int failures = 0;
void check(bool condition, const std::string& name) {
    ++checks;
    if (!condition) {
        ++failures;
        std::cerr << "FAIL: " << name << '\n';
    }
}
void near(const std::vector<double>& x, const std::vector<double>& y,
          double expected, const std::string& name) {
    try {
        double actual = statistics::Correlation::pearson(x, y);
        check(std::isfinite(actual) && std::abs(actual - expected) < 1e-10, name);
    } catch (...) { check(false, name); }
}
void invalid(const std::vector<double>& x, const std::vector<double>& y,
             const std::string& name) {
    try {
        statistics::Correlation::pearson(x, y);
        check(false, name);
    } catch (const std::invalid_argument&) { check(true, name); }
    catch (...) { check(false, name); }
}
int main() {
    near({1,2,3}, {40,50,60}, 1, "positive");
    near({1,2,3}, {60,50,40}, -1, "negative");
    near({-1,0,1}, {1,0,1}, 0, "zero linear correlation");
    near({1,2,3}, {1,3,2}, 0.5, "non-perfect correlation");
    near({1,3,2}, {1,2,3}, 0.5, "symmetry");
    near({12,14,16}, {1,3,2}, 0.5, "positive scale and shift");
    near({-1,-2,-3}, {1,3,2}, -0.5, "negative scale");
    near({2,4}, {9,3}, -1, "two pairs");
    near({1e300,2e300,3e300}, {1,2,3}, 1, "large values");
    near({1e-300,2e-300,3e-300}, {1,2,3}, 1, "small values");
    invalid({}, {}, "empty");
    invalid({1}, {2}, "one pair");
    invalid({1,2}, {1,2,3}, "unequal lengths");
    invalid({5,5,5}, {1,2,3}, "constant x");
    invalid({1,2,3}, {5,5,5}, "constant y");
    invalid({0,0}, {1,2}, "zero data");
    invalid({1,std::numeric_limits<double>::infinity()}, {1,2}, "infinity");
    invalid({1,2}, {1,std::numeric_limits<double>::quiet_NaN()}, "NaN");
    std::vector<double> originalX = {1,2,3};
    std::vector<double> originalY = {1,3,2};
    const statistics::Correlation data(originalX, originalY);
    check(std::abs(data.coefficient() - 0.5) < 1e-10, "object calculation");
    originalX[0] = 99;
    originalY.clear();
    check(std::abs(data.coefficient() - 0.5) < 1e-10, "object owns its data");
    try {
        const statistics::Correlation invalidData({1,1}, {2,3});
        invalidData.coefficient();
        check(false, "object rejects constant data");
    } catch (const std::invalid_argument&) {
        check(true, "object rejects constant data");
    }
    std::cout << checks - failures << '/' << checks << " checks passed.\n";
    return failures == 0 ? 0 : 1;
}
