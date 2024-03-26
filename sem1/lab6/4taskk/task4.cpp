#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void transform(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] % 2 == 0)
            {
                arr[i][j] *= arr[i][j];
            }
        }
    }
}
void write_infile(ofstream& transformed, int **arr, int n, int m)
{
    transformed << "Transformed array: " << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            transformed << arr[i][j] << " ";
        }
        transformed << endl;
    }
}
void min_cbrt(ofstream &cbrt_minimum, int **arr, int n, int m)
{
    double *minArray = new double[n];
    cbrt_minimum << "Cubic roots of minimum values of coloumns: ";
    for (int j = 0; j < m; j++)
    {
        double minVal = arr[0][j];
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] < minVal)
            {
                minVal = arr[i][j];
            }
        }
        minArray[j] = cbrt(minVal);
        cbrt_minimum << minArray[j] << " ";
    }
    delete[] minArray;
}

void delete_m(int **arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main()
{
    int n, m;
    ifstream myfile("original.txt");
    myfile >> n >> m;

    int inputArr[n][m];
    cout << "size: " << n << " " << m << endl;

    int **arr = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            myfile >> inputArr[i][j];
            arr[i][j] = inputArr[i][j];
        }
    }
    myfile.close();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    transform(arr, n, m);
    ofstream transformed("transformed.txt");
    write_infile(transformed, arr, n, m);
    transformed.close();
    ofstream cbrt_minimum("minimum.txt");
    min_cbrt(cbrt_minimum, arr, n, m);
    cbrt_minimum.close();
    delete_m(arr, n);

    return 0;
}