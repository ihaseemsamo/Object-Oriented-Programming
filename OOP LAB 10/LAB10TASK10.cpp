#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("data_records.txt");

    if (!infile) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    infile.seekg(18, ios::beg);

    string line;
    getline(infile, line);

    cout << "Third record: " << line << endl;

    infile.close();
    return 0;
}
