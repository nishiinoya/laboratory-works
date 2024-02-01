#include <iostream>

using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int element = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = element;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int n = 6;
    int arr[n] = {64, 25, 12, 22, 11, 1};

    cout << "Original Array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
