#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{	
	string Destination = "" ;
	string Departure = "";
	int daysStay = 0;
	int hrsStay = 0;
	double ticketPrice = 0;
	int numTicket = 0;
	double rentalCost = 0;
	double foodCost = 0;
	double subtotalCost = 0;
	double totalCost = 0;
	double costPerday = 0;
	double serviceCost = 0;

cout << "Where is your trip destination?" << endl;
	
	getline (cin, Destination);
	
cout << "Travelling to " << Destination << " is fabulous this time of the year!" << endl;
cout << "Where are you departuring from?" << endl;
	
	getline (cin, Departure);
	
cout << Departure << " sounds like a pleasant place to be from!" << endl;
cout << "How many days will you be staying in " << Destination << "? (Number Only)" << endl;

	cin >> daysStay;
	hrsStay = daysStay * 24;

cout << "Wowwwyy! You're staying at " << Destination << " for " << hrsStay;
cout << " hours?!?!" << "Amazing!!" << endl;	
cout << "How much does one ticket to " << Destination << " cost? (Number Only)" << endl;

	cin >> ticketPrice;
	
cout << "How many tickets would you want? (Number Only)" << endl;

	cin >> numTicket;

cout << "Okay, I've got you down for " << numTicket << " tickets to " << Destination;
cout << " at " << ticketPrice << " per ticket. Now we're going places!" << endl;
cout << "How much will rental car cost per day? (Number Only)" << endl;

	cin >> rentalCost;

cout << "Oh wow, " << rentalCost << " is a steal!" << endl;
cout << "How much will you be budgeting for daily food cost?" << endl;

	cin >> foodCost;
	subtotalCost = (ticketPrice * numTicket) + (rentalCost * daysStay) + (foodCost * daysStay);
	serviceCost = pow(subtotalCost, 0.6);
	totalCost = serviceCost + subtotalCost;
	costPerday = totalCost / daysStay;
cout << " Alright. Your trip from " << Departure << " to " << Destination << " will cost you ";
cout << totalCost << " in total or " << costPerday << " per day!" << endl;
return 0;
}
