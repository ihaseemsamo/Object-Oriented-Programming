#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    char* name;
    int* scores;
    int num_scores;

public:
    Student(int id, const char* name, int scores[], int num_scores) : id(id), num_scores(num_scores) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->scores = new int[num_scores];
        for (int i = 0; i < num_scores; i++) {
            this->scores[i] = scores[i];
        }
    }

    Student(const Student& other) : id(other.id), num_scores(other.num_scores) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        scores = new int[num_scores];
        for (int i = 0; i < num_scores; i++) {
            scores[i] = other.scores[i];
        }
    }

    void display() {
        cout << "Student ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < num_scores; i++) {
            cout << scores[i] << " ";
        }
        cout << "\n\n";
    }

    ~Student() {
        delete[] name;
        delete[] scores;
    }
};

int main() {
    int scores[] = {85, 90, 78};
    Student s1(1, "Ali", scores, 3);
    Student s2 = s1;
    
    cout << "Original Student:\n";
    s1.display();

    cout << "Copied Student:\n";
    s2.display();

    return 0;
}

