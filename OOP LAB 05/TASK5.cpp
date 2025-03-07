#include <iostream>
using namespace std;

class Doctor {
	private:
    	string name;
    	string specialization;
    	int experience;

	public:
    	Doctor(string n, string spec, int exp) : name(n), specialization(spec), experience(exp) {}

    	void display() const {
        	cout << "Doctor Name: " << name << "\nSpecialization: " << specialization << "\nExperience: " << experience << " years\n";
    	}
};

class Hospital {
	private:
    	string hospitalName;
    	Doctor* doctors[10];
    	int doctorCount;

	public:
	    Hospital(string name) : hospitalName(name), doctorCount(0) {}
	
	    void addDoctor(Doctor* doctor) {
	        if (doctorCount < 10) {
	            doctors[doctorCount++] = doctor;
	        }
	    }
	
	    void display() const {
	        cout << "Hospital: " << hospitalName << "\nDoctors:\n";
	        for (int i = 0; i < doctorCount; i++) {
	            doctors[i]->display();
	            cout << "-----------------------\n";
	        }
	    }
};

int main() {
    Doctor d1("Dr. Haseem", "Cardiology", 15);
    Doctor d2("Dr. Saad", "Neurology", 10);
    Doctor d3("Dr. Ali", "Neurology", 10);
    
    Hospital h1("City Hospital");
    Hospital h2("Main Hospital");
    
    h1.addDoctor(&d1);
    h1.addDoctor(&d2);
    h2.addDoctor(&d1);
    h2.addDoctor(&d3);
    
    cout << "Hospital Details:\n";
    h1.display();
    h2.display();
    
    return 0;
}

