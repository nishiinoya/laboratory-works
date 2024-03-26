#include <iostream>
using namespace std;

int main()
{
    double n, x;
    double y = 1;
    int k = 1;

    cout << "n: ";
    cin >> n;
    cout << "x: ";
    cin >> x;
    for (int i = 1; i <= 2*n; i++)
    {
        y *= x + i * k;
        k = -k;
    }
    cout << "y: " << y << endl;
    return 0;
}
