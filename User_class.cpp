#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "ticker.h"
using namespace std;


class User {
public:
	User(const string& username, const string& password): username(username), password(password)
	{
	}

	string getUsername() const { return username; }
	string getPassword() const { return password; }
	void addTicket(Ticket& newTicket)
	{
		tickets.push_back(newTicket);
	}

	void removeTicket(int index)
	{
		vector<Ticket>::iterator i = tickets.begin();
		i = i + index - 1;
		tickets.erase(i);
	}

	void printAllTickets() const
	{
		int i = 0;
		for (i = 0; i < tickets.size(); i++) {
            Bus cur=tickets[i].getBus();
			cout << "\n\t\t------ Ticket " << i + 1
				<< " ------" << endl;
			cout << "\t\t\tPassenger: "
				<< tickets[i].getPassengerName() << endl;
			cout << "\t\tSource: "
				<< tickets[i].getsource()
				<< " to "
				<< tickets[i].getdestination()
				<< "\n";
			cout << "\t\t\tBus Number: "
				<< tickets[i].getBus().getBusNumber()
				<< endl;
			cout << "\t\t\tSeat Number: "
				<< tickets[i].getSeatNumber() << endl;
            cout << "\t\t\tDate of Travel: "
                << cur.get_date().getDay()<<"-"<<cur.get_date().getMonth()<<"-"<< cur.get_date().getYear()<< endl;
		}
	}

	int numberOfTickets() const { return tickets.size(); }

	Ticket& getTicket(int index)
	{
		return tickets[index - 1];
	}

private:
	string username;
	string password;
	vector<Ticket> tickets;
};
