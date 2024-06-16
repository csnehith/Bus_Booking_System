#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "bus.h"
#include "date.h"
#include "ticker.h"
#include "route.h"
#include "admin.h"
#include "user.h"

using namespace std;


class BusReservationSystem {
public:
	BusReservationSystem(Admin& admin) : admin(admin)
	{
	    Addroute("A-B","A","B",5); //0 1
	    Addroute("A-C","A","C",5); //2 3
	    Addroute("A-D","A","D",5); //4 5
	    Addroute("B-C","B","C",5); //6 7
	    Addroute("C-D","C","D",5); //8 9
	    Addroute("B-E","B","E",5); //10 11
	    Addroute("B-F","B","F",5); //12 13
	    Addroute("C-F","C","F",5); //14 15
	    Addroute("C-G","C","G",5); //16 17
	    Addroute("D-G","D","G",5); //18 19
	    Addroute("G-H","G","H",5); //20 21
	    Addroute("E-I","E","I",5); //22 23
	    Addroute("F-J","F","J",5); //24 25
	    Addroute("I-J","I","J",5); //26 27

	    vector<Route> v;
	    v.push_back(routes[0]);
	    map<string, string> m;
	    m["A"]="08:00";
	    m["B"]="08:30";
	    buses.push_back(Bus(5,v,20,{1,1,0,1,0,1,0},Date(15,6,2024),m));
	    v.push_back(routes[6]);
	    m["C"]="09:10";
	    buses.push_back(Bus(1,v,20,{0,1,1,1,0,0,1},Date(16,6,2024),m));
	    v.push_back(routes[14]);
	    m["F"]="10:00";
	    buses.push_back(Bus(2,v,20,{1,1,0,1,0,1,0},Date(16,6,2024),m));
	    v.push_back(routes[24]);
	    m["J"]="11:05";
	    buses.push_back(Bus(3,v,20,{0,1,1,1,0,0,1},Date(16,6,2024),m));
	    v.push_back(routes[27]);
	    m["I"]="11:55";
	    buses.push_back(Bus(4,v,20,{0,1,0,1,0,0,0},Date(16,6,2024),m));
	    v.clear();
	    m.clear();
	    m["E"]="16:25";
	    m["I"]="17:00";
	    v.push_back(routes[22]);
	    buses.push_back(Bus(6,v,20,{1,1,0,1,0,1,0},Date(16,6,2024),m));
	    m["J"]="17:40";
	    v.push_back(routes[26]);
	    buses.push_back(Bus(7,v,20,{0,1,0,1,0,0,0},Date(16,6,2024),m));
	    v.clear();
	    m.clear();
	    m["H"]="11:45";
	    m["G"]="12:35";
	    v.push_back(routes[21]);
	    buses.push_back(Bus(8,v,20,{1,1,0,1,0,1,0},Date(16,6,2024),m));
	    v.push_back(routes[19]);
	    m["D"]="13:00";
	    buses.push_back(Bus(9,v,20,{0,1,0,1,0,0,0},Date(16,6,2024),m));
	    v.push_back(routes[9]);
	    m["C"]="13:45";
	    buses.push_back(Bus(10,v,10,{0,1,0,1,0,0,0},Date(16,6,2024),m));
	    v.pop_back();
	    m["C"]="00:00";
	    v.push_back(routes[5]);
	    m["A"]="13:30";
	    buses.push_back(Bus(12,v,30,{0,1,1,1,0,0,1},Date(16,6,2024),m));
	}

	void registerUser(const string& username,const string& password)
	{
		users.push_back(User(username, password));
		cout << "\n\t\tUser registered successfully. "
				"Please login to continue!\n";
	}

	bool authenticateUser(const string& username,const string& password)
	{
		for (const User& user : users) {
			string lowercaseUsername = user.getUsername();
			string lowercaseInputUsername = username;
			transform(lowercaseUsername.begin(),lowercaseUsername.end(),lowercaseUsername.begin(), ::tolower);
			transform(lowercaseInputUsername.begin(),lowercaseInputUsername.end(),lowercaseInputUsername.begin(),::tolower);

			if (lowercaseUsername == lowercaseInputUsername&& user.getPassword() == password) {
				return true;
			}
		}
		return false;
	}
	bool authenticateAdmin(const string& password)
	{
        if (admin.getPassword() == password) {
            return true;
        }
		return false;
	}
    void AddBus()
    {
        cout<<"\t\t\tAdd Bus or New Date for a Bus\n";
        int busnumber, seats,date,month,year;
        map<string, string> mapp;
        cout<< "\t\t\tEnter the bus number :";
        cin>> busnumber;
        bool k=false;
        bool id;
        for(int i=0;i<buses.size();i++){
            if(buses[i].getBusNumber()==busnumber){
                k=true;
                id=i;
                break;
            }
        }
        if(k){
            cout<<"\t\t\tBus number already exist\n";
            cout<<"\t\t\tAdd the date for bus to run\n";
            cout<<"\t\t\tdate"<<": ";
            cin>>date;
            cout<<"\t\t\tmonth"<<": ";
            cin>>month;
            cout<<"\t\t\tyear"<<": ";
            cin>>year;
            Bus cur=buses[id];
            Date d_cur= Date(date,month,year);
            if(cur.week( daytocode(Day_week(date,month,year)))==0){
                cout<<"\t\t\tBus cant be available on that day of week\n";
                return;
            }
            if(cur.get_date().getDay()== d_cur.getDay() && cur.get_date().getMonth()== d_cur.getMonth() && cur.get_date().getYear()== d_cur.getYear() ){
                cout<<"\t\t\tBus already exit on that Day"<<endl;
                return;
            }
            buses.push_back(Bus(cur.getBusNumber(),cur.getRoute(),cur.getTotalSeats(), cur.get_days(),d_cur, cur.getmap() ));
            return;
        }
        cout<< "\t\t\tEnter total number of seats :";
        cin>>seats;
        vector<Route> rout;
        string inittime;
        cout<<"\t\t\tEnter the Start time of Bus: ";
        cin>>inittime;
        while(true){
            cout<< "\t\t\tEnter the paths you want the bus to travel: ";
            string route;
            cin>>route;
            bool c = false;
            if(rout.size()!=0 && rout.back().getDestination()[0]!=route[0]){
                cout<<"\t\t\tPrevious City is not the start City in this path\n";
                cout<<"\t\t\tEnter a correct one\n";
                continue;
            }
            for(int i=0;i<routes.size();i++){
                if(routes[i].getNumber()==route){
                    c=true;
                    rout.push_back(routes[i]);
                    string time;
                    cout<<"\t\t\tEnter the Reaching time for this Destination: ";
                    cin>>time;
                    mapp[routes[i].getDestination()]=time;
                    break;
                }
            }
            if(!c){
                cout<<"\t\t\tRoute doesnt exist\n";
            }

            cout<<"\t\t\tDid u complete adding routes: (y/n) ";
            string check;
            cin>>check;
            if(check=="y"){
                break;
            }
            else if(check=="n"){
                continue;
            }
        }
        mapp[rout[0].getSource()]=inittime;
        vector<int> week(7,0);
        cout<< "\t\t\tEnter the Availability of Bus on Weekday: \n";
        for(int i=0;i<7;i++){
            int j;
            cout<<"\t\t\t"<<getDayName(i)<<" (0/1): ";
            cin>>j;
            week[i]=j;
        }

        cout<<"\t\t\tAdd the date for bus to run\n";
        cout<< "\t\t\tdate"<<": ";
        cin>>date;
        cout<< "\t\t\tmonth"<<": ";
        cin>>month;
        cout<<"\t\t\tyear"<<": ";
        cin>>year;

        buses.push_back(Bus(busnumber,rout,seats,week,Date(date,month,year),mapp));
    }
    void DeleteBus()
    {
        int busnumber,d,m,y;
        cout<< "\t\t\tEnter the Bus number to be deleted: \n";
        cin>>busnumber;
        cout<<"\t\t\tEnter the date of bus :";
        cin>>d;
        cout<<"\t\t\tEnter the month of bus :";
        cin>>m;
        cout<<"\t\t\tEnter the year of bus :";
        cin>>y;
        int id=-1;
        for(int i=0;i<buses.size();i++){
            Bus cur=buses[i];
            Date d_cur=cur.get_date();
            if(cur.getBusNumber()==busnumber && d_cur.getDay()==d && d_cur.getMonth()==m && d_cur.getYear()==y ){
                id=i;
                break;
            }
        }
        if(id==-1){
            cout<<"\t\t\tBus doesn't exist\n";
            return;
        }
        buses.erase(buses.begin()+id);
    }
    void Addroute(string name, string citya, string cityb, int dist)
    {
         routes.push_back(Route(name,citya,cityb, dist));
         size_t hyphenPos = name.find('-');
         string stringa = name.substr(0, hyphenPos);
         string stringb = name.substr(hyphenPos + 1);
         string result = stringb + "-" + stringa;
         routes.push_back(Route(result,cityb,citya,dist));
    }
    void Add_route()
    {
        string citya,cityb;
        int dist;
        cout<<"\t\t\tEnter the city a :";
        cin>>citya;
        cout<<"\t\t\tEnter the city b :";
        cin>>cityb;
        cout<<"\t\t\tEnter the Distance :";
        cin>>dist;
        for(int i=0;i<routes.size();i++){
            if(routes[i].getSource()==citya && routes[i].getDestination()==cityb){
                cout<<"\t\t\tRoute Already exist"<<endl;
                return;
            }
            if(routes[i].getDestination()==citya && routes[i].getSource()==cityb){
                cout<<"\t\t\tRoute Already exist"<<endl;
                return;
            }
        }
        Addroute(citya+"-"+cityb,citya,cityb, dist);
    }
	User& findUser(string username)
	{
		for (int i = 0; i < users.size(); i++) {
			if (users[i].getUsername() == username) {
				return users[i];
			}
		}
		return users[users.size() - 1];
	}

	int displayBusesForRoute(string source, string destination, Date date, string day)
	{
	    bool present=false;
		for (int i = 0; i < buses.size(); i++) {
			vector<Route> paths = buses[i].getRoute();
			bool present_sor=false;
			bool present_dest=false;
			for(int k=0;k< paths.size();k++){
                if(paths[k].getSource() == source){
                    present_sor=true;
                }
                if(paths[k].getDestination() == destination){
                    if(present_sor==true){
                        present_dest=true;
                    }
                }
			}
			if(present_sor==true && present_dest==true){
                present=true;
                if(buses[i].week(daytocode(day))==1 ){
                     Date d_cur=buses[i].get_date();
                     if(d_cur.getDay()==date.getDay() && d_cur.getMonth()==date.getMonth() && d_cur.getYear()==date.getYear()){
                        buses[i].dipalybusAvailability();
                        cout<<endl;
                     }
                }
			}
		}
		if(present==false){
            cout<< "\t\t\tNo Buses available \n";
            return 0;
		}
		return 1;
	}
    void CheckBuses(const string& username)
    {
        int selectedBus, selectedSeat;
        string source, destination;
        int date, month, year;
        cout<< "\t\t\tEnter Source: ";
        cin>>source;
        cout<< "\t\t\tEnter Destination: ";
        cin>>destination;
        cout<< "\t\t\tEnter the date: ";
        cin>>date;
        cout<<"\t\t\tEnter the Month: ";
        cin>>month;
        cout<<"\t\t\tEnter the Year: ";
        cin>>year;

		bool validRoute = false;
        if(source>="A" && destination>="A" &&source<="Z" && destination<="Z"){
            validRoute=true;
        }
		if (!validRoute) {
			cout << "\n\tNo route available. Please "
					"enter a valid route.\n";
			return; // Return to the main menu
		}

		// Consume the newline character
		cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

		// Display buses for the selected route
		int x=displayBusesForRoute(source, destination, Date(date,month,year),Day_week(date,month,year));

		if(x==0){
            return;
		}
		while(true){
            string b;
            cout<<"\t\t\tDo you want to check seats available for a particular bus (y/n):";
            cin>>b;
            if(b=="y"){
                int bus;
                cout<<"\t\t\tenter bus number: ";
                cin>>bus;
                int id;
                for(int i=0;i<buses.size();i++){
                    Bus cur=buses[i];
                    Date d_cur=cur.get_date();
                    if(cur.getBusNumber()==bus && d_cur.getDay()==date && d_cur.getMonth()==month && d_cur.getYear()==year ){
                        id=i;
                        break;
                    }
                }
                buses[id].displayBusInfo();
                buses[id].available_days();
            }
            else{
                break;
            }
		}


    }
	void bookTicket(const string& username)
	{
		int selectedBus, selectedSeat;
		int date,month, year;
        string source, destination;
        cout<< "\t\t\tEnter Source: ";
        cin>>source;
        cout<< "\t\t\tEnter Destination: ";
        cin>>destination;
        cout<< "\t\t\tEnter the date: ";
        cin>>date;
        cout<<"\t\t\tEnter the Month: ";
        cin>>month;
        cout<<"\t\t\tEnter the Year: ";
        cin>>year;

		bool validRoute_s = false;
		bool validRoute_d = false;
        for(int i=0;i<routes.size();i++){
            if(source==routes[i].getSource()){
                validRoute_s=true;
            }
            if(destination==routes[i].getDestination()){
                if(validRoute_s==true){
                    validRoute_d=true;
                }
            }
        }
		if (!validRoute_s && !validRoute_d) {
			cout << "\n\tNo route available. Please "
					"enter a valid route.\n";
			return;
		}

		cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

        int x=displayBusesForRoute(source, destination,Date(date,month,year),Day_week(date,month,year));
        if(x==0){
            return;
        }

        while(true){
            string b;
            cout<<"\t\t\tDo you want to check seats available for a particular bus (y/n):";
            cin>>b;
            if(b=="y"){
                int bus;
                cout<<"\t\t\tenter bus number: ";
                cin>>bus;
                int id;
                for(int i=0;i<buses.size();i++){
                    Bus cur=buses[i];
                    Date d_cur=cur.get_date();
                    if(cur.getBusNumber()==bus && d_cur.getDay()==date && d_cur.getMonth()==month && d_cur.getYear()==year ){
                        id=i;
                        break;
                    }
                }
                buses[id].displayBusInfo();
                buses[id].available_days();
            }
            else{
                break;
            }
		}

		cout << "\n\t\tSelect a Bus (Enter the Bus "
				"Number): ";
		int busNumber;
		cin >> busNumber;

		bool validRoute = false;
		for (int i = 0; i < buses.size(); i++) {
            Bus cur=buses[i];
            Date d_cur=cur.get_date();
            if(cur.getBusNumber()==busNumber && d_cur.getDay()==date && d_cur.getMonth()==month && d_cur.getYear()==year ){
                selectedBus=i+1;
                validRoute = true;
                break;
            }
		}

		if (!validRoute) {
			cout << "\n\tInvalid bus number. Please enter "
					"a valid bus number for the selected "
					"route.\n";
			return;
		}

		cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

		cout << "\n\t\tEnter the seat number you want to "
				"book: ";
		cin >> selectedSeat;

		if (cin.fail() || selectedSeat < 1|| selectedSeat > buses[selectedBus - 1].getTotalSeats()) {
			cout << "\n\tInvalid seat number. Please enter "
					"a valid seat number for the selected "
					"bus.\n";
			return;
		}

		if (buses[selectedBus - 1].reserveSeat(selectedSeat)) {
			Ticket ticket(username, selectedSeat,source, destination,buses[selectedBus - 1], Date(date,month,year));
			User& user = findUser(username);
			user.addTicket(ticket);
			cout << "\n\t\t\tTicket booked successfully!\n";
			cout << "\t\t\tPassenger: "
				<< ticket.getPassengerName() << "\n";
			cout << "\t\t\tBus Number: "
				<< buses[selectedBus - 1].getBusNumber()
				<< "\n";
			cout << "\t\t\tsource: "
				<< ticket.getsource() << " to "
				<< ticket.getdestination()
				<< "\n";
            cout<<"\t\t\tDate: "
                << ticket.get_date() <<"-"
                << ticket.get_month()<<"-"
                << ticket.get_year()<<endl;
			cout << "\t\t\tSeat Number: "
				<< ticket.getSeatNumber() << "\n";
			buses[selectedBus - 1].displayBusStatus();
		}
		else {
			cout << "\n\tSeat booking failed. The seat is "
					"already reserved or does not exist.\n";
		}
	}

	void cancelTicket(const string& username)
	{
		int ticketDel = -1;
		User& user = findUser(username);
		if (user.numberOfTickets() <= 0) {
			cout << "\n\t\t\nNo Tickets Booked!\n";
			return;
		}
		user.printAllTickets();

		cout << "\t\t\t\nSelect the ticked to be "
				"cancelled... ";
		cin >> ticketDel;


		cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			'\n');

		if (cin.fail()
			|| ticketDel > user.numberOfTickets()) {
			cout << "\tInvalid Ticked Selected! Please "
					"select a valid ticket\n";
			return;
		}
		else {
			cout << "\t\t\tTicket canceled successfully.\n";
			Ticket ticket = user.getTicket(ticketDel);
			Bus bus = ticket.getBus();
			for (int i = 0; i < buses.size(); i++) {
                Bus cur=buses[i];
                Date d_cur=cur.get_date();
                if(cur.getBusNumber()==bus.getBusNumber() && d_cur.getDay()==ticket.get_date() && d_cur.getMonth()==ticket.get_month() && d_cur.getYear()==ticket.get_year() ){
                    buses[i].cancelSeat(ticket.getSeatNumber());
                }
			}
			user.removeTicket(ticketDel);
		}
	}

	void run()
	{
		while (true) {
			cout << "\n\t------ Welcome to the Bus "
					"Booking System------\n\n";
			cout << "\t\t\t1. Adminlogin\n\t\t\t2. Register\n\t\t\t3. Log "
					"In\n\t\t\t4. Exit\t\t\t\n";
			cout << "\n\t\t\tEnter your choice: ";
			int choice;
			cin >> choice;

			if (choice == 2) {
				string username, password;
				cout << "\n\t\t\tEnter username: ";
				cin >> username;
				cout << "\t\t\tEnter password: ";
				cin >> password;
				registerUser(username, password);
			}
			else if (choice == 3) {
				string username, password;
				cout << "\n\t\t\tEnter username: ";
				cin >> username;
				cout << "\t\t\tEnter password: ";
				cin >> password;
				if (authenticateUser(username, password)) {
					cout << "\n\t\t\tLogged in "
							"successfully!\n";
					userMenu(username);
				}
				else {
					cout << "\n\t\tAuthentication failed! "
							"Please check your username "
							"and password.\n";
				}
			}
			else if (choice == 1) {
				string password;
				cout << "\t\t\tEnter password: ";
				cin >> password;
				if (authenticateAdmin(password)) {
					cout << "\n\t\t\tLogged in "
							"successfully!\n";
					adminMenu();
				}
				else {
					cout << "\n\t\tAuthentication failed! "
							"Please check your password \n";
				}
			}
			else if (choice == 4) {
				cout << "\n\t\tExiting the Bus Reservation "
						"System. Goodbye!\n";
				break;
			}
		}
	}

	void userMenu(string username)
	{
		int choice = 0;
		while (true) {
			cout << "\n\t----------- Welcome to the User "
					"Menu ------------\n\n";
			cout << "\t\t\t1. Check Buses\n\t\t\t2. Book Ticket\n\t\t\t3. "
					"Cancel Ticket\n\t\t\t4. Log"
					"Out\n\t\t\n";
			cout << "\n\t\t\tEnter your choice: ";
			cin >> choice;
            if(choice == 1){
                CheckBuses(username);
            }
			else if (choice == 2) {
				bookTicket(username);
			}
			else if (choice == 3) {
				cancelTicket(username);
			}
			else if (choice == 4) {
				cout
					<< "\n\t\t\tLogged out successfully.\n";
				break;
			}
		}
	}

	void adminMenu()
	{
		int choice = 0;
		while (true) {
			cout << "\n\t----------- Welcome to the Admin "
					"Menu ------------\n\n";
			cout << "\t\t\t1. Add Bus\n\t\t\t2. "
					"Delete Bus\n\t\t\t3. Add"
					"Route\n\t\t\t4. Log"
					"out\n";
			cout << "\n\t\t\tEnter your choice: ";
			cin >> choice;

			if (choice == 1) {
                AddBus();
			}
			else if (choice == 2) {
				DeleteBus();
			}
			else if (choice ==3){
                Add_route();
			}
			else if (choice == 4) {
				cout
					<< "\n\t\t\tLogged out successfully.\n";
				break;
			}
		}
	}

private:
	vector<User> users;
	Admin admin;
	vector<Route> routes;
	vector<Bus> buses;
};
