#include <iostream>
using namespace std;

double y_func(int x, int n)
{
    if (n < 1)
    {
        return 1;
    }
    else
    {
        double y = (x + n) * y_func(x, n - 1);
        return y;
    }
}
int main()
{
    int x, n;
    cout << "x, n: ";
    cin >> x >> n;
    
    if (n < 1)
    {
        cout << "n must be greater than 0" << endl;
        return 1;
    }
    else
    {
        cout << "y = " << y_func(x,n) << endl;
    }
    return 0;
}