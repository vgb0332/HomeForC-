/*
 * String.h
 *
 *  Created on: Apr 25, 2012
 *      Author: cskim
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class String {
public:
	String(); // Default constructor
	String(const T p[]); // Simple constructor
	String(const String& right); // Copy constructor
	~String(); // Destructor
	String& operator=(const String& right); // Assignment operator

	String& operator+=(const String& right);
	int length() const;
	int size() const;
	T& operator[](int index);
	T operator[](int index) const;

	int compare(const String& right) const;

	string tostring() const;
	ostream& outstr(ostream& sout) const;
	String substr(int pos, int nlen) const;

	static String getHighValue(); // New
private:
	T* buffer;
	int len;
};

template <typename T>
String<T> ::String(){
	//cout << "Default Constructor Called\n";
		len = 0;
		buffer = new T[0]; // No need to allocate array to hold zero characters
}

template <typename T>
String<T> ::~String(){
	//cout << "Destructor Called str=";
		//cout << *this << endl;

		delete[] buffer;
}

template <typename T>
String<T> ::String(const T p[]){
	// Determine number of characters in string (strlen(p))
		//cout << "Char Array Constructor Called str=";
		len = 0;
		while (p[len] != '\0')
			len++;
		// Allocate buffer array, remember to make space for NULL character
		buffer = new T[len + 1];
		// Copy new characters (strcpy( buffer, p ))
		for (int i = 0; i < len; i++)
			buffer[i] = p[i];
		buffer[len] = '\0';
		//cout << *this << endl;
}

template <typename T>
String<T> ::String(const String& right){
	//cout << "Copy Constructor Called str=";
		int n = right.length();
		len = n;
		buffer = new T[n + 1];
		for (int i = 0; i < n; i++)
			buffer[i] = right[i];
		buffer[n] = '\0';
		//cout << *this << endl;
}

template <typename T>
String<T>& String<T>:: operator=(const String& right){
	//cout << "Assignment Oper. Called str=";
		if (this != &right) {
			delete[] buffer; // Get rid of old buffer
			len = right.length();
			buffer = new T[len + 1];
			for (int i = 0; i < len; i++)
				buffer[i] = right[i];
			buffer[len] = '\0';
		}
		else {
			//cout << "assign op--same var assign \n";
		}
		//cout << *this << endl;
		return *this;
}

template <typename T>
String<T>& String<T>:: operator+=(const String& right){
	T* newbuf = new T[len+right.length()+1];
		for (int i = 0; i < len; i++)
			newbuf[i] = buffer[i];
		for (int i = 0; i < right.length(); i++)
			newbuf[len+i] = right[i];

		delete[] buffer; // Get rid of old buffer

		len += right.length();
		buffer = newbuf;
		buffer[len] = '\0';
		return *this;
}

template <typename T>
int String<T>::length() const{
	return len;
}

template <typename T>
int String<T>::size() const{
	return len;
}

template <typename T>
T& String<T>::operator [](int index) {
	return buffer[index];
}

template <typename T>
T String<T>::operator [](int index) const{
	return buffer[index];
}

template <typename T>
int String<T>::compare(const String<T>& right) const{
	return std::strcmp(buffer, right.buffer);
}

template <typename T>
string String<T>::tostring() const{
	return string(buffer);
}

template <typename T>
ostream& String<T>::outstr(ostream& sout) const{
	for (int i = 0; i < len; ++i)
			sout << buffer[i];
		return sout;
}

template <typename T>
String<T> String<T>::substr(int pos, int nlen) const{
	T* subbuf = new T[nlen+1];
		for (int i=0; i<nlen; ++i){
			subbuf[i] = buffer[pos+i];
		}
		subbuf[nlen] = '\0';
		return String(subbuf);
}

template <typename T>
String<T> String<T>::getHighValue(){
	return String("zzzz");
}

template <typename T>
String<T> operator+(const String<T>& left, const String<T>& right){
	String<T> res = left;
	res+=right;
	return res;
}

template <typename T>
String<T> operator+(T left, const String<T>& right){
	T* subbuf = new T[2];
	subbuf[0] = left;
	subbuf[1] = '\0';
	String<T> res = String<T>(subbuf);
	res+=right;
	return res;
}
//ostream& operator<<(ostream& out, const String& str);
//bool operator<(const String& left, const String& right);
//bool operator<=(const String& left, const String& right);
//bool operator==(const String& left, const String& right);
//bool operator!=(const String& left, const String& right);
//bool operator>=(const String& left, const String& right);

template <typename T>
bool operator>(const String<T>& left, const String<T>& right){
	return left.compare(right)>0;
}

#endif /* MY_STRING_H_ */
