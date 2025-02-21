#include<iostream>

using namespace std;

class Employee{
	public: 
	string empName;
	int empID;
	
	Employee(string name,int ID): empName(name), empID(ID){}
	
	void display() const{
	cout<<"Employee ID: "<< empID << endl<< "Employee Name " << empName << endl; 
	} 
};

class Project{
	private: 
	string ProjectName;
	Employee *employee[10];
	int emp;
	
	Employee(string name,int ID): empName(name), empID(ID){}
	
	void display() const{
	cout<<"Employee ID: "<< empID << endl<< "Employee Name " << empName << endl; 
	} 
};
