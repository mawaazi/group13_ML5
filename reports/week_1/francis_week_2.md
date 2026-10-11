Line of Best Fit Implementation

Francis Wesula 25/U/0917
October 11, 2026


I have completed the initial C++ implementation for the Line of Best Fit (Simple Linear Regression) algorithm using the Least Squares method. The code is modularized and ready to be integrated into our main file once the team reaches that stage.

Files Added/Modified
include/best_fit.hpp: Created the header file containing the function prototypes for calculating the slope (m) and y-intercept (c).
src/best_fit.cpp: Wrote the source code implementing the mathematical logic to process standard vectors of X and Y data points.

The implementation calculates the line equation y = mx + c using:
Slope (m):{N(\sum xy) - (\sum x)(\sum y)}{N(\sum x^2) - (\sum x)^2}
Intercept (c):{\sum y - m(\sum x)}{N}

I will need to coordinate with the team member handling Train/Test Splits to ensure my function accepts their data structures correctly.