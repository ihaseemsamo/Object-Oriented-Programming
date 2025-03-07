#include <iostream>
using namespace std;

class Product {
private:
    int productID;
    string productName;
    int quantity;

public:
    Product(int id, string name, int qty) : productID(id), productName(name), quantity(qty) {}

    int getID() const { return productID; }
    string getName() const { return productName; }
    int getQuantity() const { return quantity; }

    void display() const {
        cout << "Product ID: " << productID << "\nName: " << productName << "\nQuantity: " << quantity << "\n";
    }
};

class Inventory {
private:
    Product* products[10];
    int productCount;

public:
    Inventory() : productCount(0) {}

    ~Inventory() {
        for (int i = 0; i < productCount; i++) {
            delete products[i];
        }
    }

    void addProduct(int id, string name, int qty) {
        if (productCount < 10) {
            products[productCount++] = new Product(id, name, qty);
        }
    }

    void searchProduct(int id) const {
        for (int i = 0; i < productCount; i++) {
            if (products[i]->getID() == id) {
                products[i]->display();
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void displayAll() const {
        for (int i = 0; i < productCount; i++) {
            products[i]->display();
            cout << "-----------------------\n";
        }
    }
};

int main() {
    Inventory inventory;
    inventory.addProduct(101, "Laptop", 5);
    inventory.addProduct(102, "Mouse", 20);
    inventory.addProduct(103, "Keyboard", 15);

    cout << "Displaying All Products:\n";
    inventory.displayAll();
    
    cout << "Searching for Product ID 102:\n";
    inventory.searchProduct(102);
    
    return 0;
}

