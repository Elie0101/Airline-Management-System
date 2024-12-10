#include"Trips.h"

Trip::Trip() {};

Trip::Trip(Flight F) {
	Trips.push_back(F);
}

Trip::Trip(string AirLine, string PlaneType, int TotalSeats, string FlightNumber, string DepartureCity, string ArrivalCity, Time DepartureTime, Time ArrivalTime) {
	Flight F(AirLine, PlaneType, TotalSeats, FlightNumber, DepartureCity, ArrivalCity, DepartureTime, ArrivalTime);
	Trips.push_back(F);
}

Trip& Trip::Add_Flight(Flight F) {
	this->Trips.push_back(F);
	return *this;
}

bool Trip::Cancel_Flight(string FlightNumber) {
	list<Flight>::iterator it;

	for (it = Trips.begin(); it != Trips.end(); it++) {
		if ((*it).Get_FlightNumber() == FlightNumber) {
			Trips.erase(it);
			cout << "Flight Number " << FlightNumber << " has been Successfully Deleted. \n\n " << endl;
			return true;
		}
	}

	cout << "Flight Number " << FlightNumber << " is Not Found. " << endl;
	return false;
}

bool Trip::Get_FlightInformation(string FlightNumber) {
	list<Flight>::iterator it;

	for (it = Trips.begin(); it != Trips.end(); it++) {
		if (it->Get_FlightNumber() == FlightNumber) {
			cout << it->Display_Flight();
			return true;
		}
	}

	cout << "Flight Number " << FlightNumber << "is Not Found. " << endl;
	return false;
}

string Trip::Display_Trips() {
	ostringstream output;

	list<Flight>::iterator it;
	for (it = Trips.begin(); it != Trips.end(); it++) {
		output << it->Display_Flight() << endl <<"\n";
	}

	return output.str();
}