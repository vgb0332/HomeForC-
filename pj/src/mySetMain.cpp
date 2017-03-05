//============================================================================
// Name        : pj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "mySet.h"
using namespace std;

int main() {
	mySet s;
	mySet r(3, "set1");
	r.add(1);
	r.add(2);
	r.add(2);//ERROR
	r.add(3);
	r.add(4);//ERROR
	r.add(5);//ERROR

	for(int i = 1; i <= 3; ++i){
		if(r.contains(i)) cout << "True" << endl;
		else cout << "False" << endl;
	}
	/*
	cout << r.contains(1) << endl;
	cout << r.contains(2) << endl;
	cout << r.contains(3) << endl;
	*/
	return 0;
}
