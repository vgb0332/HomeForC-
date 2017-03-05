/*
 * PhoneContactList.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

//#include <list>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
#include "myList.h"

//Iterator와 const Iterator 알맞게 재선언
typedef Iterator Iter;
typedef const Iterator CIter;

//typedef list<Entry>::iterator Iter;   삭제
//typedef list<Entry>::const_iterator CIter;   삭제

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
	//Big 3 추가
	~PhoneContactList();
	PhoneContactList(const PhoneContactList& right);
	PhoneContactList& operator=(const PhoneContactList& right);

	ValueInfo find(string name) const;
	string findName(int number) const;
	string findName(string email) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	bool update(string name, string email);

	//operator [], += 추가
	int operator[](string name)const;
	int& operator[](string name);
	PhoneContactList& operator+=(const PhoneContactList& right);

	void listAll() const;
private:
	//list<Entry> contactTable;
	List contactTable;
	friend List;
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findLocConst (int number) const;

};




#endif /* PHONECONTACTLIST_H_ */
