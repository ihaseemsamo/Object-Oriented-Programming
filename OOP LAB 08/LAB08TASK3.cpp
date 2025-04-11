#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& a, const Vector2D& b);

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

double dotProduct(const Vector2D& a, const Vector2D& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2.5;
    double dot = dotProduct(v1, v2);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled v1 (x2.5): " << scaled << endl;
    cout << "Dot Product of v1 and v2: " << dot << endl;

    return 0;
}

