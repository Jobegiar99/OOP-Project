#pragma once
#include <iostream>
#include "Date.h"
#ifndef Material_h
#define Material_h
#endif

using namespace std;

class Material {
protected:
	int iMaterialID;
	string sTitle;
public:
	Material();
	Material(int, string);
	void SetMaterialID(int);
	void SetTitle(string);
	int GetMaterialID();
	string GetTitle();
	virtual void toString() = 0;
	virtual int numberOfDaysRented() = 0;
};

Material::Material() {
	iMaterialID = -1;
	sTitle = "N/A";
}

Material::Material(int iMaterialID, string sTitle) {
	this->iMaterialID = iMaterialID;
	this->sTitle = sTitle;
}

int Material::GetMaterialID() {
	return iMaterialID;
}

string Material::GetTitle() {
	return sTitle;
}

void Material::SetMaterialID(int iMaterialID) {
	this->iMaterialID = iMaterialID;
}

void Material::SetTitle(string sTitle) {
	this->sTitle = sTitle;
}
