#include"Flight.h"

Flight::Flight() {
	Airline = "Not Available ";
	PlaneType = "Not Available ";
	TotalSeats = 0;
	FlightNumber = "Not Available ";
	DepartureCity = "Not Available ";
	ArrivalCity = "Not Available ";
	DepartureTime = Time();
	ArrivalTime = Time();
}

Flight::Flight(string Airline, string PlaneType, int TotalSeats, string FlightNumber, string DepartureCity, string ArrivalCity) {
	Set_Airline(Airline);
	Set_PlaneType(PlaneType);
	Set_TotalSeats(TotalSeats);
	Set_FlightNumber(FlightNumber);
	Set_DepartureCity(DepartureCity);
	Set_ArrivalCity(ArrivalCity);
}

Flight::Flight(string Airline, string PlaneType, int TotalSeats, string FlightNumber, string DepartureCity, string ArrivalCity, Time DepartureTime, Time ArrivalTime) {

	Set_Airline(Airline);
	Set_PlaneType(PlaneType);
	Set_TotalSeats(TotalSeats);
	Set_FlightNumber(FlightNumber);
	Set_DepartureCity(DepartureCity);
	Set_ArrivalCity(ArrivalCity);
	this->DepartureTime = DepartureTime;
	this->ArrivalTime = ArrivalTime;
}

Flight& Flight::Set_Airline(const string& Airline) {
	this->Airline = Airline;
	return *this;
}

Flight& Flight::Set_PlaneType(string PlaneType) {
	this->PlaneType = PlaneType;
	return *this;
}

Flight& Flight::Set_TotalSeats(int TotalSeats) {
	this->TotalSeats = TotalSeats;
	return *this;
}

Flight& Flight::Set_FlightNumber(string FlightNumber) {
	this->FlightNumber = FlightNumber;
	return *this;
}

Flight& Flight::Set_DepartureCity(string DepartureCity) {
	this->DepartureCity = DepartureCity;
	return *this;
}

Flight& Flight::Set_ArrivalCity(string ArrivalCity) {
	this->ArrivalCity = ArrivalCity;
	return *this;
}

Flight& Flight::Set_DepartureTime(int Hour, int Minute, int Second) {
	Time T(Hour, Minute, Second);
	this->DepartureTime = T;
	return *this;
}

Flight& Flight::Set_ArrivalTime(int Hour, int Minute, int Second) {
	Time T(Hour, Minute, Second);
	this->ArrivalTime = T;
	return *this;
}

Flight& Flight::Set_Passengers(Passengers P) {
	this->Passenger = P;
	return *this;
}

string Flight::Get_Airline() {
	return Airline;
}

string Flight::Get_PlaneType() {
	return PlaneType;
}

int Flight::Get_TotalSeats() {
	return TotalSeats;
}

int Flight::Get_AvailableSeats() {

	if (Passenger.Get_TotalPassengers() <= TotalSeats) {
		return TotalSeats - Passenger.Get_TotalPassengers();
	}

	else {
		throw invalid_argument("The Plane Total Seats are Fewer than the Total Passengers");
	}
}

string Flight::Get_FlightNumber() {
	return FlightNumber;
}

string Flight::Get_DepartureCity() {
	return DepartureCity;
}

string Flight::Get_ArrivalCity() {
	return ArrivalCity;
}

Time Flight::Get_DepartureTime() {
	return DepartureTime;
}

Time Flight::Get_ArrivalTime() {
	return ArrivalTime;
}

string Flight::Get_PassengersList() {
	return Passenger.Display_PassengersList();
}

string Flight::Display_Flight() {
	ostringstream output;
	output << "Airline: " << Airline << endl;
	output << "Plane Type: " << PlaneType << endl;
	output << "Total Seats: " << TotalSeats << endl;
	output << "Available Seats: " << Get_AvailableSeats() << endl;
	output << "FlighT Number: " << FlightNumber << endl;
	output << "Departure City: " << DepartureCity << endl;
	output << "Departure Time: " << DepartureTime.Display_Time();
	output << "Arrival City: " << ArrivalCity << endl;
	output << "ArrivaL Time: " << ArrivalTime.Display_Time();
	output << "Passengers List: \n" << Passenger.Display_PassengersList();
	return output.str();
}

istream& operator>>(istream& input, Flight& F) {
	int Hour, Minute, Second;

	cout << "Enter the Arline Name: ";
	getline(input, F.Airline);

	cout << "Enter the Plane Type: ";
	getline(input, F.PlaneType);

	cout << "Enter the Flight Number: ";
	getline(input, F.FlightNumber);

	cout << "Enter the City of Departure: ";
	getline(input, F.DepartureCity);

	cout << "Enter the Arrival City: ";
	getline(input, F.ArrivalCity);

	cout << "Enter the Total Seats of the Plane: ";
	input >> F.TotalSeats;

	cout << "Enter the Departure Time (HH:MM:SS): ";
	input >> Hour;
	input.ignore(1, ':');
	input >> Minute;
	input.ignore(1, ':');
	input >> Second;
	F.Set_DepartureTime(Hour, Minute, Second);

	cout << "Enter the Arrival Time (HH:MM:SS): ";
	input >> Hour;
	input.ignore(1, ':');
	input >> Minute;
	input.ignore(1, ':');
	input >> Second;
	F.Set_ArrivalTime(Hour, Minute, Second); cout << endl; 

	return input;
}