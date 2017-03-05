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
	virtual bool insert(string name, int number, string email)=0;
	virtual bool update(string name, int number, string email)=0;
	virtual bool remove(string name)=0;
	virtual ValueInfo find(string name) const=0;
	virtual string findName(int num) const=0; //findName(int num) 함수 추가
	virtual string findName(string email) const=0; //findName(string email) 함수 추가
	virtual bool update(string name, int number)=0;
	virtual bool update(string name, string email) = 0;//email주소를 바꾸는 update 함수 추가
	virtual void listAll()const=0;
};



#endif /* PHONECONTACT_H_ */
