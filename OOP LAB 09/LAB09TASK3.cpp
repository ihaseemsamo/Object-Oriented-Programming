#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}
    virtual void calculateGrade() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Course() {}
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr) : Course(code, cr) {}

    void calculateGrade() const override {
        cout << "Calculating grade for LectureCourse " << courseCode << ": 40% Midterm + 60% Final\n";
    }

    void displayInfo() const override {
        cout << "Lecture Course - Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int cr) : Course(code, cr) {}

    void calculateGrade() const override {
        cout << "Calculating grade for LabCourse " << courseCode << ": 70% Lab Work + 30% Final Exam\n";
    }

    void displayInfo() const override {
        cout << "Lab Course - Code: " << courseCode << ", Credits: " << credits << endl;
    }
};

int main() {
    LectureCourse lec("CS101", 3);
    LabCourse lab("PHY102L", 1);

    Course* courses[2];
    courses[0] = &lec;
    courses[1] = &lab;

    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        cout << endl;
    }

    return 0;
}

