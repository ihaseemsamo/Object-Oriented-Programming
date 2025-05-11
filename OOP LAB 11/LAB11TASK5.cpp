#include <iostream>
#include <exception>
using namespace std;

// Custom exception classes (do not override what())
class NegativeStockException : public exception { };
class OverCapacityException : public exception { };

template <typename T>
class InventoryItem {
    T stock;
    T maxStock;
public:
    InventoryItem(T max) : stock(0), maxStock(max) {}

    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        if (value > maxStock)
            throw OverCapacityException();
        stock = value;
        cout << "Stock set to " << stock << endl;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    InventoryItem<int> item(100); // max stock = 100

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5); // Throws NegativeStockException
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120); // Throws OverCapacityException
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
