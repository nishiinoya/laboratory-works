#include "callback_template.h"


int function1(double x) {
    return x * x;
}

double function2(double x) {
    return std::sin(x);
}

int main() {
    double start = -10.0;
    double end = 10.0;
    double step = 0.1;

    double min_derivative1 = min_deriv(function1, start, end, step);
    std::cout << "Minimum value of the first derivative of x^2: " << min_derivative1 << std::endl;

    double min_derivative2 = min_deriv(function2, start, end, step);
    std::cout << "Minimum value of the first derivative of sin: " << min_derivative2 << std::endl;

    return 0;
}
