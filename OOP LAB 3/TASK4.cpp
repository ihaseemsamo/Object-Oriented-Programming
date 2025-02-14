#include<iostream>
using namespace std;

class Car {
    private:
        string brand;
        string model;
        float fuelCapacity;
        float currentFuelLevel; 
        float fuelEfficiency;
        float minimumFuel;

    public:
        Car() {
            currentFuelLevel = 0;
            fuelCapacity = 0;
            fuelEfficiency = -1;
            minimumFuel = 0;
        }

        Car(string Model, string Brand, float FuelCapacity, float CurrentFuelLevel, float FuelEfficiency, float MinimumFuel) {
            model = Model;
            brand = Brand;
            fuelCapacity = FuelCapacity;
            currentFuelLevel = CurrentFuelLevel;
            fuelEfficiency = FuelEfficiency;
            minimumFuel = MinimumFuel;
        }

        void drive(float distance) {
            float fuelUsed = distance / fuelEfficiency;
            if (currentFuelLevel - fuelUsed > 0) {
                currentFuelLevel -= fuelUsed;
                notify();
            }
        }

        void refuel(float liters) {
            if (currentFuelLevel + liters <= fuelCapacity && liters > 0) {
                currentFuelLevel += liters;
            } else {
                currentFuelLevel = fuelCapacity;
            }
            cout << endl << "Car is fueled with " << liters << " liters." << endl;
            fuelStatus();
        }

        void notify() {
            if (currentFuelLevel < minimumFuel) {
                cout << endl << "You are running out of fuel.";
                fuelStatus();
            }
        }

        void fuelStatus() {
            cout << endl << currentFuelLevel << " liters leftover in the car.";
        }
};

int main() {
    Car car("Honda", "Civic", 1000, 60, 40, 100);
    
    car.drive(800);
    
    car.refuel(40);
    
    car.fuelStatus();
    
    car.notify();

    return 0;
}

