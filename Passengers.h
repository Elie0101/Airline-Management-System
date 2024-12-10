#ifndef PASSENGERS_H
#define PASSENGERS_H
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
using namespace std;

struct PassengerName {

private:

	string FirstName;
	string LastName;

public:

	PassengerName();
	PassengerName(string, string);

	PassengerName& Set_FirstName(string);
	PassengerName& Set_LastName(string);

	string Get_FirstName() const;
	string Get_LastName() const;

	string Display_PassengerName() const;

	bool operator<(const PassengerName& other) const;

};

class Passengers {

	friend istream& operator>>(istream&, Passengers&);

private:

	set <PassengerName> PassengersList;
	map<PassengerName, int> Duplicate;
	int TotalPassengers;

public:

	Passengers();

	Passengers& Add_Passengers(PassengerName);
	bool Remove_Passengers(const PassengerName);
	int Get_TotalPassengers();
	bool Get_DuplicatedNames();

	string Display_PassengersList();

};

#endif


