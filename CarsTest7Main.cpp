#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
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
		import_Cars(&size, &*cars, &count);
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
				export_Cars(size, &*cars, count);
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

void import_Cars(int* size, Car* *cars, int* count){
	string line;
	int vehicleNum = 0;
	int carCount = 0;
	int lineCount = 0;
	int lineNumber = 0;
	string vehicleType, vehicleMake, vehicleModel, driveTrain, material, hybrid, selfDrive, wifi, infotainment;
	int vehicleYear, engineCylinders, vehicleSeats, transmissionGears, towing, weight;
	double milesPerGallon, vehiclePrice, accel, tire, bed, trunk;;
	
	string strLine;
	int intLine;
	double dLine;
	
	ifstream file;
	file.open("Car-List.txt");
	while(file >> line){
		 lineCount++;
	};
	*count = lineCount / 12;
	file.close();
	file.open("Car-List.txt");
	int k = 1;
	while(file >> line){
		lineNumber++;
		if(lineNumber == 13){
			carCount++;
			lineNumber = 1;}
		if(lineNumber == 1){
			vehicleMake = line;
		}
		else if(lineNumber == 2){
			vehicleType = line;
		}
		else if(lineNumber == 3){
			strLine = line;
			vehicleModel = strLine;
		}
		else if(lineNumber == 4){
			stringstream m(line);
			m >> vehicleYear;
		}
		else if(lineNumber == 5){
			stringstream m(line);
			m >> engineCylinders;
		}
		else if(lineNumber == 6){
			stringstream m(line);
			m >> vehicleSeats;
		}
		else if(lineNumber == 7){	
			stringstream m(line);
			m >> transmissionGears;
		}
		else if(lineNumber == 8){
			dLine = atof(line.c_str());
			milesPerGallon = dLine;
		}
		else if(lineNumber == 9){
			dLine = atof(line.c_str());
			vehiclePrice = dLine;
		}
		else if(lineNumber == 10){
			if(vehicleType == "Truck"){
				vehicleNum = 1;
				dLine = atof(line.c_str());
				tire = dLine;
			}
			else if(vehicleType == "Performance"){
				vehicleNum = 2;
				dLine = atof(line.c_str());
				accel = dLine;
			}
			else if(vehicleType == "Sedan"){
				vehicleNum = 3;
				strLine = line;
				material = strLine;
			}
			else if(vehicleType == "Luxury"){
				vehicleNum = 4;
				strLine = line;
				selfDrive = strLine;
			}
		}	
		else if(lineNumber == 11){
			if(vehicleType == "Truck"){
				stringstream m(line);
				m >> towing;
			}
			else if(vehicleType == "Performance"){
				stringstream m(line);
				m >> weight;
			}
			else if(vehicleType == "Sedan"){
				strLine = line;
				hybrid = strLine;
			}
			else if(vehicleType == "Luxury"){
				strLine = line;
				wifi = strLine;
			}
		}
		else if(lineNumber == 12){
			if(vehicleType == "Truck"){
				dLine = atof(line.c_str());
				bed = dLine;
			}
			else if(vehicleType == "Performance"){
				strLine = line;
				driveTrain = strLine;
			}
			else if(vehicleType == "Sedan"){
				dLine = atof(line.c_str());
				trunk = dLine;
			}
			else if(vehicleType == "Luxury"){
				strLine = line;
				infotainment = strLine;
			}
		}
	if(vehicleType == "Truck"){
		dLine = atof(line.c_str());
		bed = dLine;
		cars[carCount] = new Truck(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, tire, towing, bed);
	}
	else if(vehicleType == "Performance"){
		strLine = line;
		driveTrain = strLine;
		cars[carCount] = new Performance(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, accel, weight, driveTrain);
	}
	else if(vehicleType == "Sedan"){
		dLine = atof(line.c_str());
		trunk = dLine;
		cars[carCount] = new Sedan(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, material, hybrid, trunk);
	}
	else if(vehicleType == "Luxury"){
		strLine = line;
		infotainment = strLine;
		cars[carCount] = new Luxury(vehicleType, vehicleMake, vehicleModel, vehicleYear, engineCylinders, vehicleSeats, transmissionGears, milesPerGallon, vehiclePrice, selfDrive, wifi, infotainment);
	}}
	file.close();	
}

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


void export_Cars(int* size, Car* *cars, int* count){
	ofstream carlist;
		carlist.open("Car-List.txt");
		string sdata;
		int idata;
		double ddata;
		string type;
		for(int i=0;i<*count;i++){
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
				ddata = cars[i] -> getTruckVar1();
				carlist << ddata;
				carlist << "\n";
				idata = cars[i] -> getTruckVar2();
				carlist << idata;
				carlist << "\n";
				ddata = cars[i] -> getTruckVar3();
				carlist << ddata;
				carlist << "\n";
			}
			else if(type == "Performance"){
				ddata = cars[i] -> getPerformanceVar1();
				carlist << ddata;
				carlist << "\n";
				idata = cars[i] -> getPerformanceVar2();
				carlist << idata;
				carlist << "\n";
				sdata = cars[i] -> getPerformanceVar3();
				carlist << sdata;
				carlist << "\n";
			}
			else if(type == "Sedan"){
				sdata = cars[i] -> getSedanVar1();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[i] -> getSedanVar2();
				carlist << sdata;
				carlist << "\n";
				ddata = cars[i] -> getSedanVar3();
				carlist << sdata;
				carlist << "\n";
			}
			else if(type == "Luxury"){
				sdata = cars[i] -> getLuxuryVar1();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[i] -> getLuxuryVar2();
				carlist << sdata;
				carlist << "\n";
				sdata = cars[i] -> getLuxuryVar3();
				carlist << sdata;
				carlist << "\n";
			}
		}
	carlist.close();
}
