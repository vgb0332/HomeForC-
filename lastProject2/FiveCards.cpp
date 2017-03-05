//
// Programmed by cskim HUFS.ac.kr 2008/5/6
//

#include "FiveCards.h"
Card FIVEHIGHCARD[] = { Card(1,15), Card(1,15), Card(1,15), Card(1,15), Card(1,15) };
FiveCards& FiveCards::getHighValue(){
	FiveCards* p5Cards = new FiveCards();
	p5Cards->pelem = FIVEHIGHCARD;
	return *p5Cards;
}
FiveCards::FiveCards() {
	pelem = new Card[FIVE];
}
FiveCards::FiveCards(const FiveCards& right) {
	pelem = new Card[FIVE];
	 for(int i=0; i<FIVE; ++i)
		 pelem[i] = right.pelem[i];
}

FiveCards& FiveCards::operator=(const FiveCards& right) {
	if(this != &right) {
		delete[] pelem;
		pelem = new Card[FIVE];
		for(int i=0; i<FIVE; ++i)
			pelem[i]=right.pelem[i];
	}
	return *this;
}
FiveCards::~FiveCards() {
	delete[] pelem;
}
Card& FiveCards::operator[](int index) {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

Card FiveCards::operator[](int index) const {
	assert((index >= 0) && (index < FIVE));
	return pelem[index];
}

int FiveCards::compare(const FiveCards& right) const {
	return pelem[0].compare(right[0]);
}
/*
int FiveCards::toOrder() const {
	//포커 순 추가
	/* 노페어: 0
	 * 원페어: 1
	 * 투페어: 2
	 * 트리플: 3
	 * 스트레이트: 4
	 * 백스트레이트: 5
	 * 마운틴: 6
	 * 플러쉬: 7
	 * 풀하우스: 8
	 * 포카드: 9
	 * 스트레이트 플러쉬: 10
	 * 백스트레이트 플러쉬: 11
	 * 로얄스트레이트 플러쉬: 12
	 *
	enum ORDER {NOPAIR = 0,ONEPAIR,TWOPAIR,TRIPLE,STRAIGHT,BSTRAIGHT,MOUNTAIN,FLUSH,FULLHOUSE,
		FOURCARD,STFLUSH,BSTFLUSH,ROYALSTFLUSH};
}
*/
string FiveCards::tostring() const {

	string result = "[";
	for(int i=0; i<FIVE; ++i) {
		 if ( i != 0 ) result+=", ";
		 result += pelem[i].tostring();
	}
	result += "]\n";
	return result;
}

bool operator<(const FiveCards& left, const FiveCards& right)  {
   return left.compare(right) < 0;
}
bool operator>(const FiveCards& left, const FiveCards& right)  {
   return left.compare(right) > 0;
}

ostream& operator<<(ostream& out, const FiveCards& cards) {
	out << cards.tostring();

	return out;
}
bool operator==(const FiveCards& left, const FiveCards& right)  {
	for(int i = 0; i < FIVE; i++){
		if(left[i] != right[i])
			return false;
		return true;
	}

	return false;
}

