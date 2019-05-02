#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#ifndef Reservation_h
#define Reservation_h
#endif

using namespace std;
class Reservation {
public:
	int iMaterialID;
	int iClientID;
	Date reservationDate;
	Reservation();
	Reservation(int, int, int, int, int);
	void SetMaterialID(int);
	void SetClientID(int);
	void SetReservationDate(int, int, int);
	int GetMaterialID();
	int GetClientID();
	Date GetReservationDate();
	Date calculateEndOfReservation(int);
	void toString();
};

Reservation::Reservation() {
	iMaterialID = -1;
	iClientID = -1;
	reservationDate.iDay = -1;
	reservationDate.iMonth = -1;
	reservationDate.iYear = -1;
}

Reservation::Reservation(int iDay, int iMonth, int iYear, int iMaterialID, int iClientID) {
	this->iMaterialID = iMaterialID;
	this->iClientID = iClientID;
	reservationDate.iDay = iDay;
	reservationDate.iMonth = iMonth;
	reservationDate.iYear = iYear;
}

void Reservation::SetMaterialID(int iMaterialID) {
	this->iMaterialID = iMaterialID;
}
void Reservation::SetClientID(int iClientID) {
	this->iClientID = iClientID;
}
void Reservation::SetReservationDate(int iDay, int iMonth, int iYear) {
	reservationDate.iDay = iDay;
	reservationDate.iMonth = iMonth;
	reservationDate.iYear = iYear;
}
int Reservation::GetMaterialID() {
	return iMaterialID;
}
int Reservation::GetClientID() {
	return iClientID;
}
Date Reservation::GetReservationDate() {
	return reservationDate;
}
Date Reservation::calculateEndOfReservation(int iDatys) {
	Date d1;
	int iDays = 0, iMonth = 0, iYear = GetReservationDate().GetYear(),iMonthDays=28;
	
	switch (reservationDate.iMonth) {

	case 1: case 3: case 5: case 7: case 8: case 10: case 12: //31 days;
		iMonthDays = 31;
		break;

	case 4: case 6: case 9: case 11://30 days
		
		iMonthDays = 30;
		break;

	case 2://28 days
		iMonthDays = 38;
		break;
	}

	if (iDatys < iMonthDays) {
		if ((GetReservationDate().GetDay() + iDatys) > iMonthDays) {
			iMonth = 1;
			iDays = (GetReservationDate().GetDay() + iDatys) - iMonthDays;
			if (iDays == 0) iDays = 1;
		}
		else {
			iDays = (GetReservationDate().GetDay() + iDatys);
		}
	}
	else {
		iMonth = (iDatys / iMonthDays);
		iDatys %= iMonthDays;
		iDays = (((iDatys + GetReservationDate().GetDay()) > iMonthDays) ? (iDatys + GetReservationDate().GetDay()) - iMonthDays : iDatys + GetReservationDate().GetDay());
	}
	if ((iMonth + GetReservationDate().GetMonth() > 12)) {
		iMonth = (iMonth + GetReservationDate().GetMonth()) - 12;
		iYear++;
	}
	else {
		iMonth = (iMonth + GetReservationDate().GetMonth());
	}
	
	d1.SetDay(iDays);
	d1.SetMonth(iMonth);
	d1.SetYear(iYear);
	
	return d1;
}

void Reservation::toString() {
	cout << reservationDate;
	cout << "Client ID: " << iClientID << "\nMaterial ID: " << iMaterialID << endl;
}