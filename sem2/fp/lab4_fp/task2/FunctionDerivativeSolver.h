#pragma once

#include "DerivativeSolver.h"

class FunctionDerivativeSolver : public DerivativeSolver {
public:
    double function(double x) const override;
};

