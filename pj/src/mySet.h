#include <iostream>
using namespace std;

class mySet{
private:
	int* data;
	int currentSize, sizeMax;
	string name = "Default";
public:
	/* This was for test
	 * int* data;
	 * int currentSize, sizeMax;
	 */

	//Default Constructor
	mySet(){
		cout << "Constructor - Default" << endl;
		sizeMax = 3;
		data = new int[sizeMax];
		currentSize = 0;
	}

	//2nd Constructor : set sizeMax as n
	mySet(int n){
		cout << "Constructor - 2" << endl;
		sizeMax = n;
		data = new int[sizeMax];
		currentSize = 0;
	}

	//3rd Constructor : set sizeMax as n, name as str
	mySet(int n, string str){
		cout << "Constructor - 3" << endl;
		name = str;
		sizeMax = n;
		data = new int[sizeMax];
		currentSize = 0;
	}

	//add func: add value x in data
	void add(int x){
		// if currentSize exceeds the maxSize, print error and abort
		if (currentSize >= sizeMax){
			cout << "Error - no more space" << endl;
			return;
		}
		// if x exists in the data, print error and abort
		if(contains(x)){
			cout << "Error - value already exits " << endl;
			return;
		}
		//Add value x in the data and increase the currentSize by 1
		data[currentSize++] = x;
	}
	//contains func: check if the value x exits in data
	bool contains(int x){
		for(int i = 0; i < currentSize; ++i)
			if(data[i] == x) return true;
		return false;
	}

	//Default Destructor
	~mySet(){
		//Print which Destructor has been called
		cout << "Destructor - " << name << endl;
		delete[] data;
	}
};
