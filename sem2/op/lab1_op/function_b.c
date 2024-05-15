#include "header_b.h"

double function_b(double x, double y, double z) {
    // module
    if (x < 0) {
        x *= -1;
    }
    double b;
    if ((x + (1 / (pow(y, 2) + 1))) == 0) {
        printf("error");
        return -1;
    }
    b = (y * (atan(z) - (M_PI / 6))) / (x + (1 / (pow(y, 2) + 1)));
  
        return b;
}