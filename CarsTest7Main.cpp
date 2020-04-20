#include <string>
#include <iostream>
#include <fstream>
#include "Cars.h"
#include "CarTypes.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------
int menu();
void menu_Selection(int*, Car* *cars, int*);
void import_Cars(int*, Car* *cars, int*);
int add_Cars(int*, Car* *cars, int*);
void view_Cars(int*, Car* *cars, int*);
void search_Cars(int*, Car* *cars, int*);

int main()
	{
		int size = 100;
		int count = 0;
	
		Car *cars[size];
		cars[0] = new Truck("Truck", "Toyota", "Tacoma", 2020, 6, 5, 6, 18.8, 36599, 33.5, 6800, 6.5);
		count++;
		cars[1] = new Performance("Performance", "Porsche", "911", 2020, 6, 2, 8, 20.5, 85999, 3.5, 2700, "RWD");
		count++;		
		cars[2] = new Sedan("Sedan", "Toyota", "Avalon", 2020, 4, 5, 8, 32.5, 29689, "Cloth", "No", 23);	
		count++;		
		cars[3] = new Luxury("Luxury", "Lexus", "LX 570", 2020, 8, 8, 8, 13.5, 92775, "No", "Yes", "CarPlay");
		count++;		
		/*            
		string data;
		for(int i=0;i<100;i++){
			data = cars[i] -> getVehicleType();
			cout << "Vehicle type: " << data;
	}
		*/
		ofstream carlist;
		carlist.open("Car-List.txt");
		string data;
		//data = cars[1] -> getVehicleType();
		//carlist << data;
		/*
		for(int i=0;i<4;i++){
			data = cars[i] -> getVehicleMake();
			carlist << data;
			data = cars[i] -> getVehicleType();
			carlist << data;
			data = cars[i] -> getVehicleModel();
			carlist << data;
			data = cars[i] -> getVehicleYear();
			carlist << data;
			data = cars[i] -> getEngineCylinders();
			carlist << data;
			data = cars[i] -> getVehicleSeats();
			carlist << data;
			data = cars[i] -> getTransmissionGears();
			carlist << data;
			data = cars[i] -> getVehicleType();
			carlist << data;
			data = cars[i] -> getVehiclePrice();
			carlist << data;
			
			carlist << "\n";
		}
		
		carlist.close();
		*/
			
		//Get Car Price (Can be used for looking up by budget)
		//cout << "First Car's price is: " << cars[0] -> getPrice() << endl;
		
		//Get Car Type (Can be used for searching by car type)
		//cout << "First Car's type is: " << cars[0] -> getVehicleType() << endl;
		
		
		//int count = 4;
		//int size = 100;
		//Car *cars[size];
		menu_Selection(&size, &*cars, &count);
		return 0;
	}
	
	
int menu(){
	int choice;
	cout << "Menu\n"
		 << "------------------\n"
		 << "1. Add Cars\n"
		 << "2. View All Cars\n"
		 << "3. Search For Cars\n"
		 << "4. Quit\n"
		 << "Choose An Option: ";
	cin >> choice;
	return choice;
}
		
void menu_Selection(int* size, Car* *cars, int* count){
	int choice;
	do{
		choice = menu();
		switch(choice){
			case 1: {
				system("CLS");
				*count = add_Cars(size, &*cars, count);
				system("CLS");
				break;
			}
			case 2: {
				view_Cars(size, &*cars, count);
				system("PAUSE");
				system("CLS");
				break;
			}
			case 3: {
				search_Cars(size, &*cars, count);
				system("CLS");
				break;
			}
			case 4: {
				system("CLS");
				cout << "\nGoodbye!\n";
				system("PAUSE");
				break;
			}
			default: {
				cout << "Invalid Choice.\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}
	}while(choice != 4);
}	

void import_Cars(){
	
}

/*void add_Cars(int* size, Car* *cars, int* count){
	
}*/

int add_Cars(int* size, Car* *cars, int* count)
	{
		int selection, i = 0, arrayPos = 0;
		
		string make, model, driveTrain, seat, hybrid, selfDrive, WiFi, infotainment;
		
		int year, cylinders, seats, gears, tire, towing, weight;
		
		double mpg, price, bed, accel, trunk;
		
		int addCarPos = *count;
		
		cout	<< "Add New Car to System" << endl
				<< "---------------------------------------" << endl
				<< "1. Truck" << endl
				<< "2. Performance" << endl
				<< "3. Sedan" << endl
				<< "4. Luxury" << endl << endl
				<< "Enter your choice: " << endl;
		cin		>> selection;
		
		switch(selection){
			case 1:
				{
					system("CLS");
					
					cout	<< "Add New Truck" << endl
							<< "---------------------------------------" << endl
							<< "Enter Make: ";
					std::getline(std::cin >> std::ws, make);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Model: ";
					std::getline(std::cin >> std::ws, model);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout 	<< "Enter Year: ";
					cin		>> year;
					cout	<< "Enter Engine Cylinders: ";
					cin		>> cylinders;
					cout	<< "Enter Number of Seats: ";
					cin		>> seats;
					cout	<< "Enter Transmission Gears: ";
					cin		>> gears;
					cout	<< "Enter MPG: ";
					cin		>> mpg;
					cout	<< "Enter Price: $";
					cin		>> price;
					cout	<< "Enter Tire Size: ";
					cin		>> tire;
					cout	<< "Enter Towing Capacity: ";
					cin		>> towing;
					cout	<< "Enter Bed Length: ";
					cin		>> bed;
					
					for(i; i < addCarPos; i++)
						{
							arrayPos++;
						}
						
					cars[arrayPos] = new Truck("Truck", make, model, year, cylinders, seats, gears, mpg, price, tire, towing, bed);
					addCarPos++;
					
					system("PAUSE");
					system("CLS");
					break;
				}
				
			case 2:
				{
					system("CLS");
					
					cout	<< "Add New Performance Car" << endl
							<< "---------------------------------------" << endl
							<< "Enter Make: ";
					std::getline(std::cin >> std::ws, make);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Model: ";
					std::getline(std::cin >> std::ws, model);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout 	<< "Enter Year: ";
					cin		>> year;
					cout	<< "Enter Engine Cylinders: ";
					cin		>> cylinders;
					cout	<< "Enter Number of Seats: ";
					cin		>> seats;
					cout	<< "Enter Transmission Gears: ";
					cin		>> gears;
					cout	<< "Enter MPG: ";
					cin		>> mpg;
					cout	<< "Enter Price: $";
					cin		>> price;
					cout	<< "Enter 0-60 Time: ";
					cin		>> accel;
					cout	<< "Enter Curb Weight: ";
					cin		>> weight;
					cout	<< "Enter Drivetrain Type (FWD/RWD/AWD): ";
					std::getline(std::cin >> std::ws, driveTrain);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					
					for(i; i < addCarPos; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Performance("Performance", make, model, year, cylinders, seats, gears, mpg, price, accel, weight, driveTrain);
					addCarPos++;
					
					system("PAUSE");
					system("CLS");
					break;
				}
			
			case 3:
				{
					system("CLS");
					
					cout	<< "Add New Sedan" << endl
							<< "---------------------------------------" << endl
							<< "Enter Make: ";
					std::getline(std::cin >> std::ws, make);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Model: ";
					std::getline(std::cin >> std::ws, model);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout 	<< "Enter Year: ";
					cin		>> year;
					cout	<< "Enter Engine Cylinders: ";
					cin		>> cylinders;
					cout	<< "Enter Number of Seats: ";
					cin		>> seats;
					cout	<< "Enter Transmission Gears: ";
					cin		>> gears;
					cout	<< "Enter MPG: ";
					cin		>> mpg;
					cout	<< "Enter Price: $";
					cin		>> price;
					cout	<< "Enter Seat Material: ";
					std::getline(std::cin >> std::ws, seat);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Is this a Hybrid Vehicle? (Yes/No): ";
					std::getline(std::cin >> std::ws, hybrid);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Trunk Capacity: ";
					cin		>> trunk;
					
					for(i; i < addCarPos; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Sedan("Sedan", make, model, year, cylinders, seats, gears, mpg, price, seat, hybrid, trunk);
					addCarPos++;
					
					system("PAUSE");
					system("CLS");
					break;
				}
			case 4:
				{
					system("CLS");
					
					cout	<< "Add New Luxury Car" << endl
							<< "---------------------------------------" << endl
							<< "Enter Make: ";
					std::getline(std::cin >> std::ws, make);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Model: ";
					std::getline(std::cin >> std::ws, model);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout 	<< "Enter Year: ";
					cin		>> year;
					cout	<< "Enter Engine Cylinders: ";
					cin		>> cylinders;
					cout	<< "Enter Number of Seats: ";
					cin		>> seats;
					cout	<< "Enter Transmission Gears: ";
					cin		>> gears;
					cout	<< "Enter MPG: ";
					cin		>> mpg;
					cout	<< "Enter Price: $";
					cin		>> price;
					cout	<< "Does this car have Self Driving? (Yes/No): ";
					std::getline(std::cin >> std::ws, selfDrive);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Does this car have Wi-Fi Connectivity? (Yes/No): ";
					std::getline(std::cin >> std::ws, WiFi);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					cout	<< "Enter Infotainment System: ";
					std::getline(std::cin >> std::ws, infotainment);
					//https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
					
					for(i; i < addCarPos; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Luxury("Luxury", make, model, year, cylinders, seats, gears, mpg, price, selfDrive, WiFi, infotainment);
					addCarPos++;
					
					system("PAUSE");
					system("CLS");
					break;
				}
		}
		return addCarPos;
	}

void view_Cars(int* size, Car* *cars, int* count){
	system("CLS");
	for(int i = 0; i < *count; i++)
			{
				cars[i] -> printInfo();
				cout << endl;
			}
}

void search_Cars(int* size, Car* *cars, int* count){
		system("Cls");
		string inputs;
		double inputd;
		int choice;
		
		do{
		cout << "\t\tSearch Menu\n"
		 << "\t\t------------------\n"
		 << "\t\t1. View Cars equal to or less than Budget\n"
		 << "\t\t2. View Cars by Type\n"
		 << "\t\t3. View Cars by Name\n"
		 << "\t\t4. View Cars by Brand\n"
		 << "\t\t5. View Cars by equal to or less than Entered Model Year \n"
		 << "\t\t6. View Cars by equal to or less than Entered MPG\n"
		 << "\t\t7. Quit\n"
		 << "\t\tChoose An Option: ";	
		 
		cin>>choice;
		switch(choice){
			case 1: {
			cout << "Enter budget in dollars"<<endl;
			cin>>inputd;
			for(int i = 0; i < *count; i++){
				if((inputd)>=cars[i]->getVehiclePrice()){
						cars[i] -> printInfo();
						cout<<endl;
						//system("pause");
						//system("cls");
				}
			}
			system("pause");
			system("cls");				
				break;
			}
			case 2: {
			cout << "Enter car Type"<<endl;
			cin>>inputs;
			for(int i = 0; i < *count; i++){
				if((inputs)==cars[i]->getVehicleType()){
					cars[i] -> printInfo();
					
					
				}
			}					
				break;
			}
			system("pause");
			system("cls");	
			case 3: {
		cout << "Enter car Name"<<endl;
					cin>>inputs;
			for(int i = 0; i < *count; i++){
				if((inputs)==cars[i]->getVehicleModel()){
					cars[i] -> printInfo();
					cout<<endl;
				}
			}	
				break;
			}
			case 4: {
		cout << "Enter car Brand"<<endl;				
					cin>>inputs;
		for(int i = 0; i < *count; i++){
			if((inputs)==cars[i]->getVehicleMake()){
					cars[i] -> printInfo();
					cout<<endl;
					
					
			}
		}	
				break;
			}
			case 5: {
		cout << "Enter car Model Year"<<endl;				
						cin>>inputd;
		for(int i = 0; i < *count; i++){
			if((inputd)>=cars[i]->getVehicleYear()){
					cars[i] -> printInfo();
					cout<<endl;
			}
		}	
				system("PAUSE");
				system("CLS");
				break;
			}
			case 6: {
		cout << "Enter car MPG"<<endl;				
						cin>>inputd;
		for(int i = 0; i < *count; i++){
			if((inputd)>=cars[i]->getMilesPerGallon()){
					cars[i] -> printInfo();
					cout<<endl;
			}
		}
				system("PAUSE");
				system("CLS");
				break;
			}
			case 7: {
				
				cout << "\nGoodbye!\n";
				break;
			}
			default: {
				cout << "Invalid Choice.\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}
	}while(choice != 7);		
}











	
