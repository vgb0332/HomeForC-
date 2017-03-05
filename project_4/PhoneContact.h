/*
 * PhoneContact.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include "String.h"
using namespace std;

class PhoneContact {
public:
	PhoneContact(){}
	virtual bool insert(String name, int number, String email)=0;
	virtual bool update(String name, int number, String email)=0;
	virtual bool remove(String name)=0;
	virtual ValueInfo find(String name) const=0;
	virtual String findName(int num) const=0; //findName(int num) �Լ� �߰�
	virtual String findName(String email) const=0; //findName(string email) �Լ� �߰�
	virtual bool update(String name, int number)=0;
	virtual bool update(String name, String email) = 0;//email�ּҸ� �ٲٴ� update �Լ� �߰�
	virtual void listAll()const=0;
};



#endif /* PHONECONTACT_H_ */
