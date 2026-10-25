#include<iostream>
#include<vector>
#include<iomanip>
#include "../include/machine_learning_1/gradient_descent.hpp"

using namespace std;

int main(){
    /*
    Example: learn the relationship y=2x

    Training data:
    X=1, y=2
    X=2, y=4
    X=3, y=6

    The model is:
    y_predicted = bias + (weight*X)

    Parameters to learn:
    weights[0] = bias
    weights[1] = weight for X
    */
   vector<vector<double>> X = {
    {1.0}, {2.0}, {3.0}
   };

   vector<double> y ={5.0,8.0,11.0};
   //First guess is that both the bias and weight are zero
   vector<double> weights = {0.0,0.0};
   double learningRate = 0.01;
   int iterations = 1000;

   cout<<fixed<<setprecision(6);
   cout<<"\nStarting parameters: \n";
   cout<<"Bias= "<<weights[0]<<'\n';
   cout<<"Weight= "<<weights[1]<<'\n';

   //The function is declared in gradient_descent.hpp and implemented in gradient_descent.cpp
   vector<double> finalWeights = LinearRegression:: computeGradientDescent(
    X, y, weights, learningRate, iterations
   );

   cout<< "After"<<iterations<< "iterations: \n";
   cout<< "Learned bias ="<<finalWeights[0]<< '\n';
   cout<< "Learned weight= "<< finalWeights[1]<< '\n';

   cout<< "Predictions using the learned model:\n";
   for(size_t i=0; i<X.size(); ++i){
    double predictedy = finalWeights[0]+ finalWeights[1] *X[i][0];
    cout<< "X= "<< X[i][0]<<", actual y= "<< y[i]
    <<", predicted y= "<<predictedy<<'\n';
   }

   cout <<"\nExpected result: bias close to 2 and weight close to 3.\n";
   return 0;
}