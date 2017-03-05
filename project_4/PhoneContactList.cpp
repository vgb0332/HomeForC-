/*
 * Entry.cpp
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */



#include <iostream>
#include <string>
//#include <list>
#include "myList.h"
using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull;


PhoneContactList::PhoneContactList() { }


ValueInfo PhoneContactList::find(String name) const {
	CIter iter = findLocConst(name);
		if (iter==contactTable.end())
			return viNull;
		return iter->valueInfo;
}

String PhoneContactList::findName(int number) const{
	CIter iter = findLocConst(number);
		if(iter==contactTable.end())
			return "No such information";
	return iter->phoneName;
}
String PhoneContactList::findName(String email) const{
	CIter iter = findLocConst(email);
			if(iter==contactTable.end())
				return "No such information";
		return iter->phoneName;
}

bool PhoneContactList::insert(String name, int number, String email){
	Iter iter = findLoc(name);
	if (iter != contactTable.end())
		return false;
	contactTable.push_back(Entry(name, number, email));
	return true;
}

bool PhoneContactList::remove(String name){
	Iter iter = findLoc(name);
	if (iter == contactTable.end())
		return false;
	contactTable.erase(iter);
	return true;
}

bool PhoneContactList::update(String name, int number, String email){ //수정
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
bool PhoneContactList::update(String name, String email)
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
bool PhoneContactList::update(String name, int number){ //수정
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
Iter PhoneContactList::findLoc(String name){
	Iter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if ((iter->phoneName == name))
			return iter;
	}
	return iter; // not found, iter==end()
}
CIter PhoneContactList::findLocConst (String name) const {
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

//*******************Big 3 추가
PhoneContactList::~PhoneContactList(){
	Iter iter;
	for(iter = contactTable.begin(); iter!= contactTable.end(); iter++)
	{
		contactTable.erase(iter);
	}
}

PhoneContactList::PhoneContactList(const PhoneContactList& right){
	Iter iter;
	for(iter = right.contactTable.begin(); iter!= right.contactTable.end(); iter++){
		contactTable.push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
	}
}
//PhoneBookList& PhoneBookList::operator=(const PhoneBookList& right)
PhoneContactList& PhoneContactList::operator=(const PhoneContactList& right){
	if(this != &right){
		Iter iter;
		for(iter = right.contactTable.begin(); iter!= right.contactTable.end(); iter++){
				contactTable.push_back(Entry(iter->phoneName, iter->valueInfo.phoneNumber, iter->valueInfo.emailAddress));
			}
	}
	return *this;
}

//***************operator [], += 추가
int PhoneContactList::operator[](String name) const
{
	CIter iter = findLocConst(name);
	return iter->valueInfo.phoneNumber;
}
int& PhoneContactList::operator[](String name)
{
	Iter i = findLoc(name);
	if (i == contactTable.end()){
		contactTable.push_back(Entry(name, -99, ""));
	}
	return i->valueInfo.phoneNumber;
}
PhoneContactList& PhoneContactList::operator+=(const PhoneContactList& right)
{
	Iter ir;
	for(ir = right.contactTable.begin(); ir != right.contactTable.end(); ir++){
		contactTable.push_back(Entry(ir->phoneName, ir->valueInfo.phoneNumber, ir->valueInfo.emailAddress));
	}
	/*
	for (ir=right.pListPhoneBook->begin(); ir!=right.pListPhoneBook->end(); ir++){
		insert(ir->phoneName, ir->phoneNumber);
	}
	*/
   return *this;
}
