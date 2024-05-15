#include "Functions_arr.h"
#include <iostream>

using namespace std;

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original integer array: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    swap_elements(intArr, 1, 3);
    cout << "Array after swapping elements at index 1 and 3: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "Index of element with value 3: " << find_element(intArr, 3, intSize) << endl;

    swap_pairs(intArr, intSize);
    cout << "Array after swapping adjacent pairs: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    return 0;
}
