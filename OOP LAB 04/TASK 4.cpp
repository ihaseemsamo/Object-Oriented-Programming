#include<iostream>
#include<string>
using namespace std;

class Car{
	string brand;
	string model;
	double price;
	bool availabilityStatus;
	double totalRevenue;
	
	public:
		Car (string b, string m,double p,bool a){
			brand=b;
			model=m;
			price=p;
			availabilityStatus=a;
			totalRevenue=0.0;
		}
		
		bool checkAvailability(){
			return availabilityStatus;
		}
		
		void rentACar(int rentalDays){
			if (availabilityStatus == true){
				double rentalAmount  = price * rentalDays;
				totalRevenue +=rentalAmount; 
				
				availabilityStatus = false;
				
				cout << "Car rented for "<< rentalDays << " days. Revenue generated: $" << rentalAmount<< endl;
				cout << "Total Revenue for this car: $"<< totalRevenue<< endl;
				}else{
					cout << "Sorry, this car is already rented! "<< endl; 
				}
		}
		
		void returnCar(){
			availabilityStatus =true;
			cout<<"Car returned. AVAILABLE FOR RENT"<< endl;
		}
		
		void displayCarDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: $" << price << ", Available: " << (availabilityStatus ? "Yes" : "No") <<", Total Revenue: $"<< totalRevenue<< endl;
    	}
		
		double applyDiscount(int rentalDays){
			double discount = 0.0;
			if(rentalDays > 10){
				discount = 0.10;
			}else if (rentalDays>5){
				discount = 0.05;
			}
			return price - (discount * price);
		}
	};
	
int main(){
	Car c("Bugatti","Chiron",1000,true);
	
	c.displayCarDetails();
	
	c.rentACar(15);
	
	c.displayCarDetails();
	
	c.rentACar(4);
	
	c.displayCarDetails();
	
	c.returnCar();
	
	c.displayCarDetails();
	
	c.rentACar(7);
	
	c.displayCarDetails();
	
	c.returnCar();
	return 0;
	
}	




