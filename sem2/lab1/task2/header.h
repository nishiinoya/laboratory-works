#ifndef HEADER_H
#define HEADER_H

#include <cmath>
#include <iostream>

typedef double (*FuncPointer)(double);

double min_deriv(FuncPointer func, double start, double end, double step);

#endif