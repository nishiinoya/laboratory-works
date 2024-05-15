#include <stdio.h>
void heapify(int arr[], int size, int current);
void heapSort(int arr[], int size);
void swap(int *a, int *b);

int main() {
    int arr[] = {1, 45, 33, 56, 27, 17, 20, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);

    printf("Sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// heapify function to build max heap from the array elements
void heapify(int arr[], int size, int current) {
    
    int largest = current;
    // initialize left and right child of the root element
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    // find the largest among root, left and right child
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    // swap the root(current element) with the largest root
    if (current != largest) {
        swap(&arr[current], &arr[largest]);
        // heapify the new root again to get maximum on the top position
        heapify(arr, size, largest);
    }
}
// heap sort function to sort the elements
void heapSort(int arr[], int size) {
    // build the max heap using heapify
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // extract elements from heap and store at last position of heap i.e. arr[0]
    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        // heapify the root element again to get maximum element on top
        heapify(arr, i, 0);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

