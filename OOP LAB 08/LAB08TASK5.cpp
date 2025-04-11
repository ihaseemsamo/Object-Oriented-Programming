#include <iostream>
using namespace std;

class MatrixHelper; 

class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0)
        : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            a * other.a + b * other.c, a * other.b + b * other.d,
            c * other.a + d * other.c, c * other.b + d * other.d
        );
    }

    friend int determinant(const Matrix2x2& m);

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& os, const Matrix2x2& m) {
        os << "[ " << m.a << " " << m.b << " ]\n";
        os << "[ " << m.c << " " << m.d << " ]";
        return os;
    }
};

int determinant(const Matrix2x2& m) {
    return m.a * m.d - m.b * m.c;
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int row, int col, int value) {
        if (row == 0 && col == 0) m.a = value;
        else if (row == 0 && col == 1) m.b = value;
        else if (row == 1 && col == 0) m.c = value;
        else if (row == 1 && col == 1) m.d = value;
        else cout << "Invalid index!\n";
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix m1:\n" << m1 << "\n\n";
    cout << "Matrix m2:\n" << m2 << "\n\n";

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Sum:\n" << sum << "\n\n";
    cout << "Difference:\n" << diff << "\n\n";
    cout << "Product:\n" << prod << "\n\n";

    cout << "Determinant of m1: " << determinant(m1) << endl;
    cout << "Determinant of m2: " << determinant(m2) << endl << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 9);
    cout << "Updated m1 (0,0) to 9:\n" << m1 << endl;

    return 0;
}

