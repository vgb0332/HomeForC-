// QuickSort.cpp
//

#include <string>
#include <iostream>
#include <cassert>

#include "List.h"

using namespace std;

const int  LINE_MAX = 13;
/* 이미 Card.h에 정의되어있으므로 삭제해도 무관하다.
//enum PIP { ACE=1, JACK=11, QUEEN, KING };
//enum SUIT { CLUB=1, DIAMOND, HEART, SPADE };
string cardimage (int suit, int rank) {
	string image;
	switch (suit) {
	case CLUB:		image = "C"; break;
	case DIAMOND:	image = "D"; break;
	case HEART:		image = "H"; break;
	case SPADE:		image = "S"; break;
	}
	switch (rank) {
	case ACE:	image += "A "; break;
	case JACK:	image += "J "; break;
	case QUEEN:	image += "Q "; break;
	case KING:	image += "K "; break;
	case 10:	image += "10"; break;
	default:	image = image + (char)('0'+rank) + " ";
	}
	return image;
}
*/
void printList(List L)
{
	int i = 0;
	for (Iterator cp = L.begin(); cp!=L.end(); cp.next()) {
		cout << cp.get() << " ";
		i++;
		if (i % LINE_MAX == 0) cout << endl;
	}
	cout << endl;
}

void quickSort (List& L)
{
	int n = L.size();
	if (n < 2)
		return;

	List L1;
	List L2;
	List Le;

	Iterator last = L.end();
	last.previous();
	Card pivot = last.get();

	Iterator li = L.begin();
	while (!L.empty()) {
		if (li.get() < pivot) {
			L1.push_back(li.get());
		}
		else if (li.get() == pivot) {
			Le.push_back(li.get());
		}
		else {
			L2.push_back(li.get());
		}
		li = L.erase(li);
	}
	quickSort(L1);
	quickSort(L2);

	li = L1.begin();
	while (!L1.empty()) {
		L.push_back(li.get());
		li = L1.erase(li);
	}
	li = Le.begin();
	while (!Le.empty()) {
		L.push_back(li.get());
		li = Le.erase(li);
	}
	li = L2.begin();
	while (!L2.empty()) {
		L.push_back(li.get());
		li = L2.erase(li);
	}

}
void quickSortTest(){
	List deck;

	// Make a Card Deck
	// 수정부분: deck.push_back(card)로 기존의 string을 인자로 받는 방식에서 바뀌었다.
	for (int s=CLUB; s<=SPADE; s++)
		for (int r=ACE; r<=KING; r++){
			deck.push_back(Card(s,r));
		}
	// Display the Deck
	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;

	quickSort(deck);

	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;
}
int main()
{
	quickSortTest();
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();

	return 0;
}

