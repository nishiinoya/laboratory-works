#pragma once

#include <iostream>
#include <cmath>

using namespace std;
template <typename T> 
void swap_elements(T arr[], int index1, int index2) {
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
template <typename T>
int find_element(T arr[], T element, int size) {
    for (int i = 0; i < size; i++) {
        if( arr[i] == element) {
            return i;
        }
    }
    return -1;
}
template <typename T>
void swap_pairs(T arr[], int size) {
    int i = 0;
    while (i < size - 1) {
        T temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
        i += 2;
    }
}