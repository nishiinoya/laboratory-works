#include "header_b.h"
#include "header_a.h"

int main(void) {
    // Test functions
    double A = function_a(-0.62, 0.82);
    printf("A = %lf\n", A);
    double B = function_b(-0.62, 0.82, 25);
    printf("B = %lf\n", B);
    return 0;
}
