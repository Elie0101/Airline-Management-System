#include "Flight.h"
#include "Trips.h"
#include "Passengers.h"
#include <iostream>
using namespace std;

int main() {
    // Initialize the trip and passengers
    Trip T1;
    Passengers P1, P2, P3; 

    // Created predefined passengers
    PassengerName PN1("Rayen", "Saliba");
    PassengerName PN2("Elie", "Moukawam");
    PassengerName PN3("Celina", "Gharib");
    PassengerName PN4("Paul", "Akiki");
    PassengerName PN5("Ramy", "Korban");
    PassengerName PN6("Charbel", "Samaha");
    PassengerName PN7("Celina", "Gharib"); // Duplicate for testing
    PassengerName PN8("Jhon", "salem");

    // Adding predefined passengers to P2
    P2.Add_Passengers(PN1)
        .Add_Passengers(PN2)
        .Add_Passengers(PN3)
        .Add_Passengers(PN4)
        .Add_Passengers(PN5)    
        .Add_Passengers(PN7);

   // Adding predefined passengers to P3
    P3.Add_Passengers(PN6)  
      .Add_Passengers(PN8); 

    // Created flights
    Flight F1("Delta", "A350", 50, "R8V1", "Beirut", "Paris");
    F1.Set_DepartureTime(23, 30, 0);
    F1.Set_ArrivalTime(10, 40, 0);

    Flight F2("MEA", "A320Neo", 100, "R6M2", "Beirut", "Marmaris");
    F2.Set_DepartureTime(4, 40, 0);
    F2.Set_ArrivalTime(5, 50, 40);

    Flight F3("Swiss", "B777", 150, "R8M3", "Beirut", "Dubai");
    F3.Set_DepartureTime(3, 50, 0);
    F3.Set_ArrivalTime(5, 30, 0);

    // for user to Input new passengers  into P1
    cout << "Enter passenger details for Flight 1:" << endl;
    cin >> P1;

    // Assigned passengers to flights
    F1.Set_Passengers(P1);
    F2.Set_Passengers(P2);
    F3.Set_Passengers(P3);

    // Added flights to the trip
    T1.Add_Flight(F1)
        .Add_Flight(F2)
        .Add_Flight(F3);

    // Display all flights in the trip
    cout << "\n=== Current Trip Details ===\n" << endl;
    cout << T1.Display_Trips() << endl;

    // Display duplicated names in P1
    cout << "\n=== Checking for Duplicate Passengers ===\n" << endl;
    cout << "Flight 1: " << P1.Get_DuplicatedNames() << endl;
    cout << "Flight 2: " << P2.Get_DuplicatedNames() << endl;

    // Remove a passenger from P2
    cout << "\n=== Removing a Passenger from Flight 2 ===\n" << endl;
    P2.Remove_Passengers(PN5);
    cout << "Updated Passenger List for Flight 2:" << endl;
    F2.Set_Passengers(P2);
    cout << F2.Get_PassengersList() << endl;

    // Cancel a flight
    cout << "\n=== Canceling a Flight ===\n" << endl;
    T1.Cancel_Flight("R8M3");
    cout << "Updated Trip Details:\n" << endl;
    cout << T1.Display_Trips() << endl;

    // Retrieve flight information
    cout << "\n=== Retrieving Flight Information ===\n" << endl;
    cout << T1.Get_FlightInformation("R8V1") << endl;

    cout << "\nThank you for using the Flight Management System!" << endl;
    return 0;
}
