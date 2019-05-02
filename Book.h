#pragma once
#include "Material.h"
#include <iostream>
#ifndef Book_h
#define Book_h
#endif

using namespace std;

class Book : public Material {
public:
	Book();
	Book(int, string, int, string);
	int iNumOfPages;
	string sAuthor;
	void toString();
	int numberOfDaysRented();
	void SetNumOfPages(int);
	void SetAuthor(string);
	int GetNumOfPages();
	string GetAuthor();
};

Book::Book() : Material() {
	iMaterialID = 0;
	sTitle = "N/A";
	iNumOfPages = 0;
	sAuthor = "N/A";
}

Book::Book(int iNumOfPages, string sAuthor, int iMaterialID, string sTitle) :Material(iMaterialID, sTitle) {
	this->iNumOfPages = iNumOfPages;
	this->sAuthor = sAuthor;
	this->sTitle = sTitle;
}

void Book::toString() {
	cout << "ID: " << iMaterialID << "\nTitle: " << sTitle << "\nAuthor: " << sAuthor << "\nNumber of Pages: " << iNumOfPages << endl << endl;
}

int Book::numberOfDaysRented() {
	return 10;
}
void Book::SetNumOfPages(int iNumOfPages) {
	this->iNumOfPages = iNumOfPages;
}

void Book::SetAuthor(string sAuthor) {
	this->sAuthor = sAuthor;
}

int Book::GetNumOfPages() {
	return iNumOfPages;
}

string Book::GetAuthor() {
	return sAuthor;
}