/*
 * Entry.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */



#include <iostream>
#include <string>
//#include <list>

#include "ListPL.h"
using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull;


PhoneContactList::PhoneContactList() { }

ValueInfo PhoneContactList::find(string name) const {
	CIter iter = findLocConst(name);
		if (iter==contactTable.end())
			return viNull;
		return iter->valueInfo;
}

string PhoneContactList::findName(int number) const{
	CIter iter = findLocConst(number);
		if(iter==contactTable.end())
			return "No such information";
	return iter->phoneName;
}
string PhoneContactList::findName(string email) const{
	CIter iter = findLocConst(email);
			if(iter==contactTable.end())
				return "No such information";
		return iter->phoneName;
}
bool PhoneContactList::insert(string name, int number, string email){
	Iter iter = findLoc(name);
	if (iter != contactTable.end())
		return false;
	contactTable.push_back(Entry(name, number, email));
	return true;
}

bool PhoneContactList::remove(string name){
	Iter iter = findLoc(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactList::update(string name, int number, string email){ //수정
	Iter iter;
	for(iter=contactTable.begin(); iter!=contactTable.end(); iter++)
		if(iter == findLoc(name))
		{
			iter->valueInfo.phoneNumber = number;
			iter->valueInfo.emailAddress = email;
			return true;
		}
	return false;
}
bool PhoneContactList::update(string name, string email)
{
	Iter iter;
		for(iter=contactTable.begin(); iter!=contactTable.end(); iter++)
			if(iter == findLoc(name))
			{
				iter->valueInfo.emailAddress = email;
				return true;
			}
		return false;
}
bool PhoneContactList::update(string name, int number){ //수정
	Iter iter;
	for(iter=contactTable.begin(); iter!=contactTable.end(); iter++)
		if(iter == findLoc(name))
		{
			iter->valueInfo.phoneNumber = number;
			return true;
		}
	return false;
}

void PhoneContactList::listAll() const{
	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		cout << iter->phoneName << "		"
				<<	iter->valueInfo.phoneNumber << "	"
				<< iter->valueInfo.emailAddress << endl;
	}
}
Iter PhoneContactList::findLoc(string name){
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if ((iter->phoneName == name))
			return iter;
	}
	return iter; // not found, iter==end()
}
CIter PhoneContactList::findLocConst (string name) const {
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){ //추가했음 밑에 이메일주소도 받게
		if (iter->phoneName == name || (iter->valueInfo.emailAddress == name))
			return iter;
	}
	return iter; // not found, iter==end()
}

CIter PhoneContactList::findLocConst (int number) const {
	Iter iter;
		for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
			if (iter->valueInfo.phoneNumber == number)
				return iter;
		}
		return iter; // not found, iter==end()
}
