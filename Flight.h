#ifndef FLIGHT_H
#define FLIGHT_H

#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>
#include<iomanip>
#include"Passengers.h"
using namespace std;

struct Time {

private:

	int Hour;
	int Minute;
	int Second;

public:

	Time() {
		Hour = 00;
		Minute = 00;
		Second = 00;
	}

	Time(int Hour, int Minute, int Second) {
		Set_Hour(Hour);
		Set_Minute(Minute);
		Set_Second(Second);
	}

	Time& Set_Hour(int Hour) {
		if (Hour >= 0 && Hour < 24) {
			this->Hour = Hour;
			return *this;
		}

		else {
			throw invalid_argument("Hour must be between 0 and 23");
		}
	}

	Time& Set_Minute(int Minute) {
		if (Minute >= 0 && Minute < 60) {
			this->Minute = Minute;
			return *this;
		}

		else {
			throw invalid_argument("Minute must be between 0 and 59");
		}
	}

	Time& Set_Second(int Second) {
		if (Second >= 0 && Second < 60) {
			this->Second = Second;
			return *this;
		}
		else {
			throw invalid_argument("Seconde must be between 0 and 59");
		}

	}

	string Display_Time() {
		ostringstream output;
		output << setw(2) << setfill('0') << ((Hour == 0 || Hour == 12) ? 12 : Hour % 12) << ":" << setw(2) << setfill('0') << Minute << ":" << setw(2) << setfill('0') << Second << ((Hour >= 12) ? " PM " : " AM ") << endl;
		return output.str();
	}

};

class Flight {

	friend istream& operator>>(istream&, Flight&);

private:

	string Airline;
	string PlaneType;
	int TotalSeats;
	string FlightNumber;
	string DepartureCity;
	string ArrivalCity;
	Time DepartureTime;
	Time ArrivalTime;
	Passengers Passenger;

public:

	Flight();
	Flight(string, string, int, string, string, string);
	Flight(string, string, int, string, string, string, Time, Time);

	Flight& Set_Airline(const string&);
	Flight& Set_PlaneType(string);
	Flight& Set_TotalSeats(int);
	Flight& Set_FlightNumber(string);
	Flight& Set_DepartureCity(string);
	Flight& Set_ArrivalCity(string);
	Flight& Set_DepartureTime(int, int, int);
	Flight& Set_ArrivalTime(int, int, int);
	Flight& Set_Passengers(Passengers);

	string Get_Airline();
	string Get_PlaneType();
	int Get_TotalSeats();
	int Get_AvailableSeats();
	string Get_FlightNumber();
	string Get_DepartureCity();
	string Get_ArrivalCity();
	Time Get_DepartureTime();
	Time Get_ArrivalTime();
	string Get_PassengersList();

	string Display_Flight();
};

#endif