extern module callbackModule;

import <cmath>;
import <iostream>;
import std;
template <typename F>
double first_derivative(F func, double x, double step) {
    return (func(x + step) - func(x)) / step;
}

template <typename F>
double min_deriv(F func, double start, double end, double step) {
    double min_derivative = INFINITY;

    for (double x = start; x <= end; x += step) {
        double derivative = first_derivative(func, x, step);

        if (derivative < min_derivative) {
            min_derivative = derivative;
        }
    }

    return min_derivative;
}
