#include "header.h"

double sum_of_second_powers(double arg1, double arg2) {
    return pow(arg1, 2) + pow(arg2, 2);
}
int main() {

   myspace::FuncPointer functions[] = {&pow, &hypot, &fmax, &fmin, &sum_of_second_powers};

    double arg1, arg2;
    std::cout << "Enter two double values: ";
    std::cin >> arg1 >> arg2;

    for (myspace::FuncPointer func : functions) {
        myspace::display(func, arg1, arg2);
    }

    return 0;
}
