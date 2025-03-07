#include <iostream>
#include <cstring>
using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* owner_name;

public:
    Apartment(int id, string addr, const char* own) : id(id), address(addr) {
        owner_name = new char[strlen(own) + 1];
        strcpy(owner_name, own);
    }

    Apartment(const Apartment& other) : id(other.id), address(other.address) {
        owner_name = new char[strlen(other.owner_name) + 1];
        strcpy(owner_name, other.owner_name);
    }

    void display() {
        cout << "Apartment ID: " << id << "\nAddress: " << address << "\nOwner: " << owner_name << "\n\n";
    }

    ~Apartment() {
        delete[] owner_name;
    }
};

int main() {
    Apartment a1(1, "53/D DHA", "Haseem");
    Apartment a2 = a1;
    
    cout << "Original Apartment:\n";
    a1.display();

    cout << "Copied Apartment:\n";
    a2.display();

    return 0;
}
