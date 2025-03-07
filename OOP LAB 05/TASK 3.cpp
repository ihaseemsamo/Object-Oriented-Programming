#include <iostream>
using namespace std;

class Employee {
public:
    string empName;
    int empID;
    string designation;

    Employee(string name, int ID, string desig) : empName(name), empID(ID), designation(desig) {}

    void display() const {
        cout << "Employee ID: " << empID << endl 
             << "Employee Name: " << empName << endl
             << "Designation: " << designation << endl;
    }
};

class Project {
private:
    string ProjectTitle;
    string deadline;
    Employee* employees[10];
    int empCount;

public:
    Project(string title, string dueDate) : ProjectTitle(title), deadline(dueDate), empCount(0) {}

    void addEmployee(Employee* employee) {
        if (empCount < 10) {
            employees[empCount++] = employee;
        }
    }

    void display() const {
        cout << "Project Title: " << ProjectTitle << endl
             << "Deadline: " << deadline << endl
             << "Assigned Employees:\n";
        for (int i = 0; i < empCount; i++) {
            employees[i]->display();
            cout << "-----------------------\n";
        }
        cout << endl;
    }
};

int main() {
    Employee e1("Ahmed", 1, "Developer");
    Employee e2("Haseem", 2, "Manager");
    Employee e3("Saad", 3, "Developer");
    
    Project p1("AI Project", "2025-06-01");
    Project p2("CyberSecurity Project", "2025-06-01");
    Project p3("Data Science", "2025-06-01");
    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    p2.addEmployee(&e1);
    p2.addEmployee(&e2);
    p3.addEmployee(&e3);
	p2.addEmployee(&e3); 
    
    cout << "Project Details:\n";
    p1.display();
    p2.display();
    p3.display();
    
    return 0;
}
