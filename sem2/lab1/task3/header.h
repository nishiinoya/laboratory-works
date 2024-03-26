#ifndef HEADER_H
#define HEADER_H

#include <cmath>
#include <iostream>

namespace myspace {
    typedef double (*FuncPointer)(double, double);

    void display(FuncPointer func, double arg1, double arg2) {
        std::cout << "Arguments: " << arg1 << ", " << arg2 << std::endl;
        std::cout << "Function value: " << func(arg1, arg2) << std::endl;
    }
}

#endif