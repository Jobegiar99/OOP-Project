#pragma once
#include <iostream>
#include <string>
#ifndef Date_h
#define Date_h
#endif

using namespace std;

class Date {
private:
	string nameOfMonth();
public:
	int iDay;
	int iMonth;
	int iYear;
	Date();
	Date(int, int, int);
	int GetDay();
	int GetMonth();
	int GetYear();
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	friend Date operator+(Date, int);
	friend bool operator>=(Date, Date);
	friend bool operator>(Date, Date);
	friend bool operator<=(Date, Date);
	friend bool operator<(Date, Date);
	friend bool operator==(Date, Date);
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, Date&);
};
string Date::nameOfMonth() {
	string month[12] = { "January","February","March","April","June","July","August","September","October","November","December" };
	return month[iMonth - 1];
}
Date::Date() {
	iDay = 0;
	iMonth = 0;
	iYear = 0;
}
Date::Date(int iDay, int iMonth, int iYear) {
	this->iDay = iDay;
	this->iMonth = iMonth;
	this->iYear = iYear;
}
void Date::SetDay(int iDay) {
	this->iDay = iDay;
}
void Date::SetMonth(int iMonth) {
	this->iMonth = iMonth;
}
void Date::SetYear(int iYear) {
	this->iYear = iYear;
}
int Date::GetDay() {
	return iDay;
}
int Date::GetMonth() {
	return iMonth;
}
int Date::GetYear() {
	return iYear;
}
Date operator+(Date d1, int iD) {
	d1.iDay += iD;
	return d1;
}
bool operator>=(Date d1, Date d2) {
	if (d1.GetDay() >= d2.GetDay()) {
		if (d1.GetMonth() >= d2.GetMonth()) {
			if (d1.GetYear() >= d2.GetYear()) {
				return true;
			}
		}
	}
	return false;
	
}
bool operator>(Date d1, Date d2) {
	if (d1.GetYear() > d2.GetYear()) {
		return true;

	}else if (d1.GetYear() == d2.GetYear()) {

		if (d1.GetMonth() == d2.GetMonth()) {
			if (d1.GetDay() > d2.GetDay()) {
				return true;
			}
		} else if (d1.GetMonth() > d2.GetMonth()) {
				return true;
		}
	}
	return false;
}

bool operator<(Date d1, Date d2) {
	if (d1.GetYear() < d2.GetYear()) {
		return true;
	}
	else if (d1.GetYear() == d2.GetYear()) {
		if (d1.GetMonth() == d2.GetMonth()) {
			if (d1.GetDay() < d2.GetDay()) {
				return true;
			}
		}else {
			if (d1.GetMonth() < d2.GetMonth()) {
				return true;
			}
		}
	}
	return false;
}
bool operator<=(Date d1, Date d2) {
	if (d1.GetDay() <= d2.GetDay()) {
		if (d1.GetMonth() <= d2.GetMonth()) {
			if (d1.GetYear() <= d2.GetYear()) {
				return true;
			}
		}
	}
	return false;
}
bool operator==(Date d1, Date d2) {
	if (d1.GetDay() == d2.GetDay()) {
		if (d1.GetMonth() == d2.GetMonth()) {
			if (d1.GetYear() == d1.GetYear()) {
				return true;
			}
		}
	}

	return false;
}

istream& operator>>(istream & is, Date & d1) {
	int iDay, iMonth, iYear;
	cout << "Write the day, then month and finally the year (you must use enter per answer)" << endl;
	is >> iDay;
	is.ignore();
	is >> iMonth;
	is.ignore();
	is >> iYear;
	is.ignore();
	d1.iDay = iDay;
	d1.iMonth = iMonth;
	d1.iYear = iYear;
	cout << endl;
	return is;
}

ostream& operator<<(ostream & os, Date & d1) {
	os <<"Date: "<< d1.iDay <<"/" << d1.iMonth <<"/"<<d1.iYear << endl;
	return os;
}
