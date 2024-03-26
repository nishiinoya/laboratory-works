#include <iostream>
using namespace std;

int main() {
    int num[] = {5, 3, 8, 1, 6, 7, 2, 4, -2};
    int n = sizeof(num) / sizeof(num[0]);

    int odd[n], even[n];
    int n_odd = 0, n_even = 0;


    for (int i = 0; i < n; ++i) {
        if (num[i] % 2 == 0) {
            even[n_even++] = num[i];
        } else {
            odd[n_odd++] = num[i];
        }
    }

    // Bubble sort for odd elements in ascending order
    for (int p = 0; p < n_even - 1; ++p) {
        for (int k = 0; p < n_even - k - 1; ++k) {
            if (odd[k] > odd[k + 1]) {
                // Swap the elements
                int temp = odd[k];
                odd[k] = odd[k + 1];
                odd[k + 1] = temp;
            }
        }
    }

    // Bubble sort for even elements in descending order
    for (int p = 0; p < n_even - 1; ++p) {
        for (int k = 0; p < n_even - k - 1; ++k) {
            if (even[k] < even[k + 1]) {
                // Swap the elements
                int temp = even[k];
                even[k] = even[k + 1];
                even[k + 1] = temp;
            }
        }
    }

    // Print sorted odd array
    cout << "Sorted odd array: ";
    for (int i = 0; i < n_odd; ++i) {
        cout << odd[i] << " ";
    }
    cout << endl;

    // Print sorted even array
    cout << "Sorted even array: ";
    for (int i = 0; i < n_even; ++i) {
        cout << even[i] << " ";
    }
    cout << endl;

    return 0;
}