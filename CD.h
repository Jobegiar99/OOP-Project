#include "Material.h"
#include <iostream>
#ifndef CD_h
#define CD_h
#endif

using namespace std;

class CD :public Material {
public:
	int iDuration;
	CD();
	CD(int, int, string);
	void toString();
	int numberOfDaysRented();
	int GetDuration();
	void SetDuration(int);
};
CD::CD() :Material() {
	iDuration = 0;
}
CD::CD(int iDuration, int iMaterialID, string sTitle) : Material(iMaterialID, sTitle) {
	this->iDuration = iDuration;
}
void CD::toString() {
	cout << "ID: " << iMaterialID << "\nTitle: " << sTitle << "\nDuration: "<<iDuration<<" minutes" << endl<<endl;
}

int CD::numberOfDaysRented() {
	return 3;
}

int CD::GetDuration() {
	return iDuration;
}
void CD::SetDuration(int iDuration) {
	this->iDuration = iDuration;
}