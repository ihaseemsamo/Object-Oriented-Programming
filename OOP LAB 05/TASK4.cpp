#include <iostream>
using namespace std;

class AlarmSystem {
	private:
    	string securityLevel;

	public:
    	AlarmSystem(string level) : securityLevel(level) {}

    	void display() const {
        	cout << "Alarm Security Level: " << securityLevel << "\n";
    	}
	};

class SmartHome {
	private:
    	string homeName;
    	AlarmSystem* alarm;

	public:
    	SmartHome(string name, string securityLevel) : homeName(name) {
        	alarm = new AlarmSystem(securityLevel);
    	}

    	~SmartHome() {
        	delete alarm;
    	}

    	void display() const {
        	cout << "SmartHome: " << homeName << "\n";
        	alarm->display();
    	}
};

int main() {
    SmartHome home1("Smart Home1", "High");
    SmartHome home2("Smart Home2", "Low");
    cout << "SmartHome Details:\n";
    home1.display();
    home2.display();
    
    return 0;
}

