#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "busreservationsystem.h"
#include "admin.h"


using namespace std;


int main()
{
    Admin admin("password");
	BusReservationSystem system(admin);
	system.run();
	return 0;
}
