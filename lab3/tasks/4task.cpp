#include <iostream>
using namespace std;

int main()
{
    double eps, element;
    double y = 0;
    cout << "eps: ";
    cin >> eps;
    element = 0.5;
    int i = 1;  
    while (element >= eps)
    {
        y += element;  
        i++;
        element = 1.0 / (1 << i) ; 
    }
    cout << "y: " << y <<endl; 
    return 0;
}

