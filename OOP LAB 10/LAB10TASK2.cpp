#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string line = "ElectricVehicle,EV202,VoltZ,2022,Battery:150,CERT-ECO";

    stringstream ss(line);
    string type, id, model, year, extra1, extra2;

    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, model, ',');
    getline(ss, year, ',');
    getline(ss, extra1, ',');
    getline(ss, extra2, ',');

    cout << "Type: " << type << endl;
    cout << "ID: " << id << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Extra1: " << extra1 << endl;
    cout << "Extra2: " << extra2 << endl;

    return 0;
}
