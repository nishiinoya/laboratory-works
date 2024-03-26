#include "header.h"

double function1(double x) {
    return x * x; 
}
double function2(double x) {
    return sin(x);
}

int main() {
    double start = -10.0;
    double end = 10.0;
    double step = 0.1;

    double min_derivative1 = min_deriv(function1, start, end, step);
    std::cout << "Minimum value of the first derivative: " << min_derivative1 << std::endl;
    double min_derivative2 = min_deriv(function2, start, end, step);
    std::cout << "Minimum value of the first derivative: " << min_derivative2 << std::endl;
    // The minimum value of the derivative of sin is - 1.
    // The minimum value of the derivative of x square is - 20.
    return 0;
}
