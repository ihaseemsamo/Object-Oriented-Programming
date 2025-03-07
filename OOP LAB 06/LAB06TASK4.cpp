#include <iostream>
using namespace std;

class Account {
	protected:
	    int accountNumber;
	    float balance;
	
	public:
	    Account(int accNum, float bal) {
	        accountNumber = accNum;
	        balance = bal;
	    }
	
	    void displayDetails() {
	        cout << "Account Number: " << accountNumber << endl;
	        cout << "Balance: $" << balance << endl;
	    }
};

class SavingsAccount : public Account {
	protected:
	    float interestRate;
	
	public:
	    SavingsAccount(int accNum, float bal, float rate)
	        : Account(accNum, bal) {
	        interestRate = rate;
	    }
	
	    void displayDetails() {
	        Account::displayDetails();
	        cout << "Interest Rate: " << interestRate << "%" << endl;
	    }
};

class CheckingAccount : public Account {
	protected:
	    float overdraftLimit;
	
	public:
	    CheckingAccount(int accNum, float bal, float limit)
	        : Account(accNum, bal) {
	        overdraftLimit = limit;
	    }
	
	    void displayDetails() {
	        Account::displayDetails();
	        cout << "Overdraft Limit: $" << overdraftLimit << endl;
	    }
};

int main() {
    int accNum;
    float balance, interestRate, overdraftLimit;
	int choice;
	cout << "Choose your Account?"<<endl;
	cout << "1. Savings"<<endl;
	cout << "2. Checking"<<endl;
	cin >> choice;
	
	if (choice == 1){
    cout << "Enter Savings Account details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate (%): ";
    cin >> interestRate;
    SavingsAccount savings(accNum, balance, interestRate);
    cout << "\nSavings Account Details:\n";
    savings.displayDetails();
	}
	else if(choice==2){
    cout << "\nEnter Checking Account details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Overdraft Limit: ";
    cin >> overdraftLimit;
    CheckingAccount checking(accNum, balance, overdraftLimit);
	}else{
		cout<<"Invalid Choice";
	}

    return 0;
}
