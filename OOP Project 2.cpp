//References: c++ documentation.

#include "Reservation.h"
#include "iostream"
#include "Book.h"
#include "Software.h"
#include "Date.h"
#include "CD.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
	int iControl = 0,iMaterialNumber=0,iReservationNumber=0, iInput1=0, iInput2=0, iInput3=0,iInput4=0,iInput5=0; //Will hold values for ID, pages, etc.
	int iMaterialReservationControl[50]; //Will work as a map (As i don't know how to do maps in c++ yet)
	string sX, sInput1="", sInput2="", sInput3="", sInput4="",sInput5=""; //Will hold the title, author, name, etc.
	
	bool bFound = false; //Will be used to check conditions on some cases.
	Book* book; Software* software; CD* cd; Material* material[20]; Reservation reservation[50]; Date d1; Date d2[50];
	ifstream iFile; ofstream oFile;
		iFile.open("material.txt");

			while (!iFile.eof()) {
				getline(iFile, sX);
				if (sX.find(" B ")!=-1 && (iControl<20)) { //Creates a new book.
					iInput1 =stoi (sX.substr(0, sX.find(" "))); //Gets the id of the book.
					sInput1 = sX.substr(sX.find(" ", 2) + 1, sX.find(" ", 4) - 3); //Gets the title of the book
					iInput2 = stoi(sX.substr(sX.find(" B ")+3,sX.find(" ",3))); //Gets the amount of pages that the book has.
					sInput3 = sX.substr(sX.find_last_of(" ")+1); //Gets the author of the book
					material[iControl] = new Book(iInput2, sInput3, iInput1, sInput1);
					iControl++;
				}

				if (sX.find(" C ") !=-1 && (iControl<20)) { //Creates a new CD
					iInput1 = stoi(sX.substr(0, sX.find(" ")));//Gets the id of the CD.
					sInput1 = sX.substr(sX.find(" ")+1,sX.find(" C ")-4);//Gets the title of the CD
					iInput2 = stoi(sX.substr(sX.find_last_of(" ")));//Gets the length of the cd
					material[iControl] = new CD(iInput2, iInput1, sInput1);
					iControl++;
				}

				if (sX.find(" S ") != -1 && (iControl<20)) {//
					sInput1 = sX.substr(sX.find_last_of(" ")+1);//Gets the operating system.
					iInput1 = stoi(sX.substr(0, sX.find(" ")));//Gets the id of the software.
					sInput2=sX.substr(sX.find(" ")+1,sX.find(" S ")-4);//Gets the name of the software.
					material[iControl] = new Software(sInput1, iInput1, sInput2);					
					iControl++;
				}
			}

			iMaterialNumber = iControl;
			iControl = 0;
			iFile.close();
			iFile.open("reservations.txt");

			while (!iFile.eof()) {
				iFile >> sInput1 >> sInput2 >> sInput3 >> sInput4 >> sInput5; //gets the day,month,year,client id and material id.
				reservation[iControl].SetReservationDate(stoi(sInput1), stoi(sInput2), stoi(sInput3)); //sets the reservation date.
				reservation[iControl].SetMaterialID(stoi(sInput4)); //sets the material id.
				reservation[iControl].SetClientID(stoi(sInput5)); //sets the client id.
				if (iControl<50)iControl++;
			}
			iReservationNumber = iControl-1;
			iControl = 0;

			//This will set all the ending dates for the reservation.
			for (int i = 0; i < iReservationNumber; i++) {
				for (int e = 0; e < iMaterialNumber; e++) {
					if (reservation[i].GetMaterialID() == material[e]->GetMaterialID()) {
					    iMaterialReservationControl[i]=e; //Sets the key for the material, so if i use iMaterialReservationControl[i] I'll get the corresponding value for the reservation
						d2[i]= reservation[i].calculateEndOfReservation(material[e]->numberOfDaysRented());
						
						break;
					}
				}
			}
		
			do {
				cout << "MENU:\n1) Display the list of material\n2) Display the list of reservation\n3) Display the reservation of a given material" <<
					"\n4) Display the reservations of a given date\n5) Do a reservation\n6) Exit the program" << endl;
				cin >> iInput1;
				cin.ignore();
				switch (iInput1) {

					case 1://Display list of materials.
					
						for (int i = 0; i < iMaterialNumber; i++) {
							material[i]->toString();
						}
						break;

					case 2://Display the list of reservations

						bFound = false;
						for (int i = 0; i < iReservationNumber; i++) {
							bFound = false;
							cout << "Title: " << material[iMaterialReservationControl[i]]->GetTitle() << endl;
							reservation[i].toString();
							cout << "Return " << d2[i] << endl<<endl;
						}
						break;

					case 3://Display the reservation of a given material.

						bFound = false;
						do {
							cout << "Write the id of the material" << endl;
							cin >> iInput1;
							cin.ignore();
	
							for (int i = 0; i < iReservationNumber; i++) {
								if (reservation[i].GetMaterialID() == iInput1) {
									bFound = true;
									cout << "Title: " << material[iMaterialReservationControl[i]]->GetTitle();
									reservation[i].toString();
									cout << "It must be returnred by: " << d2[i] << endl;
								}
							}

							if (!bFound) cout << "The material was not found or it does not has a reservation date yet." << endl;
						} while (!bFound);
						break;

					case 4://Display the reservation of a given date.

						bFound = false;
						cin >> d1; //gets the date.

						for (int i = 0; i < iReservationNumber; i++) {
							if (d1 == reservation[i].GetReservationDate() || (d2[i]==d1)|| (d2[i] > d1) && (reservation[i].GetReservationDate() < d1) ) {
								bFound = true;
								cout << "Title: " << material[iMaterialReservationControl[i]]->GetTitle() << endl;
								reservation[i].toString();
								cout << "Return " << d2[i] << endl << endl;
							} 
						}

						if (!bFound) cout << "There are no reservation for that date" << endl << endl;
						break;

					case 5://Do a reservation

						if (iReservationNumber < 50) {

							bFound = false;
							cout << "Type the client id" << endl;
							cin >> iInput1; //Will hold the client ID.
							cin.ignore();
							cout << "Type the material id" << endl;
							cin >> iInput2; //Will hold the material ID.
							cin.ignore();
							do { //will check if the material id is a valid one.

								for (int i = 0; i < iMaterialNumber; i++) {
									if (iInput2 == material[i]->GetMaterialID()) bFound = true;
								}
								if (!bFound) {
									cout << "Type a valid material id" << endl;
									cin >> iInput2;
									cin.ignore();
								}

							} while (!bFound);

							cin >> d1;
							bFound = false;
							//The following for will check if the date is a valid one.

							for (int i = 0; i < iReservationNumber; i++) {
								if (iInput2 == reservation[i].GetMaterialID()) {
									if (d1 == reservation[i].GetReservationDate()) bFound = true;
									if (d1 == d2[i]) bFound = true;
									if ((d1 < d2[i]) && (d1 > reservation[i].GetReservationDate())) bFound = true;
								}
							}

							if (!bFound) {
								iReservationNumber++;
								reservation[iReservationNumber-1].SetClientID(iInput1);
								reservation[iReservationNumber-1].SetMaterialID(iInput2);
								reservation[iReservationNumber-1].SetReservationDate(d1.GetDay(), d1.GetMonth(), d1.GetYear());
								//check if this works
								for (int i = 0; i < iMaterialNumber; i++) {
									if (material[i]->GetMaterialID() == iInput2) {
										iMaterialReservationControl[iReservationNumber - 1] = i;
									}
								}
								d2[iReservationNumber - 1] = reservation[iReservationNumber - 1].calculateEndOfReservation(material[iMaterialReservationControl[iReservationNumber - 1]]->numberOfDaysRented());
								for (int i = 0; i < iReservationNumber; i++) {
									cout << "Title: " << material[iMaterialReservationControl[i]]->GetTitle() << endl;
									reservation[i].toString();
									cout << d2[i] << endl;
								}
							}
							else {
								cout << "The requested material is reserved for that date." << endl;
							}
						}
						else {
							cout << "Reservation limit has been reached " << endl;
						}
						break;

					case 6://Do a reservation

						cout << "Updating reservation database..." << endl;
						oFile.open("reservations.txt");
						for (int i = 0; i < iReservationNumber; i++) {
							d1=reservation[i].GetReservationDate();
							sInput1 = to_string(d1.GetDay()); //gets day;
							sInput2 = to_string(d1.GetMonth());// gets month;
							sInput3 = to_string(d1.GetYear()); //gets year;
							sInput4 = to_string(reservation[i].GetMaterialID()); //gets material id;
							sInput5 = to_string(reservation[i].GetClientID()); //gets client id;
							oFile << sInput1 << " " << sInput2 << " " << sInput3 << " " << sInput4 << " " << sInput5 << endl;
						}
						oFile.close();
						cout << "Database has been updated." << endl;
						break;

					default:
						cout << "Write a valid option for the menu" << endl;
						break;
				}
			} while (iInput1 != 6);


			iFile.close();
	return 0;
}