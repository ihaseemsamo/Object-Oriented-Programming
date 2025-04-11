#include <iostream>
using namespace std;

class Manager; 

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << ", Balance: " << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited " << amount << " to account " << acc.accountNumber << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(Account& acc, double amount) {
        if (amount <= acc.balance && amount > 0) {
            acc.balance -= amount;
            cout << "Withdrew " << amount << " from account " << acc.accountNumber << endl;
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred " << amount << " from account " << from.accountNumber
             << " to account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed: insufficient balance or invalid amount.\n";
    }
}

int main() {
    Account acc1(1001, 5000.0);
    Account acc2(1002, 3000.0);

    Manager manager;

    cout << "Initial Account Details:\n";
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    manager.deposit(acc1, 1000.0);
    manager.withdraw(acc2, 500.0);

    transferFunds(acc1, acc2, 2000.0);

    cout << "\nFinal Account Details:\n";
    manager.displayAccount(acc1);
    manager.displayAccount(acc2);

    return 0;
}

