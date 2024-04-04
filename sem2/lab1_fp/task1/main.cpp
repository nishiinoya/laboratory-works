#include "header.h"
#include <iostream>
using std::cout;
using std::endl;

double y_func(double x, int n) {
    double y = 0;
    if (x >= 0 && n >= 1) {
        for (int i = 0; i < n - 1; i++) {
            double p = 1;
            for (int j = 0; j < n - 1; j++) {
                p = p * (x + i + j * j);
            }
            y += p;
        }
        return y;
    } else if (x < 0 && n >= 4) {
        y = 1;
        for (int j = 2; j < n - 2; j++) {
            y = y * (j + x);
        }
        return y;
    } else {

        return 1;
    }
}
double square_func(double x, int n) {
    return x * x;
}
int main() {
    int n = 5;
    double x1 = 1;
    double x2 = 4;
    double step = 0.5;

    print_table(n, x1, x2, step, y_func);
    cout << endl;
    print_table(n, x1, x2, step, square_func);
    cout << endl;
    print_table(n, x1, x2, step, pow);

    return 0;
}
