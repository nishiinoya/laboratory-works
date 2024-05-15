#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Matrix {
    friend ostream &operator<<(ostream &out, const Matrix &mat);
    friend istream &operator>>(istream &in, Matrix &mat);

private:
    int **data; 
    int rows;  
    int cols; 

public:
    // Nested class for creating an exception object
    class MatrixException {
        std::string message;
    public:
        MatrixException(const std::string &msg) : message(msg) {}
        std::string getMessage() const { return message; }
    };

    Matrix(int rows, int cols);
    Matrix(const Matrix &other);
    ~Matrix();

    int &operator()(int row, int col);
    const int &operator()(int row, int col) const;

    Matrix &operator=(const Matrix &other);
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    void transform_squares();
};

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    // Allocate memory for the 2D array
    data = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
    // Copy constructor
    data = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    // Destructor
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int &Matrix::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw MatrixException("Index out of bounds");
    }
    return data[row][col];
}

const int &Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw MatrixException("Index out of bounds");
    }
    return data[row][col];
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        // Check for self-assignment
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        throw MatrixException("Cannot add matrices of different sizes");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        throw MatrixException("Cannot subtract matrices of different sizes");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
    if (cols != other.rows) {
        throw MatrixException("Cannot multiply matrices with incompatible sizes");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result(i, j) = 0;
            for (int k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

ostream &operator<<(ostream &out, const Matrix &mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            out << mat.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Matrix &mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            in >> mat.data[i][j];
        }
    }
    return in;
}

void Matrix::transform_squares() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] % 2 == 0) {
                data[i][j] *= data[i][j];
            }
        }
    }
}

int main() {
    Matrix A(2, 2);
    cout << "Enter elements for matrix A (2x2): ";
    cin >> A;
    cout << "Matrix A:\n" << A << endl;
    A.transform_squares();
    cout << "Result:\n" << A << endl;

    return 0;
}
