#include <iostream>
using namespace std;

int main()
{
    

    int b[45];
    

    cout << "Array of 45 numbers: " ;

    for (int i = 0; i < 45; ++i)
    { 
    cin >> b[i];     
    }

    int sum = 0;

    for (int i = 0; i < 45; ++i) {
        if (b[i] < 0) 
        {
            sum += b[i];
        }
    }

    cout << "Sum of negative numbers: " << sum << endl;

    return 0;
}

