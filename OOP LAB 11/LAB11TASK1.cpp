#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
    int rows1, cols1, rows2, cols2;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2)
        : rows1(r1), cols1(c1), rows2(r2), cols2(c2) {}

    const char* what() const noexcept override {
        return "DimensionMismatchException - Matrices must have same dimensions";
    }

    void printDimensions() const {
        cout << "Matrix A (" << rows1 << "x" << cols1 << ") + "
             << "Matrix B (" << rows2 << "x" << cols2 << ")" << endl;
    }
};

template <typename T>
class Matrix {
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    void input() {
        cout << "Enter matrix (" << rows << "x" << cols << ") values:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);
        A.input();
        B.input();
        Matrix<int> C = A + B;
        C.display();
    } catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;
        e.printDimensions();
    }
    return 0;
}
