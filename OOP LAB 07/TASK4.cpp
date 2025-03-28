#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | Age: " << age << " | Contact: " << contactNumber << " | Address: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddress = "") {
        contactNumber = newContact;
        if (!newAddress.empty()) address = newAddress;
    }
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string contact, int id, string history, string doctor)
        : Person(n, a, contact), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << " | Medical History: " << medicalHistory
             << " | Assigned Doctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string spec, double fee, string patients)
        : Person(n, a, contact), specialization(spec), consultationFee(fee), patientsList(patients) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << " | Consultation Fee: $" << consultationFee
             << " | Patients List: " << patientsList << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift)
        : Person(n, a, contact), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << " | Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string dept, double sal)
        : Person(n, a, contact), department(dept), salary(sal) {}

    void updateInfo(string newContact, double newSalary) {
        Person::updateInfo(newContact);
        salary = newSalary;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << " | Salary: $" << salary << endl;
    }
};

int main() {
    Patient p("John Doe", 30, "123456789", 101, "Diabetes", "Dr. Smith");
    Doctor d("Dr. Smith", 45, "987654321", "Cardiology", 200.00, "John Doe, Alice Brown");
    Nurse n("Emily Clark", 29, "456789123", "ICU", "Night Shift");
    Administrator a("Michael Scott", 50, "741258963", "HR", 75000.00);

    cout << "\n---- Hospital Information ----\n";
    p.displayInfo();
    d.displayInfo();
    n.displayInfo();
    a.displayInfo();

    return 0;
}

