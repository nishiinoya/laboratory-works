#include <iostream>
using namespace std;

double y_func(double x, int n)
{
    double y = 0;
    if (x >= 0 && n >= 1)
    {
        for (int i = 0; i < n - 1; i++) 
        {
            double p = 1;
            for (int j = 0; j < n - 1; j++) 
            {
                p = p * (x + i + j * j);
            }
            y += p;
        }
        return y;
    } 
    else if (x < 0 && n >= 4) 
    {
        y = 1;
        for (int j = 2; j < n - 2; j++) 
        {
            y = y * (j + x);
        }
        return y;
    }
    else
    {
        
        return 1;
    }
   
}

double readData(int &n, double &x1, double &x2, double &step) 
{
    cout << "n: ";
    cin >> n;

    cout << "x1, x2: ";
    cin >> x1 >> x2;

    if (x1 >= x2) 
    {
        cout << "x1 must be less than x2" << endl;
        return -1; 
    }
    else if (n < 0)
    {
        cout << "n must be greater than 0" << endl;
        return -1; 
    }

    cout << "step: ";
    cin >> step;
    return step;
}


void results_print(int n, double x1, double x2, double step) 
{
    for (double currentX = x1; currentX <= x2; currentX += step) 
    {
        double result = y_func(currentX, n);
        if (result != 1)
        {
            cout << "x: " << currentX << " y: " << result << endl;
        }
        else
        {
            cout << "error: wrong input of n or x" << endl;
            break;
        }
       
    }
}
int main()
{
    int n;
    double x1, x2, step;
    double currentX;

    double stepValue = readData(n, x1, x2, step);

    
    results_print(n, x1, x2, step);
    

    return 0;
}
