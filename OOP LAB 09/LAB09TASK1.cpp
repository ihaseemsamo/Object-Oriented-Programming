#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;
    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "InPatient Treatment for " << name << " (ID: " << id << "):" << endl;
        cout << "- Admitted to ward\n- Monitored daily by doctor\n- Given medications and meals" << endl;
    }

    double calculateCost() const override {
        return 5000.00;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "OutPatient Treatment for " << name << " (ID: " << id << "):" << endl;
        cout << "- Visited doctor for consultation\n- Prescribed medications" << endl;
    }

    double calculateCost() const override {
        return 1500.00;
    }
};

int main() {
    InPatient inPatient("Alice", "IP101");
    OutPatient outPatient("Bob", "OP202");

    Patient* patients[2];

    patients[0] = &inPatient;
    patients[1] = &outPatient;

    for (int i = 0; i < 2; ++i) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << "\n" << endl;
    }

    return 0;
}

