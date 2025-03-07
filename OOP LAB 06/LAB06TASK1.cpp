#include <iostream>
#include <string>
using namespace std;

class Employee {
	protected:
	    string name;
	    float salary;
	
	public:
	    Employee(string empName, float empSalary) {
	        name = empName;
	        salary = empSalary;
	    }
	
	    void displayDetails() {
	        cout << "Name: " << name << endl;
	        cout << "Salary: " << salary << endl;
	    }
};

class Manager : public Employee {
	private:
	    float bonus;
	
	public:
	    Manager(string empName, float empSalary, float empBonus)
	        : Employee(empName, empSalary) {
	        bonus = empBonus;
	    }
	
	    void displayDetails() {
	        Employee::displayDetails();
	        cout << "Bonus: " << bonus << endl;
	    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter manager's name: ";
    getline(cin, name);
    cout << "Enter manager's salary: ";
    cin >> salary;
    cout << "Enter manager's bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);

    cout << "\nManager Details:\n";
    manager.displayDetails();

    return 0;
}

