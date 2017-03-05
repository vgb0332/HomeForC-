/*
 * PhoneContactMap.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef PHONECONTACTMAP_H_
#define PHONECONTACTMAP_H_
/*
 * PhoneContactMap.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */
#include <map>
#include "Entry.h"
#include "PhoneContact.h"

typedef map<string, ValueInfo>::const_iterator CMIter;
typedef map<string, ValueInfo>::iterator MIter;


class PhoneContactMap: public PhoneContact {
public:
	PhoneContactMap();
	ValueInfo find(string name) const;
	string findName(int num) const;
	string findName(string email) const;
	bool insert(string name, int number, string email);
	bool remove(string name);
	bool update(string name, int number, string email);
	bool update(string name, int number);
	bool update(string name, string email);
	void listAll() const;
private:
	map<string, ValueInfo> contactTable;
};

#endif /* PHONECONTACTMAP_H_ */






