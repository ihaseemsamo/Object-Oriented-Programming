#include <iostream>
#include <string>
using namespace std;

class Vehicle {
	protected:
	    string brand;
	    int speed;
	
	public:
	    Vehicle(string vBrand, int vSpeed) {
	        brand = vBrand;
	        speed = vSpeed;
	    }
	
	    void displayDetails() {
	        cout << "Brand: " << brand << endl;
	        cout << "Speed: " << speed << " km/h" << endl;
	    }
	};

class Car : public Vehicle {
	protected:
	    int seats;
	
	public:
	    Car(string vBrand, int vSpeed, int vSeats)
	        : Vehicle(vBrand, vSpeed) {
	        seats = vSeats;
	    }
	
	    void displayDetails() {
	        Vehicle::displayDetails();
	        cout << "Seats: " << seats << endl;
	    }
};

class ElectricCar : public Car {
	private:
	    int batteryLife;
	
	public:
	    ElectricCar(string vBrand, int vSpeed, int vSeats, int vBatteryLife)
	        : Car(vBrand, vSpeed, vSeats) {
	        batteryLife = vBatteryLife;
	    }
	
	    void displayDetails() {
	        Car::displayDetails();
	        cout << "Battery Life: " << batteryLife << " hours" << endl;
	    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter car brand: ";
    getline(cin, brand);
    cout << "Enter car speed (km/h): ";
    cin >> speed;
    cout << "Enter number of seats: ";
    cin >> seats;
    cout << "Enter battery life (hours): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);

    cout << "\nElectric Car Details:\n";
    eCar.displayDetails();

    return 0;
}

