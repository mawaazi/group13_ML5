#include "closed_form.hpp"
#include <iostream>

using namespace std;
int main(){
    cout << "Closed-form  Equations Example\n\n";
    
    //sum of the first 10 natural numbers
    cout << "sum of natural numbers" << closed_form::sum_natural_numbers(10) << '\n';

    //Arithmetic series: 5, 8, 11,14,17
    cout <<"Arithmetic series sum: " << closed_form::arithmetic_series_sum(5, 5, 3) << '\n';

    //Geometric series: 2, 6, 18, 54
    cout <<"Geometric series sum: " << closed_form::geometric_series_sum(4, 2, 3) << '\n';
    
}