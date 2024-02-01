#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double a, b, c;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    
    if (a == 0) 
    {
        if (b == 0) 
        {
            if (c == 0) 
            {
                cout << "Infinite solutions\n";
            }
            else 
            {
                cout << "No solutions\n";
            }
        }
        else
        {
            double x = -c / b;
            cout << "Linear equation x = " << x << endl;
        }
    } 
    else 
    {
        double d = b * b - 4 * a * c;

        if (d > 0)
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            cout << "Quadratic equation\n";
            cout << "x1: " << x1 << endl;
            cout << "x2: " << x2 << endl;
        } 
        else if (d == 0) 
        {
            double x = -b / (2 * a);
            cout << "x: " << x << endl;
        } 
        else 
        {
            cout << "No real solutions\n";
        }
    }

    return 0;
}
