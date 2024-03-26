#include <iostream>

using namespace std;

int main()
{
    int y, n;
    cout << "n: ";
    cin >>  n;
    switch (n)
    {
        case 0:
            y = 2;
            break; 
        case 1:
            y = 4;
            break; 
        case 2:
            y = 5;
            break;
        case 3:
            y = 3;
            break;
        case 4: 
            y = 1;
            break;
        default:
            y = 0;
    }
    cout << y << endl;
    return 0;
}