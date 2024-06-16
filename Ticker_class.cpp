#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "bus.h"
#include "date.h"
using namespace std;



class Ticket {
public:
	Ticket(const string& passengerName, int seatNumber, const string& source, const string& destination, const Bus& bus, Date date): passengerName(passengerName), seatNumber(seatNumber), source(source),destination(destination), bus(bus), date(date)
	{
	}

	string getPassengerName() const
	{
		return passengerName;
	}
	int getSeatNumber() const { return seatNumber; }
	string getsource() const { return source; }
	string getdestination() const { return destination; }
	const Bus& getBus() const { return bus; }
	int get_date(){  return date.getDay(); }
    int get_month(){ return date.getMonth(); }
    int get_year(){ return date.getYear(); }
private:
	string passengerName;
	Date date;
	int seatNumber;
	string source;
	string destination;
	Bus bus;
};
