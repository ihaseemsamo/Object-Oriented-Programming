#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception {
    // No override of what()
    // Value is not included in what() as required
};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < -273.15) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9 / 5) + 32;
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        double result = convertToFahrenheit(-300.0); // will throw
        cout << "Fahrenheit: " << result << endl;
    } catch (const InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
