#include "header.h"
#include "test.h"
void print_table(int n, double start, double end, double step, FuncPointer func) {
    printf(" x\t| f(x)\n");
    printf("--------------\n");

    for (double x = start; x <= end; x += step) {
        double y = func(x, n);
        if(y == 1) {
            return;
        }
        // Format and print the output
        printf("%.f\t| %.f\n", x, y);
    }
}
