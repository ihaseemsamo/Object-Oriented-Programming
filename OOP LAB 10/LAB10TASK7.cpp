#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream sensorFile("sensor_log.txt");

    if (!sensorFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string data[] = {
        "Temperature: 25.3 C\n",
        "Humidity: 60%\n",
        "Pressure: 101.3 kPa\n"
    };

    for (const string& line : data) {
        sensorFile << line;
        streampos pos = sensorFile.tellp();
        cout << "Current write position: " << pos << endl;
    }

    sensorFile.close();

    return 0;
}
