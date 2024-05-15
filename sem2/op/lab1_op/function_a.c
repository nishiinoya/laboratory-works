#include "header_a.h"

double function_a(double x, double y) {
    double a;

    //module
    if(x < 0) {
        x *= -1;
    }
    a = pow(y, cbrt((x))) + pow(sin(y - 3), 3);
    return a;
}
