#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array2D {
private:
    T **data;
    int numRows;
    int numCols;

public:
    Array2D(int rows, int cols) : numRows(rows), numCols(cols) {
        data = new T *[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    ~Array2D() {
        for (int i = 0; i < numRows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

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

