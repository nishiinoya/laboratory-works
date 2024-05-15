#include "header.h"

void print_table(int n, double start, double end, double step, double (*FuncPointer)(double, int)) {
    printf(" x\t| f(x)\n");
    printf("--------------\n");

    for (double x = start; x <= end; x += step) {
        double y = FuncPointer(x, n);
        printf("%.2f\t| %.2f\n", x, y);
    }
}
