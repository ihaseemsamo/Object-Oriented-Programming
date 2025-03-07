#include <iostream>
#include <string>
using namespace std;

class Person {
	protected:
	    string name;
	    int age;
	
	public:
	    Person(string pName, int pAge) {
	        name = pName;
	        age = pAge;
	    }
	
	    void displayDetails() {
	        cout << "Name: " << name << endl;
	        cout << "Age: " << age << endl;
	    }
};

class Teacher : virtual public Person {
	protected:
	    string subject;
	
	public:
	    Teacher(string pName, int pAge, string tSubject)
	        : Person(pName, pAge) {
	        subject = tSubject;
	    }
	
	    void displayDetails() {
	        cout << "Subject: " << subject << endl;
	    }
};

class Researcher : virtual public Person {
	protected:
	    string researchArea;
	
	public:
	    Researcher(string pName, int pAge, string rArea)
	        : Person(pName, pAge) {
	        researchArea = rArea;
	    }
	
	    void displayDetails() {
	        cout << "Research Area: " << researchArea << endl;
	    }
};

class Professor : public Teacher, public Researcher {
	private:
	int publications;
	
	public:
	Professor(string pName, int pAge, string tSubject, string rArea, int pPublications)
	    : Person(pName, pAge), Teacher(pName, pAge, tSubject), Researcher(pName, pAge, rArea) {
	    publications = pPublications;
	}
	
	void displayDetails() {
	    Person::displayDetails();
	    Teacher::displayDetails();
	    Researcher::displayDetails();
	    cout << "Publications: " << publications << endl;
	}
};

int main() {
    string name, subject, researchArea;
    int age, publications;

    cout << "Enter professor's name: ";
    getline(cin, name);
    cout << "Enter professor's age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter subject expertise: ";
    getline(cin, subject);
    cout << "Enter research area: ";
    getline(cin, researchArea);
    cout << "Enter number of publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);

    cout << "\nProfessor Details:\n";
    prof.displayDetails();

    return 0;
}
