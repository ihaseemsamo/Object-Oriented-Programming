#include <iostream>
#include <fstream>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[25];
};

int main() {
    InventoryItem itemOut = {1001, "Electric Motor"};
    InventoryItem itemIn;

    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cout << "Cannot open file for writing.\n";
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&itemOut), sizeof(itemOut));
    outFile.close();

    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cout << "Cannot open file for reading.\n";
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemIn), sizeof(itemIn));
    inFile.close();

    cout << "Loaded Item ID: " << itemIn.itemID << endl;
    cout << "Loaded Item Name: " << itemIn.itemName << endl;

    return 0;
}
