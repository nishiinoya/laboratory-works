#include <iostream>
#include <ctime>
using namespace std;

double Random()
{
    return rand() % 100;
}

int main()
{
    srand(time(0));
    const int m = 3;
    const int n = 4;
    const int p = 7;

    double a[m][n] = {};
    for ( auto &row : a)
    {
        for ( double &item : row)
        {
            item = Random();
        }
    }
    cout << "Matrix A: \n" << endl;
    for ( auto &row : a)
    {
        for ( double &item : row)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
    cout << endl;

    double b[n][p] = {};
    for ( auto &row : b)
    {
        for ( double &item : row)
        {
            item = Random();
        }
    }
    cout << "Matrix B: \n" << endl;
    for ( auto &row : b)
    {
        for (double  &item : row)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
    cout << endl;

    double c[m][p] = {};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Result of multiplication A by B:  \n" << endl;
    for ( auto &row : c)
    {
        for ( double &item : row)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
    return 0;
}
