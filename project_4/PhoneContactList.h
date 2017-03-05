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

//Iterator�� const Iterator �˸°� �缱��
typedef Iterator Iter;
typedef const Iterator CIter;

//typedef list<Entry>::iterator Iter;   ����
//typedef list<Entry>::const_iterator CIter;   ����

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
	//Big 3 �߰�
	~PhoneContactList();
	PhoneContactList(const PhoneContactList& right);
	PhoneContactList& operator=(const PhoneContactList& right);

	ValueInfo find(String name) const;
	String findName(int number) const;
	String findName(String email) const;
	bool insert(String name, int number, String email);
	bool remove(String name);
	bool update(String name, int number, String email);
	bool update(String name, int number);
	bool update(String name, String email);

	//operator [], += �߰�
	int operator[](String name)const;
	int& operator[](String name);
	PhoneContactList& operator+=(const PhoneContactList& right);

	void listAll() const;
private:
	//list<Entry> contactTable;
	List contactTable;
	friend List;
	Iter findLoc(String name);
	CIter findLocConst (String name) const;
	CIter findLocConst (int number) const;

};




#endif /* PHONECONTACTLIST_H_ */
