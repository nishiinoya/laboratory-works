#pragma once
#include <cmath>

class DerivativeSolver {
public:
    virtual double function(double x) const = 0; 
    double minDerivative(double start, double end, double step);
    double firstDerivative(double x, double step) const;
};

