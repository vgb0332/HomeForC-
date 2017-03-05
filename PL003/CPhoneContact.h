/*
 * CPhoneContact.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef CPHONECONTACT_H_
#define CPHONECONTACT_H_

#include <vector>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
class PhoneContactVector : public PhoneContact{
public:
	PhoneContactVector();
	ValueInfo find(string name) const;
	string findName(int number) const;
	string findName(string email) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	bool update(string name, string email);
	void listAll() const;
private:
	vector<Entry> vectorPhoneBook;
	int findLoc(string name) const;
	int findLoc(int number) const;
};


#endif /* CPHONECONTACT_H_ */
