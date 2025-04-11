#include <iostream>
#include <string>
using namespace std;

class InventoryManager; 

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
        cout << "Price updated for model: " << car.model << endl;
    }

    void displayCar(const Car& car) {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    cout << "Comparing prices..." << endl;
    if (c1.price > c2.price) {
        cout << c1.model << " is more expensive than " << c2.model << endl;
    } else if (c1.price < c2.price) {
        cout << c2.model << " is more expensive than " << c1.model << endl;
    } else {
        cout << "Both " << c1.model << " and " << c2.model << " are priced equally." << endl;
    }
}

int main() {
    Car car1("Toyota Camry", 25000);
    Car car2("Honda Accord", 24000);

    InventoryManager manager;

    cout << "Initial Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    manager.updatePrice(car2, 26000); 

    cout << "\nUpdated Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    cout << "\nPrice Comparison:\n";
    comparePrice(car1, car2);

    return 0;
}

