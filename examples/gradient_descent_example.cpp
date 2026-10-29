#include<iostream>
#include<vector>
#include<iomanip>
#include "../include/machine_learning_1/gradient_descent.hpp"

using namespace std;

int main(){
    /*
    Example: learn the relationship y=2x

    Training data:
    x=1, y=2
    x=2, y=4
    x=3, y=6

    The model is:
    y_predicted = bias + (weight*x)

    Parameters to learn:
    weights[0] = bias
    weights[1] = weight for x
    */
   vector<vector<double>> x = {
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
    x, y, weights, learningRate, iterations
   );

   cout<< "After"<<iterations<< "iterations: \n";
   cout<< "Learned bias ="<<finalWeights[0]<< '\n';
   cout<< "Learned weight= "<< finalWeights[1]<< '\n';

   cout<< "Predictions using the learned model:\n";
   for(size_t i=0; i<x.size(); ++i){
    double predictedy = finalWeights[0]+ finalWeights[1] *x[i][0];
    cout<< "x= "<< x[i][0]<<", actual y= "<< y[i]
    <<", predicted y= "<<predictedy<<'\n';
   }

   cout <<"\nExpected result: bias close to 2 and weight close to 3.\n";
   return 0;
}