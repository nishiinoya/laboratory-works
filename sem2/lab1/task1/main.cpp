#include "header.h"
#include "test.h"
#include <iostream>

int main()
{
    int n = 5;
    double x1 = 1;
    double x2 = 4;
   double step = 2;

   if (check_data(n, x1, x2, step)){
    print_table(n, x1, x2, step, y_func);
   }


    return 0;
}
