#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        cout << "Line: " << line << endl;
    }

    file.close();
    return 0;
}
 