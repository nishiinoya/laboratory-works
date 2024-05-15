#include "Array2D.h"
#include "Fraction.h"
#include <iostream>

using namespace std;

template <typename T>
T findMin(const Array2D<T> &arr) {
    T minVal = arr(0, 0);
    for (int i = 0; i < arr.getNumRows(); ++i) {
        for (int j = 0; j < arr.getNumCols(); ++j) {
            if (arr(i, j) < minVal) {
                minVal = arr(i, j);
            }
        }
    }
    return minVal;
}

template <typename T>
void print_array(const Array2D<T> &arr) {
    for (int i = 0; i < arr.getNumRows(); ++i) {
        for (int j = 0; j < arr.getNumCols(); ++j) {
            cout << arr(i, j) << " ";
        }
        cout << endl;
    }
}

template <typename T>
void arrayEvenSquare(Array2D<T> &arr) {
    for (int i = 0; i < arr.getNumRows(); ++i) {
        for (int j = 0; j < arr.getNumCols(); ++j) {
            if constexpr (std::is_integral_v<T>) { 
                if (arr(i, j) % 2 == 0) {
                    arr(i, j) = arr(i, j) * arr(i, j);
                }
            } else {
                if (static_cast<int>(arr(i, j)) == arr(i, j) && static_cast<int>(arr(i, j)) % 2 == 0) {
                    arr(i, j) = arr(i, j) * arr(i, j);
                }
            }
        }
    }
}

int main() {
    // Array of integers
    Array2D<int> intArray(2, 3);
    intArray(0, 0) = 5;
    intArray(0, 1) = 3;
    intArray(0, 2) = 7;
    intArray(1, 0) = 2;
    intArray(1, 1) = 1;
    intArray(1, 2) = 9;
    cout << "Original integer array:" << endl;
    print_array(intArray);
    arrayEvenSquare(intArray);
    cout << "Array with even values replaced by their squares:" << endl;
    print_array(intArray);
    cout << "Minimum value in the integer array: " << findMin(intArray) << endl;

    Array2D<double> doubleArray(2, 2);
    doubleArray(0, 0) = 3.5;
    doubleArray(0, 1) = 1.2;
    doubleArray(1, 0) = 5.7;
    doubleArray(1, 1) = 2.8;
    cout << "\nOriginal double array:" << endl;
    print_array(doubleArray);
    arrayEvenSquare(doubleArray);
    cout << "Minimum value in the double array: " << findMin(doubleArray) << endl;

    // Array of fractions
    Array2D<Fraction> fractionArray(2, 2);
    fractionArray(0, 0) = Fraction(1, 2);
    fractionArray(0, 1) = Fraction(3, 4);
    fractionArray(1, 0) = Fraction(1, 3);
    fractionArray(1, 1) = Fraction(2, 5);
    cout << "\nOriginal fraction array:" << endl;
    print_array(fractionArray);
    cout << "Minimum value in the fraction array: " << findMin(fractionArray) << endl;

    return 0;
}
