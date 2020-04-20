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
void add_Cars(int*, Car* *cars, int*);
void view_Cars(int*, Car* *cars, int*);
void search_Cars(int*, Car* *cars, int*);

int main()
	{
		int size = 100;
		Car *cars[size];
		//cars[0] = new Truck("Truck", "Toyota", "Tacoma", 2020, 6, 5, 6, 18.8, 36599, 33.5, 6800, 6.5);
		//cars[1] = new Performance("Performance", "Porsche", "911", 2020, 6, 2, 8, 20.5, 85999, 3.5, 2700, "RWD");
		//cars[2] = new Sedan("Sedan", "Toyota", "Avalon", 2020, 4, 5, 8, 32.5, 29689, "Cloth", "No", 23);	
		//cars[3] = new Luxury("Luxury", "Lexus", "LX 570", 2020, 8, 8, 8, 13.5, 92775, "No", "Yes", "CarPlay");
		
		string strLine;
		int intLine, lineNumber;
		int linesRead = 0;
		int count = 4;
		double dLine;
		ifstream reading;
		reading.open("Car-List.txt");
		string lines;
		while(reading >> lines){
			linesRead++;
		}
		count = linesRead / 12;
		string vehicleType, vehicleMake, vehicleModel, driveTrain, material, hybrid, selfDrive, wifi, infotainment;
		int vehicleYear, engineCylinders, vehicleSeats, transmissionGears, towing, weight;
		double milesPerGallon, vehiclePrice, accel, tire, bed, trunk;
		ifstream carlist;
		carlist.open("Car-List.txt");
		for(int i = 0; i < 4; i++){
			lineNumber = 1;
			for(int j = 0; j < 12; j++){
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
					//count++;
				}

		
		/*
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
		*/
		
			
		//Get Car Price (Can be used for looking up by budget)
		//cout << "First Car's price is: " << cars[0] -> getPrice() << endl;
		
		//Get Car Type (Can be used for searching by car type)
		//cout << "First Car's type is: " << cars[0] -> getVehicleType() << endl;
		
		
		//int count = 4;
		//int size = 100;
		//Car *cars[size];
		//import_Cars(&size, &*cars, &count);
		//cout << "Car 1: " << cars[0] -> getVehicleType();
		//import_Cars(&size, &*cars, &count);
		menu_Selection(&size, &*cars, &count);
		return 0;
	}
	
	
int menu(){
	int choice;
	cout << "\t\tMenu\n"
		 << "\t\t------------------\n"
		 << "\t\t1. Add Cars\n"
		 << "\t\t2. View All Cars\n"
		 << "\t\t3. Search For Cars\n"
		 << "\t\t4. Quit\n"
		 << "\t\tChoose An Option: ";
	cin >> choice;
	return choice;
}
		
void menu_Selection(int* size, Car* *cars, int* count){
	int choice;
	do{
		choice = menu();
		switch(choice){
			case 1: {
				add_Cars(size, &*cars, count);
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

		


void add_Cars(int* size, Car* *cars, int* count){
	
}

void view_Cars(int* size, Car* *cars, int* count){
	for(int i = 0; i < *count; i++)
			{
				cars[i] -> printInfo();
				cout << endl;
			}
}

void search_Cars(int* size, Car* *cars, int* count){
	
}







	
