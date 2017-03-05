/*
 * Entry.h
 *
 *  Created on: Apr 5, 2016
 *      Author: Yongsuk
 */

#ifndef ENTRY_H_
#define ENTRY_H_

//string -> String
//#include <string>
#include "String.h"
using namespace std;

class ValueInfo {
public:
	int phoneNumber;
	String emailAddress;
	ValueInfo(){
		phoneNumber = -99;
	}
	ValueInfo(int n, String em){
		phoneNumber = n;
		emailAddress = em;
	}
};
class Entry {
public:
	String phoneName;
	ValueInfo valueInfo;
	Entry(){
		phoneName = "";
		valueInfo.phoneNumber = -1;
		valueInfo.emailAddress = "";
	}
	Entry(String s, int n, String em) {
		phoneName = s;
		valueInfo.phoneNumber = n;
		valueInfo.emailAddress = em;
	}
};



#endif /* ENTRY_H_ */
