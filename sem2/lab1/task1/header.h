#ifndef HEADER_H
#define HEADER_H
#include <cstdio>

typedef double (*FuncPointer)(double, int);

void print_table(int n, double start, double end, double step, FuncPointer func);
bool check_data(int n, double x1, double x2, double step);

#endif
