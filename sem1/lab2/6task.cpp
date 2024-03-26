#include <iostream>
using namespace std;

int main()
{
    double x, res;
    cout << "x: ";
    cin >> x;

    res = x < 0 ? x/(x+1) : x<= 2 ? x - x*x : 1 + 1/x + 1/(x*x*x);
    x == -1 || x == 0? cout << "Error\n" : cout << res << endl;
    return 0;
}