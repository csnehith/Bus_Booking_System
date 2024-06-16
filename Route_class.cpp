#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Route {
public:
	Route(string& name, string& source,string& destination, int distance): name(name), source(source), destination(destination), distance(distance)
	{
	}

	string getNumber() { return name; }
	string getSource() { return source; }
	string getDestination() { return destination; }
	int getDistance() { return distance; }

private:
	string name;
	string source;
	string destination;
	int distance;
};

