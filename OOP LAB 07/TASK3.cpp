#include <iostream>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Reserving ticket for " << passengerName << " to " << destination << " on " << date << ".\n";
    }

    virtual void cancel() {
        cout << "Cancelling ticket ID: " << ticketID << ".\n";
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << " | Passenger: " << passengerName
             << " | Date: " << date << " | Destination: " << destination << " | Price: $" << price << endl;
    }
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    int flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, int flightNo, string sClass)
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flightNo), seatClass(sClass) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << " | Flight No: " << flightNumber << " | Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    int trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, int tNumber, string coach, string depTime)
        : Ticket(id, name, p, d, dest), trainNumber(tNumber), coachType(coach), departureTime(depTime) {}

    void reserve() override {
        cout << "Auto-assigning seat in " << coachType << " for Train No: " << trainNumber << ".\n";
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, int seatNo)
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seatNo) {}

    void cancel() override {
        cout << "Allowing last-minute refund for Bus Company: " << busCompany << " | Seat: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string sType)
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(sType) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Concert Artist: " << artistName << " | Venue: " << venue << " | Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket ft(101, "Ali", 250.50, "2025-05-10", "New York", "Delta Airlines", 456, "Business");
    TrainTicket tt(202, "Ahmed", 80.75, "2025-06-15", "Chicago", 789, "First Class", "10:30 AM");
    BusTicket bt(303, "Aliza", 45.25, "2025-07-20", "Los Angeles", "Greyhound", 15);
    ConcertTicket ct(404, "Bilal", 120.00, "2025-08-30", "Madison Square Garden", "The Weeknd", "VIP", "Front Row");

    cout << "\n---- Ticket Details ----\n";
    ft.displayTicketInfo();
    tt.reserve();
    bt.cancel();
    ct.displayTicketInfo();

    return 0;
}

