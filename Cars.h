#include <string>
#include <iostream>
using namespace std;

#ifndef CARS_H
#define CARS_H

class Car
	{
		public:
			Car();
			//~Car();
			void setInfo(string, string, string, int, int, int, int, double, double);
			virtual void printInfo() = 0;
			double getPrice()
				{
					return vehiclePrice;
				}
			string getVehicleMake();
			string getVehicleType();
			string getVehicleModel();
			int getVehicleYear();
			int getEngineCylinders();
			int getVehicleSeats();
			int getTransmissionGears();
			double getMilesPerGallon();
			double getVehiclePrice();
			double virtual getTruckVar1(){};
			int virtual getTruckVar2(){};
			double virtual getTruckVar3(){};
			double virtual getPerformanceVar1(){};
			int virtual getPerformanceVar2(){};
			string virtual getPerformanceVar3(){};
			string virtual getSedanVar1(){};
			string virtual getSedanVar2(){};
			double virtual getSedanVar3(){};
			string virtual getLuxuryVar1(){};
			string virtual getLuxuryVar2(){};
			string virtual getLuxuryVar3(){};
			
	
		protected:
			string vehicleType, vehicleMake, vehicleModel;
			int vehicleYear, engineCylinders, vehicleSeats, transmissionGears;
			double milesPerGallon, vehiclePrice;
	};

Car::Car()
	{
		setInfo("", "", "", 0, 0, 0, 0, 0.0, 0.0);
	}
	
void Car::setInfo(string type, string make, string model, int year, int cylinders, int seats, int gears, double mpg, double price)
	{
		vehicleType = type;
		vehicleMake = make;
		vehicleModel = model;
		vehicleYear = year;
		engineCylinders = cylinders;
		vehicleSeats = seats;
		transmissionGears = gears;
		milesPerGallon = mpg;
		vehiclePrice = price;
	}
	
string Car::getVehicleType()
	{
		return vehicleType;
	}
string Car::getVehicleMake()
	{
		return vehicleMake;
	}
string Car::getVehicleModel()
	{
		return vehicleModel;
	}
int Car::getVehicleYear()
	{
		return vehicleYear;
	}
int Car::getEngineCylinders()
	{
		return engineCylinders;
	}
int Car::getVehicleSeats()
	{
		return vehicleSeats;
	}
int Car::getTransmissionGears()
	{
		return transmissionGears;
	}
double Car::getMilesPerGallon()
	{
		return milesPerGallon;
	}
double Car::getVehiclePrice()
	{
		return vehiclePrice;
	}
	
#endif
