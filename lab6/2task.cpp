#include <iostream>
#include <ctime>
using namespace std;

double Random()
{
    return rand() % 100;
}

bool readData(int &m, int &n, int &p, int &k)
{
    cout << "Enter m and n (size of matrix A): ";
    cin >> m >> n;
    cout << "Enter p and k (size of matrix B): ";
    cin >> p >> k;
    if (m <= 0 || n <= 0)
    {
        cout << "Wrong values" << endl;
        return false;
    }
    if (n != p)
    {
        cout << "Multiplication impossible" << endl;
        return false;
    }
    return true;
}

double **create(int m, int n)
{
    double **matrix = new double *[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new double[n];
    }
    return matrix;
}

void fill(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = Random();
        }
    }
}

void print(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

double **multiplication_m(double **a, double **b, int m, int n, int k)
{
    double **c = create(m, k);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            c[i][j] = 0;

            for (int l = 0; l < n; l++)
            {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    return c;
}

void delete_m(double **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    srand(time(0));
    int m, n, p, k;
    if (readData(m, n, p, k))
    {
        double **a = create(m, n);
        fill(a, m, n);
        print(a, m, n);
        double **b = create(p, k);
        fill(b, p, k);
        print(b, p, k);
        double **c = multiplication_m(a, b, m, n, k);
        print(c, m, k);
        delete_m(a, m);
        delete_m(b, p);
        delete_m(c, m);
        return 0;
    }
    return 1;
}
