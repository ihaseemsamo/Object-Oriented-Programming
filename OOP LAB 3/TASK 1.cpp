#include<iostream>
#include<cstring>

using namespace std;

class Wallet{
	string ownerName;
	double totalAmount;
	string transactionHistory[100];
	int count;
	float balance;
	
	public:
		Wallet(){
			totalAmount = 0;
			balance = 0;
		}
		Wallet(string Name, double amount, float Balance){
			ownerName = Name;
			totalAmount = amount;
			count = 0;
			if(Balance > 0){
				balance = Balance;
			}else {
				balance = 0;
			}
		}
	
		void addMoney(double amount){
			if(amount > 0){
				totalAmount += amount;
				cout<<"Amount has been added successfully." <<endl;
				if (count < 100){
					transactionHistory[count] = "Deposited: "+ to_string(amount);
					count++;
				}
			}else {
				cout<< "Please Enter a valid Amount."<<endl;
			}
			notify();
		}
		
		void spendMoney(double amount) {
			if (totalAmount >= amount) {
				totalAmount -= amount;
				cout << "Amount has been withdrawn successfully." << endl;
				if (count < 100) {
					transactionHistory[count] = "Withdrawn: " + to_string(amount);
					count++;
				}
			} else {
				cout << "Not Enough Money" << endl;
			}
			notify();
		}
		
		void display() {
			cout << "Transaction History: " << endl << endl;
			for (int i = 0; i < count; i++) {
				cout << transactionHistory[i] << endl;
			}
		}
		
		void notify() {
			if (totalAmount < balance) {
				cout << "Amount is Less than " <<balance<< endl;
			}
		}

};

int main() {
	
	Wallet myWallet("Haseem", 5000,500);
	
	myWallet.addMoney(2000);
	
	myWallet.spendMoney(3500);
	
	myWallet.display();

	return 0;
}
