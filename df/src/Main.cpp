/*
 * Mian.cpp
 *
 *  Created on: 2016. 11. 10.
 *      Author: Administrator
 */

#include <iostream>
#include "mySet.h"
using namespace std;


int main()
{
	mySet s;
	mySet r(3,"set1");
	r.add(1);
	r.add(2);
	r.add(2);//error_existed value
	r.add(3);
	r.add(4);//error_no space
	r.add(5);//error_no space

	cout<<r.contains(1)<<endl;
	cout<<r.contains(2)<<endl;
	cout<<r.contains(3)<<endl;

	return 0;
}
