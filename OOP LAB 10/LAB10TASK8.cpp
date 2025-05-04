#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("config.txt");
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    outFile << "AAAAABBBBBCCCCC";  
    outFile.close();

    fstream configFile("config.txt", ios::in | ios::out);
    if (!configFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    configFile.seekp(5);  

    configFile << "XXXXX";

    configFile.close();

    ifstream verifyFile("config.txt");
    string content;
    getline(verifyFile, content);
    cout << "Updated file content: " << content << endl;

    verifyFile.close();
    return 0;
}
