#include "header.h"

double min_deriv(FuncPointer func, double start, double end, double step) {
    double min_derivative = INFINITY; // Initial value for minimum derivative

    for (double x = start; x <= end; x += step) {
        double derivative = (func(x + step) - func(x)) / step;

        if (derivative < min_derivative) {
            min_derivative = derivative;
        }
    }

    return min_derivative;
}
