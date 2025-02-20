#include<iostream>

using namespace std;

class Car{
	string brand;
	string model;
	double price;
	bool availabilityStatus;
	
	public:
		Car(){
			brand="Unknown";
			model="Generic";
			price= 0.0;
			availabilityStatus = true;
		}
		
		Car (string b, string m,double p,bool a){
			brand=b;
			model=m;
			price=p;
			availabilityStatus=a;
		}
		void setBrand(string Brand){
			brand =Brand;
		}
		
		void setModel(string Model){
			model =Model;
		}
		
		void setPrice(double Price){
			price =Price;
		}
		
		void setAvailability(bool a){
			availabilityStatus = a;
		}
		
		bool checkAvailabilityStatus(){
			return availabilityStatus;
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
		
		void rentACar(string name){
			if (checkAvailabilityStatus()==true){
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
	
	Car c("Bugatti","Chiron",10000,false);
	c.displayCarDetails();
	c.rentACar("haseem");
	c.setAvailability(true);
	c.displayCarDetails();
	c.rentACar("ALI");
	c.setPrice(c.applyDiscount(15));
	c.displayCarDetails();
	c.setAvailability(false);
	c.displayCarDetails();
	c.rentACar("muzammil");
}
