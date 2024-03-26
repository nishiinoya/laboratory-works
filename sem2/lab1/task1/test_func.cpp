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

bool check_data(int n, double x1, double x2, double step) {
    if (step < 0) {
        cout << "step must be greater than 0" << endl;
        return false;
    }
    if (x1 >= x2) {
        cout << "x1 must be less than x2" << endl;
        return false;
    }
    if (n < 0) {
        cout << "n must be greater than 0" << endl;
        return false;
    }
    return true;
}
