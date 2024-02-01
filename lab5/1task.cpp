#include <iostream>
using namespace std;



double find_min(const double arr[], int size)
{
    double min = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

double find_max(const double arr[], int size)
{
    double max = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    const int n = 5;
    //double array[n] = {3.5, 1.2, 4.8, 2.1, 5.7};
    double array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    double minValue = find_min(array, n);
    double maxValue = find_max(array, n);
    double sum = minValue + maxValue;

    cout << "\nMinimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;
    cout << "Sum of Min and Max: " << sum << endl;

    return 0;

}
