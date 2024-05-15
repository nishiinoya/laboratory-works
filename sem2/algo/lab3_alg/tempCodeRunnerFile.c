#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int fibonacciSearch(int arr[], int n, int key) {
    int fib2 = 0;         
    int fib1 = 1;    
    int fib = fib1 + fib2; // kth Fibonacci number

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        // Check if fib2 is a valid location
        int i = min(offset + fib2, n - 1);

        // If greater, cut the subarray from offset to i
        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }

        // If less, cut the subarray after index fib2
        else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }

        else
            return i;
    }
    if (fib1 && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

int main() {
    const int n = 20; //20 elements 
    int key, i;

    int arr[n];
    printf("Enter %d elements of the sequence :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int index = fibonacciSearch(arr, n, key);
    if (index != -1)
        printf("Element %d found at index %d.\n", key, index);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
