#pragma once
#include "Material.h"
#include <iostream>
#include <string>
#ifndef Software_h
#define Software_h
#endif
using namespace std;
class Software :public Material {
public:
	string sOperatingSystem;
	Software();
	Software(string, int, string);
	void toString();
	int numberOfDaysRented();
	void SetOperatingSystem(string);
	string GetOperatingSystem();

};

Software::Software() :Material() {
	sOperatingSystem = "N/A";
}

Software::Software(string sOperatingSystem, int iMaterialID, string sTitle) : Material(iMaterialID, sTitle) {
	this->sOperatingSystem = sOperatingSystem;
}

void Software::toString() {
	cout << "ID: " << iMaterialID << "\nTitle: " << sTitle << "\nOperating System: " << sOperatingSystem << endl<<endl;
}

int Software::numberOfDaysRented() {
	return 1;
}

void Software::SetOperatingSystem(string sOperatingSystem) {
	this->sOperatingSystem = sOperatingSystem;
}

string Software::GetOperatingSystem() {
	return sOperatingSystem;
}