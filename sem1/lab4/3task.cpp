#include <iostream>
using namespace std;

int func(int x = 1, int y = 1, int z = 1)
{
    return x * y * z;
}
int func1()
{
    return 1;
}

int func1(int x, int y)
{
    return x * y;
}

double func1(double x, double y)
{
    return x * y;
}

double func1(double x, double y, double z)
{
    return x * y * z;
}
int main()
{
    cout << func() << endl;
    cout << func(5, 1) << endl;
    cout << func(1, 2) << endl;
    cout << func(1, 2, 5) << endl;

    cout << func1() << endl;
    cout << func1(5, 1) << endl;
    cout << func1(1.0, 2.0) << endl;
    cout << func1(1.0, 2.0, 5.0) << endl;
    return 0;
}
