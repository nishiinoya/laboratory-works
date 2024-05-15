#include "header.h"

namespace myspace {
    typedef double (*FuncPointer)(double, double);

    void display(FuncPointer func, double arg1, double arg2) {
    std::cout << "Arguments: " << arg1 << ", " << arg2 << std::endl;
    std::cout << "Function value: " << func(arg1, arg2) << std::endl;
    }
}

double sum_of_cube_powers(double arg1, double arg2) {
    return pow(arg1, 3) + pow(arg2, 3);
}

int main() {

    myspace::FuncPointer functions[] = {&pow, &hypot, &fmax, &fmin, &sum_of_cube_powers};

    double arg1, arg2;
    std::cout << "Enter two double values: ";
    std::cin >> arg1 >> arg2;

    for (myspace::FuncPointer func : functions) {
        myspace::display(func, arg1, arg2);
    }

    return 0;
}
