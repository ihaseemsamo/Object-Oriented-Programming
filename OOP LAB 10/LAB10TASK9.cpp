#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("large_log.txt");

    if (!infile) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    char buffer[11]; 
    infile.read(buffer, 10);
    buffer[infile.gcount()] = '\0'; 

    cout << "First read (10 characters): " << buffer << endl;
    cout << "Position after first read: " << infile.tellg() << endl;

    infile.read(buffer, 10);
    buffer[infile.gcount()] = '\0';

    cout << "Second read (next 10 characters): " << buffer << endl;
    cout << "Position after second read: " << infile.tellg() << endl;

    infile.close();
    return 0;
}
