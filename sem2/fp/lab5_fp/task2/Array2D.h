#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Array2D {
private:
    vector<vector<T>> data;
    int numRows;
    int numCols;

public:
    Array2D(int rows, int cols) : numRows(rows), numCols(cols), data(rows, vector<T>(cols)) {}

    T &operator()(int row, int col) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Index out of range");
        }
        return data[row][col];
    }

    const T &operator()(int row, int col) const {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Index out of range");
        }
        return data[row][col];
    }

    int getNumRows() const {
        return numRows;
    }

    int getNumCols() const {
        return numCols;
    }
};
