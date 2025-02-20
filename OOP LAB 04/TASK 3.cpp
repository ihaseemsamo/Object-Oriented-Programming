#include<iostream>
#include<string>
using namespace std;

class Car{
	string brand;
	string model;
	double price;
	bool availabilityStatus;
	
	public:
		Car (string b, string m,double p,bool a){
			brand=b;
			model=m;
			price=p;
			availabilityStatus=a;
		}
		
		Car (const Car& car1){
			brand = car1.brand;
			model = car1.model;
			price = car1.price;
			availabilityStatus = car1.availabilityStatus;
		}
		
		~Car() {
        cout << "Car " << brand << " " << model << " is being destroyed." << endl;
    	}
		
		bool checkAvailibilityStatus(){
			return availabilityStatus;
		}	
		
		void rentACar(string name){
			if (availabilityStatus==true){
				cout<< "CAR IS AVAILABLE AND RENTED TO "<< name <<endl;
				availabilityStatus=false;
			}else{
				cout<< "CAR IS ALREADY RENTED"<<endl;
			}
		}
		
		void displayCarDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: $" << price << ", Available: " << (availabilityStatus ? "Yes" : "No") << endl;
    	}
};

int main(){
	Car c("Bugatti","Chiron",10000,true);
	c.displayCarDetails();
	
	Car car1 = c;
	car1.displayCarDetails();

	c.rentACar("ALI");
	c.displayCarDetails();
	
	car1.displayCarDetails();
	
	Car car2 = car1;
	
	return 0;
}
		
	
