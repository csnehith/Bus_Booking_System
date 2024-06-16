#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void printLine(int length, const char c)
{
	for (int i = 0; i < length; i++) {
		cout << c;
	}
	cout << endl;
}

class Date {
public:
    Date(int day, int month, int year) {
        setDate(day, month, year);
    }

    void setDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        } else {
            throw invalid_argument("Invalid date");
        }
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    static bool isValidDate(int day, int month, int year) {
        if (month < 1 || month > 12 || day < 1 || year < 1) {
            return false;
        }

        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Adjust for leap years
        if (month == 2 && isLeapYear(year)) {
            daysInMonth[1] = 29;
        }

        return day <= daysInMonth[month - 1];
    }

private:
    int day;
    int month;
    int year;
    static bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

string getDayName(int dayCode) {
    switch (dayCode) {
        case 0: return "Saturday";
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
        default: return "Invalid";
    }
}
int daytocode(string day){
    if(day=="Saturday"){
        return 0;
    }
    else if(day=="Sunday"){
        return 1;
    }
    else if(day=="Monday"){
        return 2;
    }
    else if(day=="Tuesday"){
        return 3;
    }
    else if(day=="Wednesday"){
        return 4;
    }
    else if(day=="Thursday"){
        return 5;
    }
    else{
        return 6;
    }
}
string Day_week(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    return getDayName(h);
}




#endif // DATE_H_INCLUDED
