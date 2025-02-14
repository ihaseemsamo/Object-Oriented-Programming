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
		
		void rentACar(string name){
			if (checkAvailabilityStatus()==true){
				cout<< "CAR IS AVAILABLE"<<endl;
			}else{
				cout<< "CAR IS RENTED"<<endl;
			}
		}
		
		
};

int main(){
	
	Car c("Bugatti","Chiron",10000,false);
	c.rentACar("haseem");
	c.setAvailability(false);
	c.rentACar("muzammil");
	c.setAvailability(true);
	c.rentACar("ALI");
}
