#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;

public:
    Device(int id, string name) : deviceID(id), deviceName(name), status(false) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    bool getStatus() { return status; }
    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << "\nDevice Name: " << deviceName << "\nStatus: " << (status ? "On" : "Off") << endl;
    }
};

class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, int brightness, string color)
        : Device(id, name), brightnessLevel(brightness), colorMode(color) {}
    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
private:
    int temperature;
    string mode;
    int targetTemperature;

public:
    Thermostat(int id, string name, int temp, string m, int target)
        : Device(id, name), temperature(temp), mode(m), targetTemperature(target) {}
    void displayInfo() override {
        Device::displayInfo();
        cout << "Temperature: " << temperature << "\nMode: " << mode << "\nTarget Temperature: " << targetTemperature << endl;
    }
};

class SecurityCamera : public Device {
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, int res, bool nightVision)
        : Device(id, name), resolution(res), recordingStatus(false), nightVisionEnabled(nightVision) {}
    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
    }
    void displayInfo() override {
        Device::displayInfo();
        cout << "Resolution: " << resolution << "p\nRecording Status: " << (recordingStatus ? "Recording" : "Not Recording")
             << "\nNight Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << endl;
    }
};

class SmartPlug : public Device {
private:
    int powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, int power, int timer)
        : Device(id, name), powerConsumption(power), timerSetting(timer) {}
    void turnOff() override {
        Device::turnOff();
        cout << "Logging Power Usage: " << powerConsumption << " watts" << endl;
    }
    void displayInfo() override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerConsumption << " watts\nTimer Setting: " << timerSetting << " minutes" << endl;
    }
};

int main() {
    Light light(1, "Living Room Light", 75, "Warm White");
    Thermostat thermostat(2, "Home Thermostat", 22, "Cooling", 24);
    SecurityCamera camera(3, "Front Door Camera", 1080, true);
    SmartPlug plug(4, "Smart Plug", 100, 30);

    light.turnOn();
    thermostat.turnOn();
    camera.turnOn();
    plug.turnOn();

    cout << "\nDevice Details:\n";
    light.displayInfo();
    cout << "\n";
    thermostat.displayInfo();
    cout << "\n";
    camera.displayInfo();
    cout << "\n";
    plug.displayInfo();

    return 0;
}

