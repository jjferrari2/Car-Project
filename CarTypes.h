#include <string>
#include <iostream>
#include "Cars.h"
using namespace std;

#ifndef CARTYPES_H
#define CARTYPES_H

class Truck: public Car
	{	
		public:        
			Truck();        
			//~Truck();
			Truck(string, string, string, int, int, int, int, double, double, int, int, double);
			void setTruck(int, int, double);
			void printInfo();
		
		private:
			int tireSize, towingCapacity;
			double bedSize;
	};

Truck::Truck(string type, string make, string model, int year, int cylinders, int seats, int gears, double mpg, double price,
int tire, int towing, double bed)
	{
		setInfo(type, make, model, year, cylinders, seats, gears, mpg, price);
		setTruck(tire, towing, bed);
	}
	
void Truck::setTruck(int tire, int towing, double bed)
	{
		tireSize = tire;
		towingCapacity = towing;
		bedSize = bed;
	}
	
void Truck::printInfo()
	{
		cout 	<< "Vehicle Type: " << vehicleType << endl
				<< "Vechicle: " << vehicleYear << " " << vehicleMake << " " << vehicleModel << endl
				<< "Price: $" << vehiclePrice << endl
				<< "Cylinders: " << engineCylinders << endl
				<< "Gears: " << transmissionGears << endl
				<< "MPG: " << milesPerGallon << endl
				<< "Seats: " << vehicleSeats << endl
				<< "Tire Size: " << tireSize << "\"" << endl
				<< "Towing Capacity: " << towingCapacity << " Pounds" << endl
				<< "Bed Size: " << bedSize << " Feet" << endl;
	}	
//--------------------------------------------------------------------------------------------------------------------------
class Performance : public Car
	{
		public:
			Performance();
			Performance(string, string, string, int, int, int, int, double, double, double, int, string);
			void setPerformance(double, int, string);
			void printInfo();	
		
		private:
			double acceleration060;
			int curbWeight;
			string driveTrainType;
	};
	
Performance::Performance(string type, string make, string model, int year, int cylinders, int seats, int gears, double mpg,
double price, double accel, int weight, string driveTrain)
	{
		setInfo(type, make, model, year, cylinders, seats, gears, mpg, price);
		setPerformance(accel, weight, driveTrain);
	}
	
void Performance::setPerformance(double accel, int weight, string driveTrain)
	{
		acceleration060 = accel;
		curbWeight = weight;
		driveTrainType = driveTrain;
	}
	
void Performance::printInfo()
	{
		cout 	<< "Vehicle Type: " << vehicleType << endl
				<< "Vechicle: " << vehicleYear << " " << vehicleMake << " " << vehicleModel << endl
				<< "Price: $" << vehiclePrice << endl
				<< "Cylinders: " << engineCylinders << endl
				<< "Gears: " << transmissionGears << endl
				<< "MPG: " << milesPerGallon << endl
				<< "Seats: " << vehicleSeats << endl
				<< "0 - 60 Time: " << acceleration060 << " Seconds" << endl
				<< "Curb Weight: " << curbWeight << " Pounds" << endl
				<< "Drivetrain Type: " << driveTrainType << endl;
	}
//--------------------------------------------------------------------------------------------------------------------------
class Sedan : public Car
	{
		public:
			Sedan();
			Sedan(string, string, string, int, int, int, int, double, double, string, string, double);
			void setSedan(string, string, double);
			void printInfo();
		
		private:
			string seatMaterial, hybridDrive;
			double trunkCapacity;
	};
	
Sedan::Sedan(string type, string make, string model, int year, int cylinders, int seats, int gears, double mpg,
double price, string material, string hybrid, double trunk)
	{
		setInfo(type, make, model, year, cylinders, seats, gears, mpg, price);
		setSedan(material, hybrid, trunk);
	}
	
void Sedan::setSedan(string material, string hybrid, double trunk)
	{
		seatMaterial = material;
		hybridDrive = hybrid;
		trunkCapacity = trunk;
	}
	
void Sedan::printInfo()
	{
		cout 	<< "Vehicle Type: " << vehicleType << endl
				<< "Vechicle: " << vehicleYear << " " << vehicleMake << " " << vehicleModel << endl
				<< "Price: $" << vehiclePrice << endl
				<< "Cylinders: " << engineCylinders << endl
				<< "Gears: " << transmissionGears << endl
				<< "MPG: " << milesPerGallon << endl
				<< "Seats: " << vehicleSeats << endl
				<< "Seat Material: " << seatMaterial << endl
				<< "Hybrid Drive: " << hybridDrive << endl
				<< "Trunk Capacity: " << trunkCapacity << " Cubic Feet" << endl;	
	}
//--------------------------------------------------------------------------------------------------------------------------
class Luxury : public Car
	{
		public:
			Luxury();
			Luxury(string, string, string, int, int, int, int, double, double, string, string, string);
			void setLuxury(string, string, string);
			void printInfo();
		
		private:
			string selfDriving, WiFiConnectivity, infotainmentSystem;
	};
	
Luxury::Luxury(string type, string make, string model, int year, int cylinders, int seats, int gears, double mpg,
double price, string selfDrive, string Wifi, string infotainment)
	{
		setInfo(type, make, model, year, cylinders, seats, gears, mpg, price);
		setLuxury(selfDrive, Wifi, infotainment);	
	}
	
void Luxury::setLuxury(string selfDrive, string WiFi, string infotainment)
	{
		selfDriving = selfDrive;
		WiFiConnectivity = WiFi;
		infotainmentSystem = infotainment;
	}

void Luxury::printInfo()
	{
		cout 	<< "Vehicle Type: " << vehicleType << endl
				<< "Vechicle: " << vehicleYear << " " << vehicleMake << " " << vehicleModel << endl
				<< "Price: $" << vehiclePrice << endl
				<< "Cylinders: " << engineCylinders << endl
				<< "Gears: " << transmissionGears << endl
				<< "MPG: " << milesPerGallon << endl
				<< "Seats: " << vehicleSeats << endl
				<< "Self Driving: " << selfDriving << endl
				<< "Wi-Fi Connectivity: " << WiFiConnectivity << endl
				<< "Infotainment System: " << infotainmentSystem << endl;	
	}
	
#endif
