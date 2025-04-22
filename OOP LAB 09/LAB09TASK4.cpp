#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    float temperature;
public:
    void readData() override {
        temperature = 22.5;
    }

    void displayReport() override {
        cout << "Temperature: " << temperature << " °C" << endl;
    }
};

class Barometer : public WeatherSensor {
private:
    float pressure;
public:
    void readData() override {
        pressure = 1013.25; 
    }

    void displayReport() override {
        cout << "Pressure: " << pressure << " hPa" << endl;
    }
};

int main() {
    Thermometer thermo;
    Barometer baro;

    WeatherSensor* sensors[2];

    sensors[0] = &thermo;
    sensors[1] = &baro;

    for (int i = 0; i < 2; ++i) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    return 0;
}

