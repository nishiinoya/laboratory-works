#include <iostream>
#include <cmath>
using namespace std;

void transformArray(int array[][5], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] % 2 == 0)
            {
                array[i][j] *= array[i][j];
            }
        }
    }
}

int main()
{
    const int m = 3;
    const int n = 5;

    int array[m][n] = {
        {2, 5, 8, -3, 22},
        {1, 4, 7, 10, 45},
        {3, 6, 9, 12, 78},
    };

    cout << "Original Array:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    transformArray(array, m, n);

    cout << "\nTransformed Array (even values replaced with their squares):\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    int minValues[n];
    for (int j = 0; j < n; j++)
    {
        int minVal = array[0][j];
        for (int i = 1; i < m; i++)
        {
            if (array[i][j] < minVal)
            {
                minVal = array[i][j];
            }
        }
        minValues[j] = minVal;
    }
    double minArray[n];
    for (int j = 0; j < n; j++)
    {
        minArray[j] = cbrt(minValues[j]);
    }

    cout << "\nCubic roots of minimal items of columns:\n";
    for (int j = 0; j < n; j++)
    {
        cout << minArray[j] << "\t";
    }
    cout << endl;

    return 0;
}
