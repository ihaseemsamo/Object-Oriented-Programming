#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual double calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual double applyDiscount() {
        return 0; 
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << "\nProduct Name: " << productName
             << "\nPrice: $" << price << "\nStock: " << stockQuantity << "\n";
    }
};

class Electronics : public Product {
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string b)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " years\nBrand: " << brand << "\n";
    }
};

class Clothing : public Product {
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string f)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(f) {}

    double applyDiscount() override {
        return price * 0.10; 
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Size: " << size << "\nColor: " << color
             << "\nFabric Material: " << fabricMaterial << "\n";
    }
};

class FoodItem : public Product {
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string expDate, int cal)
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        double total = Product::calculateTotalPrice(quantity);
        if (quantity > 10)
            total *= 0.90; 
        return total;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Expiration Date: " << expirationDate
             << "\nCalories: " << calories << " kcal\n";
    }
};

int main() {
    Electronics laptop(101, "Laptop", 1200, 5, 2, "Dell");
    Clothing tshirt(102, "T-Shirt", 20, 50, "L", "Blue", "Cotton");
    FoodItem apple(103, "Apple", 2, 100, "2025-01-01", 95);

    cout << "\nProduct Details:\n";
    laptop.displayProductInfo();
    cout << "\n";
    tshirt.displayProductInfo();
    cout << "Discount: $" << tshirt.applyDiscount() << "\n\n";
    apple.displayProductInfo();
    cout << "Total Price for 15 apples: $" << apple.calculateTotalPrice(15) << "\n";
    
    return 0;
}

