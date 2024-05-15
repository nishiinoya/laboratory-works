#include "DerivativeSolver.h"

double DerivativeSolver::minDerivative(double start, double end, double step) {
    double min_derivative = INFINITY;

    for (double x = start; x <= end; x += step) {
        double derivative = firstDerivative(x, step);

        if (derivative < min_derivative) {
            min_derivative = derivative;
        }
    }

    return min_derivative;
}

double DerivativeSolver::firstDerivative(double x, double step) const {
    return (function(x + step) - function(x)) / step;
}
