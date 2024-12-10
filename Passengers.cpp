#include"Passengers.h"
#include <iostream>


PassengerName::PassengerName() {
	FirstName = "Not Available";
	LastName = "Not Available";
}

PassengerName::PassengerName(string FirstName, string LastName) {
	Set_FirstName(FirstName);
	Set_LastName(LastName);
}

PassengerName& PassengerName::Set_FirstName(string FirstName) {
	this->FirstName = FirstName;
	return*this;
}

PassengerName& PassengerName::Set_LastName(string LastName) {
	this->LastName = LastName;
	return*this;
}

string PassengerName::Get_FirstName() const {
	return FirstName;
}

string PassengerName::Get_LastName() const {
	return LastName;
}

string PassengerName::Display_PassengerName() const {
	ostringstream output;
	output << FirstName << " " << LastName << endl;
	return output.str();
}

bool PassengerName::operator<(const PassengerName& other) const {
	if (FirstName == other.FirstName) {
		return LastName < other.LastName;
	}
	return FirstName < other.FirstName;
}

Passengers::Passengers() {
	TotalPassengers = 0;
}

Passengers& Passengers::Add_Passengers(PassengerName N) {
	pair<set<PassengerName>::iterator, bool> Results = PassengersList.insert(N);

	if (!Results.second) {
		Duplicate[N] += 1;
	}

	else {
		TotalPassengers++;
	}

	return *this;
}

bool Passengers::Remove_Passengers(const PassengerName PN) {
	auto it = PassengersList.find(PN); // Locate the passenger using find

	if (it != PassengersList.end()) {
		// Passenger found
		PassengersList.erase(it);
		TotalPassengers--;

		// Check if it was a duplicate and update the Duplicate map
		auto duplicateIt = Duplicate.find(PN);
		if (duplicateIt != Duplicate.end()) {
			Duplicate[PN]--;
			if (Duplicate[PN] == 0) {
				Duplicate.erase(PN); // Remove if no more duplicates exist
			}
		}

		cout << PN.Get_FirstName() << " " << PN.Get_LastName()
			<< " has been successfully removed from the flight." << endl;

		return true;
	}

	// Passenger not found
	cout << PN.Get_FirstName() << " " << PN.Get_LastName()
		<< " has not been found." << endl;
	return false;
}

int Passengers::Get_TotalPassengers() {
	return TotalPassengers;
}

bool Passengers::Get_DuplicatedNames() {
	if (!Duplicate.empty()) {
		int counter = 1;
		cout << "The duplicated names are:" << endl;
		for (const pair<PassengerName, int> pair : Duplicate) {
			cout << pair.first.Get_FirstName() << " " << pair.first.Get_LastName() << " has been repeated " << pair.second << " times." << endl;
		}
		return true;
	}
	cout << "There are no duplicated names." << endl;
	return false;

}

string Passengers::Display_PassengersList() {
	ostringstream output;

	int Counter = 1;

	for (PassengerName PN : PassengersList) {
		output << "Passenger (" << Counter++ << "): " << PN.Display_PassengerName();
	}

	return output.str();

}

istream& operator>>(istream& input, Passengers& P) {

	PassengerName PN;
	int Counter = 1;
	string FirstName, LastName;

	cout << "Enter the Names of Passengers, and Press Ctrl+Z to Stop. " << endl;
	while (true) {

		cout << "Enter the First Name and the Last Name of Passenger Number (" << Counter << "): ";
		if (!(cin >> FirstName >> LastName)) break;
		PN.Set_FirstName(FirstName).Set_LastName(LastName);
		P.Add_Passengers(PN);
		Counter++;
	}

	return input;
}