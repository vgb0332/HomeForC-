//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//
#ifndef MY_FIVECARDS_H
#define MY_FIVECARDS_H
#include <cassert>
#include "Card.h"
//Card FIVEHIGHCARD[] = { Card(1,15), Card(1,15), Card(1,15), Card(1,15), Card(1,15) };
const int FIVE = 5;

template <typename T>
class FiveCards {
public:
	FiveCards();
	FiveCards(const FiveCards& r);
	FiveCards& operator=(const FiveCards& r);
	Card<T>& operator[](int i);
	Card<T> operator[](int i) const;
	~FiveCards();
	int compare(const FiveCards& right) const;
	string tostring() const;

	static FiveCards& getHighValue();
private:
	Card<T>* pelem;

};
//template <typename T>
//Card<int> FIVEHIGHCARD[] = { Card(1,15), Card(1,15), Card(1,15), Card(1,15), Card(1,15) };

template <typename T>
FiveCards<T>::FiveCards(){
	pelem = new Card<T>[FIVE];
}
template <typename T>
FiveCards<T>::~FiveCards(){
	delete[] pelem;
}
template <typename T>
FiveCards<T>::FiveCards(const FiveCards<T>& right){
	pelem = new Card<T>[FIVE];
		 for(int i=0; i<FIVE; ++i)
			 pelem[i] = right.pelem[i];
}
template <typename T>
FiveCards<T>& FiveCards<T>::operator =(const FiveCards<T>& right){
	if(this != &right) {
			delete[] pelem;
			pelem = new Card<T>[FIVE];
			for(int i=0; i<FIVE; ++i)
				pelem[i]=right.pelem[i];
		}
	return *this;
}
template <typename T>
Card<T>& FiveCards<T>::operator [](int index){
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}
template <typename T>
Card<T> FiveCards<T>::operator [](int index) const{
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}
template <typename T>
int FiveCards<T>::compare(const FiveCards<T>& right) const{
	return pelem[0].compare(right[0]);
}
template <typename T>
string FiveCards<T>::tostring() const{
	string result = "[";
		for(int i=0; i<FIVE; ++i) {
			 if ( i != 0 ) result+=", ";
			 result += pelem[i].tostring();
		}
		result += "]\n";
		return result;
}
//template <typename T>
//FiveCards<T>& FiveCards<T>::getHighValue(){
//	FiveCards<T>* p5Cards = new FiveCards();
//	p5Cards->pelem = FIVEHIGHCARD;
//	return *p5Cards;
//}
template <typename T>
bool operator<(const FiveCards<T>& left, const FiveCards<T>& right){
	return left.compare(right) < 0;
}
template <typename T>
bool operator>(const FiveCards<T>& left, const FiveCards<T>& right){
	return left.compare(right) > 0;
}
template <typename T>
ostream& operator<<(ostream& out, const FiveCards<T>& value){
	out << value.tostring();
	return out;
}

#endif
