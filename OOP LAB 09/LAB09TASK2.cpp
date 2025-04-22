#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double cost) : dishName(name), price(cost) {}
    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;
    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() const override {
        cout << "Appetizer: " << dishName << "\nPrice: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation steps:\n- Light cooking or no cooking\n- Quick seasoning and serving\n" << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() const override {
        cout << "Main Course: " << dishName << "\nPrice: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation steps:\n- Full cooking process\n- Served hot with sides\n" << endl;
    }
};

int main() {
    Appetizer appetizer("Bruschetta", 6.99);
    MainCourse mainCourse("Grilled Chicken", 14.99);

    MenuItem* menu[2];
    menu[0] = &appetizer;
    menu[1] = &mainCourse;

    for (int i = 0; i < 2; ++i) {
        menu[i]->showDetails();
        menu[i]->prepare();
    }

    return 0;
}

