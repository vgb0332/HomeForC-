/*
 * CPhoneContact.cpp
 *
 *  Created on: Apr 6, 2016
 *      Author: Yongsuk
 */
/*
 * CPhoneContact.cpp
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Entry.h"
#include "CPhoneContact.h"

extern ValueInfo viNull;

PhoneContactVector::PhoneContactVector() { }

ValueInfo PhoneContactVector::find(string name) const{
	int loc = findLoc(name);
	if (loc == -1)
		return viNull; // not found
	return vectorPhoneBook[loc].valueInfo;
}
string PhoneContactVector::findName(int number) const{
	int loc = findLoc(number);
	if (loc == -1)
		return "No Name Found";
	return vectorPhoneBook[loc].phoneName;
}
string PhoneContactVector::findName(string email) const
{
	int loc = findLoc(email);
		if (loc == -1)
			return "No Name Found";
		return vectorPhoneBook[loc].phoneName;
}
bool PhoneContactVector::insert(string name, int number, string email){
	int loc = findLoc(name);
	if (loc == -1){ // insert
		vectorPhoneBook.push_back(Entry(name, number, email));
		return true;
	}
	else
		return false;
}

bool PhoneContactVector::remove(string name){
	int loc = findLoc(name);
	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (int i=loc+1; i<(signed)vectorPhoneBook.size(); ++i){
			vectorPhoneBook[i-1] = vectorPhoneBook[i];
		}
		vectorPhoneBook.pop_back();
		return true;
	}
	else
		return false;
}

bool PhoneContactVector::update(string name, int number, string email){
	int loc = findLoc(name);
	if(loc != -1){
		vectorPhoneBook[loc].valueInfo.emailAddress = email;
		vectorPhoneBook[loc].valueInfo.phoneNumber = number;
		return true;
	}
	else
		return false;

}
bool PhoneContactVector::update(string name, int number){
	int loc = findLoc(name);
		if(loc != -1){
			vectorPhoneBook[loc].valueInfo.phoneNumber = number;
			return true;
		}
		else
			return false;
}

bool PhoneContactVector::update(string name, string email){
	int loc = findLoc(name);
			if(loc != -1){
				vectorPhoneBook[loc].valueInfo.emailAddress = email;
				return true;
			}
			else
				return false;
}


void PhoneContactVector::listAll() const{
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	for (int i=0; i<(signed)vectorPhoneBook.size(); ++i){
		cout << vectorPhoneBook[i].phoneName << "		"
			 <<	vectorPhoneBook[i].valueInfo.phoneNumber << "	"
			 << vectorPhoneBook[i].valueInfo.emailAddress << endl;
	}
}
int PhoneContactVector::findLoc(string name) const{
	for (int i=0; i<(signed)vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

int PhoneContactVector::findLoc(int number) const{
	for (int i=0; i < (signed)vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].valueInfo.phoneNumber == number)
			return i;
	}
	return -1;

}







