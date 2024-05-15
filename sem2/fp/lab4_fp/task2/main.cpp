#include "FunctionDerivativeSolver.h"
#include <iostream>

int main() {
    double start = -10.0;
    double end = 10.0;
    double step = 0.1;

    FunctionDerivativeSolver solver;

    double min_derivative = solver.minDerivative(start, end, step);

    // The minimum value of the derivative of sin is - 1.
    std::cout << "Minimum value of the first derivative: " << min_derivative << std::endl;

    return 0;
}
