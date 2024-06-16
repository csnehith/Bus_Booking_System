#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "route.h"
#include "date.h"
using namespace std;


class Bus {
public:
	Bus( int busNumber, vector<Route> routes,int totalSeats, vector<int> days, Date date, map<string, string> maptimings): busNumber(busNumber), routes(routes), totalSeats(totalSeats), days(days) ,date(date), maptimings(maptimings)
	{
		seats.reserve(totalSeats);
		for (int i = 1; i <= totalSeats; ++i) {
			seats.push_back(false);
		}
	}

	bool reserveSeat(int seatNumber)
	{
		if (seatNumber >= 1 && seatNumber <= totalSeats&& !seats[seatNumber - 1]) {
			seats[seatNumber - 1] = true;
			return true;
		}
		return false;
	}

	int getTotalSeats() const { return totalSeats; }

	bool cancelSeat(int seatNumber)
	{
		if (seatNumber >= 1 && seatNumber <= totalSeats&& seats[seatNumber - 1]) {
            seats[seatNumber - 1] = false;
			return true;
		}
		return false;
	}

	void dipalybusAvailability()
	{
	    cout << "\n\t\t\tBus Number: " << busNumber << endl;
	    cout<< "\t\t\tStart time: "<<arrivaltime(routes[0].getSource())<<endl;
		cout << "\t\t\tRoute:\n";
		for(int i=0;i<routes.size();i++){
            Route x = routes[i];
            cout<<"\t\t\t";
            cout<< x.getNumber() << " ("
             << x.getSource() << " to "
             << x.getDestination() << ") "
             << "Arrival Time: "<<arrivaltime(x.getDestination()) <<endl;
		}
		int seats_color=0;
		for(int i=0;i<seats.size();i++){
            if(seats[i]==true){
                seats_color++;
            }
		}
		seats_color = (100*seats_color)/totalSeats ;
		cout<<"\t\t\tSeat Availability:";
		if(seats_color <= 60){
            cout<<" GREEN ";
		}
		else if(seats_color <=90){
            cout<<" YELLOW ";
		}
		else{
            cout<<" RED ";
		}
		cout<<endl;
	}

	void displayBusInfo()
	{
		cout << "\n\t\t\tBus Number: " << busNumber << endl;
		cout<< "\t\t\tStart time: "<<arrivaltime(routes[0].getSource())<<endl;
		cout << "\t\t\tRoute:\n";
		for(int i=0;i<routes.size();i++){
            cout<<"\t\t\t";
            Route x = routes[i];
            cout<< x.getNumber() << " ("
             << x.getSource() << " to "
             << x.getDestination() << ") "
             << "Arrival Time: "<<arrivaltime(x.getDestination()) <<endl;
		}
		cout << "\t\t\tTotal Seats: " << totalSeats << endl;
		cout << "\t\t\t----- Available Seat -----\n";
		bool flag = false;
		for (int i = 0; i < totalSeats; i++) {
			if (!seats[i]) {
				cout << "\t\t\t" << i + 1;
			}
			else {
				cout << "\t\t\tNA";
			}
			if (!flag) {
				cout << "\t";
				flag = true;
			}
			else {
				cout << "\n";
				flag = false;
			}
		}
		cout << endl;
	}

	void displayAvailableSeats() const
	{
		cout << "\t\t\tAvailable Seats on Bus " << busNumber
			<< ":\n";
		for (int i = 0; i < totalSeats; ++i) {
			if (seats[i]) {
				cout << "\t\t\tSeat " << i + 1
					<< ": Available\n";
			}
		}
	}

	void displayBusStatus() const
	{
		int reservedSeats = 0;
		for (int i = 0; i < totalSeats; ++i) {
			if (seats[i]) {
				reservedSeats++;
			}
		}

		cout << "\t\t\tBus Status for Bus " << busNumber << ":\n";
		cout << "\t\t\tTotal Seats: " << totalSeats << "\n";
		cout << "\t\t\tReserved Seats: " << reservedSeats << "\n";
		cout << "\t\t\tAvailable Seats: "
			<< totalSeats - reservedSeats << "\n";
	}

	int getBusNumber() const { return busNumber; }

	vector<Route> getRoute()
	{
	    return routes;
	}

	void available_days(){
	    cout<<"\t\t\tGenerally Available on: ";
	    for(int i=0;i<7;i++){
            if(days[i]==1){
                cout<<getDayName(i)<<"  ";
            }
	    }
	    cout<<endl;
	}
	int week(int code){
	    return days[code];
	}
	vector<int> get_days(){
	    return days;
	}

	Date get_date(){
	    return date;
	}
	string arrivaltime(string city){
	    return maptimings[city];
	}
	map<string,string> getmap(){ return maptimings;}
private:
	int busNumber;
	vector<Route> routes;
	int totalSeats;
	vector<bool> seats;
	vector<int> days;
	Date date;
	map<string, string> maptimings;
};


#endif // BUS_H_INCLUDED
