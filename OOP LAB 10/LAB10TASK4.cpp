#include <iostream>
#include <string>
using namespace std;

int main() {
    string type = "ElectricVehicle"; 
    string extraData = "Battery:150,CERT-ECO";  

    if (type == "AutonomousCar") {
        size_t commaPos = extraData.find(',');
        if (commaPos != string::npos) {
            string softwareVersion = extraData.substr(0, commaPos);
            cout << "Software Version: " << softwareVersion << endl;
        } else {
            cout << "Format error in AutonomousCar extraData." << endl;
        }
    }
    else if (type == "ElectricVehicle") {
        size_t colonPos = extraData.find(':');
        size_t commaPos = extraData.find(',');

        if (colonPos != string::npos && commaPos != string::npos) {
            string batteryStr = extraData.substr(colonPos + 1, commaPos - colonPos - 1);
            int batteryCapacity = stoi(batteryStr);
            cout << "Battery Capacity: " << batteryCapacity << endl;
        } else {
            cout << "Format error in ElectricVehicle extraData." << endl;
        }
    }
    else {
        cout << "Unknown vehicle type." << endl;
    }

    return 0;
}
