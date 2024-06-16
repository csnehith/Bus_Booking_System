#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


class Admin {
public:
	Admin(const string& password): password(password){}

	string getPassword() const { return password; }

private:
	string password;

};

#endif // ADMIN_H_INCLUDED
