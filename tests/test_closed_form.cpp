#include "closed_form.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    // Test 1: Sum of the first 10 natural numbers
    assert(closed_form::sum_natural_numbers(10) == 55);

    // Test 2: Arithmetic series sum: 5, 8, 11, 14, 17
    assert(closed_form::arithmetic_series_sum(5, 5, 3) == 55);

    // Test 3: Geometric series sum: 2, 6, 18, 54
    assert(closed_form::geometric_series_sum(4, 2, 3) == 80);

    // Test 4: Geometric series sum when r = 1
    assert(closed_form::geometric_series_sum(4, 5, 1) == 20);

    // Test 5:  Check a decimal result
    assert(abs(closed_form::arithmetic_series_sum(3, 1.5, 0.5) - 6.0) < 1e-9);

    cout << " All closed-form equation tests passed!\n";
    return 0;
}