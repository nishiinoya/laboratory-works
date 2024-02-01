#include <iostream>
using namespace std;

double solve(double a , double b, double c, double &x1, double &x2)
{
    auto D_calc = [&](){ return b * b - 4 * a * c ;};
    double d = D_calc();
    if (a == 0) 
    {
        if (b == 0) 
        {
            if (c == 0) 
            {
               return -1;
            }
            else 
            {
                return 0;
            }
        }
        else
        {
            double x = -c / b;
            return 1;
        }
    } 
    else 
    {
        if (d > 0)
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            return 2;
        } 
        else if (d == 0) 
        {
            double x = -b / (2 * a);
            return 1;
        } 
        else 
        {
           return 0;
        }
    }
  
}
int main()
{
    double a, b, c, x1, x2;
    cout << "Enter a, b, c: " ;
    cin >> a >> b >> c;
    int result = solve(a, b, c, x1, x2);

    if (result == 2)
    {
        cout << "The equation has two real roots: x1 = " << x1 << " x2 = " << x2 << endl;
    }
    else if (result == 1)
    {
        cout << "The equation has one real root: x = " << x1 << endl; 
    }
    else if (result == 0)
    {
       cout << "The equation has no real roots." << endl;
    }
    else
    {
        cout << "The equation has an infinite number of roots." << endl;
    }
    return 0;
}