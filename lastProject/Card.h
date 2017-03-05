//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//
#ifndef MY_CARD_H
#define MY_CARD_H

#include <iostream>
#include <string>
#include "String.h"
using namespace std;

enum PIP { ACE=1, JACK=11, QUEEN, KING };
enum SUIT { CLUB=1, DIAMOND, HEART, SPADE };

template <typename T>
class Card {
private:
	SUIT	suit;
	PIP		rank;

public:
	Card ();
	Card (int s, int r);
	string	tostring() const;
	String<T> toString() const;
	//ostream& outstr(ostream& sout) const;
	int compare (const Card& c) const;
	static Card getHighValue(); // New
};

template <typename T>
Card<T>::Card(){
	suit = SPADE;
	rank = ACE;
}
template <typename T>
Card<T>:: Card(int s, int r){
	suit = (SUIT) s;
	rank = (PIP) r;
}
template <typename T>
string Card<T>::tostring() const{
	string image;
		switch (suit) {
			case CLUB:		image = "CL "; break;
			case DIAMOND:	image = "DI "; break;
			case HEART:		image = "HE "; break;
			case SPADE:		image = "SP "; break;
		}
		switch ((int)rank) {
			case ACE:	image += "A "; break;
			case JACK:	image += "J "; break;
			case QUEEN:	image += "Q "; break;
			case KING:	image += "K "; break;
			case 10:	image += "10"; break;
			default:	image = image + (char)('0'+rank) + " ";
		}
		return image;
}
template <typename T>
String<T> Card<T>::toString() const{
	String<T> image;
		switch (suit) {
		case CLUB:		image = "CL "; break;
		case DIAMOND:	image = "DI "; break;
		case HEART:		image = "HE "; break;
		case SPADE:		image = "SP "; break;
	}
	switch ((int)rank) {
		case ACE:	image += "A "; break;
		case JACK:	image += "J "; break;
		case QUEEN:	image += "Q "; break;
		case KING:	image += "K "; break;
		case 10:	image += "10"; break;
		default:	image = image + ((T)('0'+(int)rank) + String<T>(" "));
		}
		return image;
}
template <typename T>
int Card<T>::compare(const Card<T>& right) const{
	int lrank, rrank;
		if (rank == ACE )
			lrank = KING + 1;
		else
			lrank = rank;

		if (right.rank == ACE )
			rrank = KING + 1;
		else
			rrank = right.rank;

		int diff = lrank - rrank;
		return diff;
}
template <typename T>
Card<T> Card<T>::getHighValue(){
	return Card(1,15);
}

template <typename T>
bool operator<(const Card<T>& left, const Card<T>& right){
	return left.compare(right) < 0;
}
template<typename T>
bool operator<=(const Card<T>& left, const Card<T>& right){
	return left.compare(right) <= 0;
}
template <typename T>
bool operator==(const Card<T>& left, const Card<T>& right){
	return left.compare(right) == 0;
}
template <typename T>
bool operator!=(const Card<T>& left, const Card<T>& right){
	return left.compare(right) != 0;
}
template <typename T>
bool operator>=(const Card<T>& left, const Card<T>& right){
	return left.compare(right) >= 0;
}
template <typename T>
bool operator>(const Card<T>& left, const Card<T>& right){
	return left.compare(right) > 0;
}
template <typename T>
ostream& operator<<(ostream& out, const Card<T>& card){
	out << card.tostring();
	return out;
}

#endif
