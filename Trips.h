#ifndef TRIPS_H
#define TRIPS_H
#include<list>
#include"Flight.h"

class Trip {

private:

	list<Flight> Trips;

public:

	Trip();
	Trip(Flight);
	Trip(string, string, int, string, string, string, Time, Time);

	Trip& Add_Flight(Flight);
	bool Cancel_Flight(string);
	bool Get_FlightInformation(string);

	string Display_Trips();

};

#endif