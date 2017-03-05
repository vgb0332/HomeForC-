/*
 * PhoneContactList.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

//#include <list> 삭제
#include "Entry.h"
#include "ListPL.h"
#include "PhoneContact.h"

//Iter와 CIter 수정
typedef Iterator Iter;
typedef const Iterator CIter;

class PhoneContactList: public PhoneContact {
private:
	//list<Entry> contactTable -> List contactTable
	List contactTable;
	friend List;
	Iter findLoc(string name);
	CIter findLocConst (string name) const;
	CIter findLocConst (int number) const;
public:
	PhoneContactList();
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	bool update(string name, string email);
	ValueInfo find(string name) const;
	string findName(int number) const;
	string findName(string email) const;
	void listAll() const;
};




#endif /* PHONECONTACTLIST_H_ */
