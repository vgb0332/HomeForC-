
/*
 * PhoneContactMap.cpp
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "Entry.h"
#include "PhoneContactMap.h"

extern ValueInfo viNull;

PhoneContactMap::PhoneContactMap() { }

ValueInfo PhoneContactMap::find(string name) const {
	CMIter iter;
	for(iter = contactTable.begin(); iter != contactTable.end(); iter++)	{
		if(iter == contactTable.find(name))
			return contactTable.at(name);
	}
	return viNull;
}

string PhoneContactMap::findName(int number) const {
	CMIter iter;
	for(iter = contactTable.begin(); iter != contactTable.end(); iter++) {
		if((iter->second.phoneNumber) == number)
			return iter->first;
	}
	return "No Name Found";

}

string PhoneContactMap::findName(string email) const {
	CMIter iter;
	for(iter = contactTable.begin(); iter != contactTable.end(); iter++) {
		if((iter->second.emailAddress) == email)
			return iter->first;
	}
	return "No Name Found";

}
bool PhoneContactMap::insert(string name, int number, string email){ //¼öÁ¤ÇØ¾ßµÊ
	MIter iter = contactTable.find(name);
		if(iter != contactTable.end())
			return false;
	contactTable[name] = ValueInfo(number, email);
	return true;
}

bool PhoneContactMap::remove(string name){
	MIter iter = contactTable.find(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactMap::update(string name, int number, string email){
	MIter iter = contactTable.find(name);
	if(iter == contactTable.end())
		return false;
	contactTable[name] = ValueInfo(number, email);
	return true;
}

bool PhoneContactMap::update(string name, string email){
	MIter iter = contactTable.find(name);
		if(iter == contactTable.end())
			return false;
		contactTable[name].emailAddress = email;
		return true;
}

bool PhoneContactMap::update(string name, int number){
	MIter iter = contactTable.find(name);
		if(iter == contactTable.end())
			return false;
		contactTable[name].phoneNumber = number;
		return true;
}

void PhoneContactMap::listAll() const {
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	CMIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->first << "		"
				<<	iter->second.phoneNumber << "	"
				<< iter->second.emailAddress << endl;
	}
}

