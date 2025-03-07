#include <iostream>
using namespace std;

class Device {
	protected:
	    int deviceID;
	    bool status;
	
	public:
	    Device(int id, bool stat) {
	        deviceID = id;
	        status = stat;
	    }
	
	    virtual void displayDetails() {
	        cout << "Device ID: " << deviceID << endl;
	        cout << "Status: " << (status ? "On" : "Off") << endl;
	    }
};

class SmartPhone : virtual public Device {
	protected:
	    float screenSize;
	
	public:
	    SmartPhone(int id, bool stat, float screen)
	        : Device(id, stat) {
	        screenSize = screen;
	    }
	
	    void displayDetails() override {
	        Device::displayDetails();
	        cout << "Screen Size: " << screenSize << " inches" << endl;
	    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool stat, bool hrm)
        : Device(id, stat) {
        heartRateMonitor = hrm;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
protected:
    int stepCounter;

public:
    SmartWearable(int id, bool stat, float screen, bool hrm, int steps)
        : Device(id, stat), SmartPhone(id, stat, screen), SmartWatch(id, stat, hrm) {
        stepCounter = steps;
    }

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int id, steps;
    bool status, hrm;
    float screenSize;

    cout << "Enter Smart Wearable details:\n";
    cout << "Device ID: ";
    cin >> id;
    cout << "Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Yes, 0 for No): ";
    cin >> hrm;
    cout << "Step Counter: ";
    cin >> steps;

    SmartWearable wearable(id, status, screenSize, hrm, steps);

    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();

    return 0;
}

