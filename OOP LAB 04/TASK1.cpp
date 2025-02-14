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
				cout<< "CAR IS RENTED"<<endl;
				availabilityStatus=false;
				
			}else{
				cout<< "CAR IS NOT AVAILABLE"<<endl;
			}
		}
};

int main(){
	
	Car c;
	
	c.rentACar("haseem");
	c.setAvailability(false);
	c.rentACar("muzammil");
	c.setAvailability(true);
	c.rentACar("ALI");
}
