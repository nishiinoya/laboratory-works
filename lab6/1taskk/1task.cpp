#include <iostream>
#include <fstream>
using namespace std;

void randNum(double *pa, int n)
{
     for (double* p = pa; p < pa + n; p++)
    {
       *p = (rand() % 100000) / 1000.;
    }
}    

double find_min(double *pa, int n)
{
    double min = pa[0];
    for (double* p = pa; p < pa + n; p++)
    {
       if (*p < min)
        {
            min = *p;
        }
    }

    return min;
}

double find_max(double *pa, int n)
{
    double max = pa[0];

    for (double* p = pa; p < pa + n; p++)
    {
       if (*p > max)
        {
            max = *p;
        }
    }

    return max;
}
void print_arr(double *pa, int n)
{
    for (double* p = pa; p < pa + n; p++)
    {
       cout << *p << " ";
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    double *pa = new double[n];
    randNum(pa, n);
    print_arr(pa, n);
    double minValue = find_min(pa, n);
    double maxValue = find_max(pa, n);
    delete[] pa;
    ofstream result("task1results.txt");
    result << "minimum: " << minValue << endl;
    result << "maximum: " << maxValue << endl;
    result << "sum of min and max: " << minValue + maxValue;
    result.close();
    return 0;
}