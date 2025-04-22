#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}

    virtual double estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;

    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}

    double estimateDeliveryTime() override {
        return 1.5 + (weight * 0.1);
    }

    void showDetails() override {
        cout << "Air Freight Shipment\n";
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " days\n\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}

    double estimateDeliveryTime() override {
        return 3.0 + (weight * 0.2);
    }

    void showDetails() override {
        cout << "Ground Shipment\n";
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " days\n\n";
    }
};

int main() {
    AirFreight air("AIR123", 10.5);
    GroundShipment ground("GRD456", 15.0);

    Shipment* shipments[2];
    shipments[0] = &air;
    shipments[1] = &ground;

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
    }

    return 0;
}

