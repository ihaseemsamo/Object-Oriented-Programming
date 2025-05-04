#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "HybridTruck";
    string extraData = "Cargo:80|Battery:75";

    if (type == "HybridTruck") {
        size_t colon1 = extraData.find(':');
        size_t pipe = extraData.find('|');
        size_t colon2 = extraData.rfind(':');

        if (colon1 != string::npos && pipe != string::npos && colon2 != string::npos) {
            string cargoStr = extraData.substr(colon1 + 1, pipe - colon1 - 1);
            string batteryStr = extraData.substr(colon2 + 1);

            int cargo = stoi(cargoStr);
            int battery = stoi(batteryStr);

            cout << "Cargo Capacity: " << cargo << endl;
            cout << "Battery Capacity: " << battery << endl;
        } else {
            cout << "Error parsing HybridTruck extra data.\n";
        }
    } else {
        cout << "Vehicle type not handled.\n";
    }

    return 0;
}
