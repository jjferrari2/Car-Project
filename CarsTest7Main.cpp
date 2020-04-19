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
void export_Cars(int*, Car* *cars, int*);

int main()
	{
		int size = 100;
		int count = 0;
		Car *cars[size];
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
				export_Cars(size, &*cars, count);
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

void import_Cars(int* size, Car* *cars, int* count){
	string strLine;
		int intLine, lineNumber;
		int linesRead = 0;
		double dLine;
		string vehicleType, vehicleMake, vehicleModel, driveTrain, material, hybrid, selfDrive, wifi, infotainment;
		int vehicleYear, engineCylinders, vehicleSeats, transmissionGears, towing, weight;
		double milesPerGallon, vehiclePrice, accel, tire, bed, trunk;
		ifstream carlist;
		carlist.open("Car-List.txt");
		for(int i = 0; i < 4; i++){
			lineNumber = 1;
			for(int j = 0; j < 13; j++){
				if(lineNumber == 2){
					carlist >> strLine;
					vehicleType = strLine;
					cout << vehicleType << endl;
				}
				else if(lineNumber == 1){
					carlist >> strLine;
					vehicleMake = strLine;
					cout << vehicleMake << endl;
				}
				else if(lineNumber == 3){
					carlist >> strLine;
					vehicleModel = strLine;
					cout << vehicleModel << endl;
				}
				else if(lineNumber == 4){
					carlist >> intLine;
					vehicleYear = intLine;
					cout << vehicleYear << endl;
				}
				else if(lineNumber == 5){
					carlist >> intLine;
					engineCylinders = intLine;
					cout << engineCylinders << endl;
				}
				else if(lineNumber == 6){
					carlist >> intLine;
					vehicleSeats = intLine;
					cout << vehicleSeats << endl;
				}
				else if(lineNumber == 7){
					carlist >> intLine;
					transmissionGears = intLine;
					cout << transmissionGears << endl;
				}
				else if(lineNumber == 8){
					carlist >> dLine;
					milesPerGallon = dLine;
					cout << milesPerGallon << endl;
				}
				else if(lineNumber == 9){
					carlist >> dLine;
					vehiclePrice = dLine;
					cout << vehiclePrice << endl;
				}
				else if(lineNumber == 10){
					if(vehicleType == "Truck"){
						carlist >> intLine;
						tire = intLine;
						cout << tire << endl;
					}
					else if(vehicleType == "Performance"){
						carlist >> dLine;
						accel = dLine;
						cout << accel << endl;
					}
					else if(vehicleType == "Sedan"){
						carlist >> strLine;
						material = strLine;
						cout << material << endl;
					}
					else if(vehicleType == "Luxury"){
						carlist >> strLine;
						selfDrive = strLine;
						cout << selfDrive << endl;
					}
				}	
				else if(lineNumber == 11){
					if(vehicleType == "Truck"){
						carlist >> intLine;
						towing = intLine;
						cout << towing << endl;
					}
					else if(vehicleType == "Performance"){
						carlist >> intLine;
						weight = intLine;
						cout << weight << endl;
					}
					else if(vehicleType == "Sedan"){
						carlist >> strLine;
						hybrid = strLine;
						cout << hybrid << endl;
					}
					else if(vehicleType == "Luxury"){
						carlist >> strLine;
						wifi = strLine;
						cout << wifi << endl;
					}
				}
				else if(lineNumber == 12){
					if(vehicleType == "Truck"){
						carlist >> dLine;
						bed = dLine;
						cout << bed << endl;
					}
					else if(vehicleType == "Performance"){
						carlist >> strLine;
						driveTrain = strLine;
						cout << driveTrain << endl;
					}
					else if(vehicleType == "Sedan"){
						carlist >> dLine;
						trunk = dLine;
						cout << trunk << endl;
					}
					else if(vehicleType == "Luxury"){
						carlist >> strLine;
						infotainment = strLine;
						cout << infotainment << endl;
					}
					lineNumber++;
				}
				linesRead++;}
				if(vehicleType == "Truck"){
					cout << "Truck Chosen\n";
						cars[i] = new Truck(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, tire, towing, bed);
					}
				else if(vehicleType == "Performance"){
					cout << "Performance Chosen\n";
						cars[i] = new Performance(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, accel, weight, driveTrain);
					}
				else if(vehicleType == "Sedan"){
					cout << "Sedan Chosen\n";
						cars[i] = new Sedan(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, material, hybrid, trunk);
					}
				else if(vehicleType == "Luxury"){
					cout << "Luxury Chosen\n";
						cars[i] = new Luxury(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, selfDrive, wifi, infotainment);
					}
					*count++;
				}
}


/*void add_Cars(int* size, Car* *cars, int* count){
	
}*/

int add_Cars(int* size, Car* *cars, int* count)
	{
		int selection, i = 0, arrayPos = 0;
		string make, model, driveTrain, seat, hybrid, selfDrive, WiFi, infotainment;
		int year, cylinders, seats, gears, tire, towing, weight;
		double mpg, price, bed, accel, trunk;
		
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
					cin		>> make;
					cout	<< "Enter Model: ";
					cin 	>> model;
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
					
					for(i; i < *count; i++)
						{
							arrayPos++;
						}
						
					cars[arrayPos] = new Truck("Truck", make, model, year, cylinders, seats, gears, mpg, price, tire, towing, bed);
					*count++;
					
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
					cin		>> make;
					cout	<< "Enter Model: ";
					cin 	>> model;
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
					cin		>> driveTrain;
					
					for(i; i < *count; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Performance("Performance", make, model, year, cylinders, seats, gears, mpg, price, accel, weight, driveTrain);
					*count++;
					
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
					cin		>> make;
					cout	<< "Enter Model: ";
					cin 	>> model;
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
					cin		>> seat;
					cout	<< "Is this a Hybrid Vehicle? (Yes/No): ";
					cin		>> hybrid;
					cout	<< "Enter Trunk Capacity: ";
					cin		>> trunk;
					
					for(i; i < *count; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Sedan("Sedan", make, model, year, cylinders, seats, gears, mpg, price, seat, hybrid, trunk);
					*count++;
					
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
					cin		>> make;
					cout	<< "Enter Model: ";
					cin 	>> model;
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
					cin		>> selfDrive;
					cout	<< "Does this car have Wi-Fi Connectivity? (Yes/No): ";
					cin		>> WiFi;
					cout	<< "Enter Infotainment System: ";
					cin		>> infotainment;
					
					for(i; i < *count; i++)
						{
							arrayPos++;
						}	
							
					cars[arrayPos] = new Luxury("Luxury", make, model, year, cylinders, seats, gears, mpg, price, selfDrive, WiFi, infotainment);
					*count++;
					
					system("PAUSE");
					system("CLS");
					break;
				}
		}
		return *count;
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

void export_Cars(int* size, Car* *cars, int* count){
	ofstream carlist;
		carlist.open("Car-List.txt");
		string sdata;
		int idata;
		double ddata;
		string type;
		for(int i=0;i<4;i++){
			sdata = cars[i] -> getVehicleMake();
			carlist << sdata;
			carlist << "\n";
			sdata = cars[i] -> getVehicleType();
			type  = cars[i] -> getVehicleType();
			carlist << sdata;
			carlist << "\n";
			sdata = cars[i] -> getVehicleModel();
			carlist << sdata;
			carlist << "\n";
			idata = cars[i] -> getVehicleYear();
			carlist << idata;
			carlist << "\n";
			idata = cars[i] -> getEngineCylinders();
			carlist << idata;
			carlist << "\n";
			idata = cars[i] -> getVehicleSeats();
			carlist << idata;
			carlist << "\n";
			idata = cars[i] -> getTransmissionGears();
			carlist << idata;
			carlist << "\n";
			ddata = cars[i] -> getMilesPerGallon();
			carlist << ddata;
			carlist << "\n";
			ddata = cars[i] -> getVehiclePrice();
			carlist << ddata;
			carlist << "\n";
			if(type == "Truck"){
				ddata = cars[0] -> getTruckVar1();
				carlist << ddata;
				carlist << "\n";
				idata = cars[0] -> getTruckVar2();
				carlist << idata;
				carlist << "\n";
				ddata = cars[0] -> getTruckVar3();
				carlist << ddata;
				carlist << "\n";
			}
			else if(type == "Performance"){
				ddata = cars[1] -> getPerformanceVar1();
				carlist << ddata;
				carlist << "\n";
				idata = cars[1] -> getPerformanceVar2();
				carlist << idata;
				carlist << "\n";
				sdata = cars[1] -> getPerformanceVar3();
				carlist << sdata;
				carlist << "\n";
			}
			else if(type == "Sedan"){
				sdata = cars[2] -> getSedanVar1();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[2] -> getSedanVar2();
				carlist << sdata;
				carlist << "\n";
				ddata = cars[2] -> getSedanVar3();
				carlist << sdata;
				carlist << "\n";
			}
			else if(type == "Luxury"){
				sdata = cars[3] -> getLuxuryVar1();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[3] -> getLuxuryVar2();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[3] -> getLuxuryVar3();
				carlist << sdata;
				carlist << "\n";
			}
		}
		carlist.close();
}









	
