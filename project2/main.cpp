/*
 * main.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: cskim
 */

#include <iostream>
#include "String.h"

using namespace std;

#include "PhoneContactList.h"
#include "PhoneContactMap.h"
#include "CPhoneContact.h"

/*********************     5개 나만의 데이터 추가      **********************/
string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				      "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY",
				      "Kim JH", "Jung MW", "Jung YS", "Choi EJ", "Hong JM"};

int numberData[] = {5023, 5002, 5008, 5067, 5038,
					5381, 5125, 5165, 5684, 5752,
					1111, 2222, 3333, 4444, 5555};

String emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com",
		"kimjh@email.com", "jungmw@email.com", "jungys@email.com", "choiej@email.com", "hongjm@email.com"};

PhoneContactList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 15;
void testPhoneBook(PhoneContact* pb, String pbType){
	cout << "***Test "+pbType+"PhoneBook***" << endl;

	// Create PhoneBook made of vector and array
	for (int i=0; i < incount; i++){
		if (!pb->insert(nameData[i]+"-"+"L", numberData[i], emailData[i])){
			cout << "***Error in Insert***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}

	cout << "***List All "+pbType+" PhoneBook" << endl;
	pb->listAll();
	cout << endl << "    /////// ERROR TESTS ////////" << endl;

	//중복된 이름을 insert 대신 update로 다시 수정
	if (!pb->update(string("Jung MW-")+pbType[0], 4321, "UPDATED@email.com    **EDITED**")){
		cout << "***Error in Update --" + string("Jung MW-")+pbType[0] + " ***"<< endl;
	};
	//테스트 데이터 추가 -- insert(중복)
	if (!pb->insert(string("Hong JM-")+pbType[0], 5555, "ADD TEST@email.com")){
		cout << "***Error in Insert --" + string("Hong JM-")+pbType[0] + " ***"<< endl;
	};
	//테스트 데이터 추가 -- remove(중복)
	if (!pb->remove(string("REMOVE TEST-")+pbType[0])){
		cout << "***Error in Remove --" + string("REMOVE TEST-")+pbType[0] + " ***"<< endl;
	};
	//테스트 데이터 추가 -- update(없는 이름)
	if (!pb->update(string("UPDATE TEST-")+pbType[0], 0000, "UPDATE TEST@email.com   **TEST**")){
			cout << "***Error in Update --" + string("UPDATE TEST-")+pbType[0] + " ***"<< endl;
		};
	cout << endl;
	//findName(string email) 테스트
	cout << "Finding Name by Email(hongjm@email.com) - " << pb->findName("hongjm@email.com") << endl;
	//findName(int number) 테스트
	cout << "Finding Name by Number(4444) - " << pb->findName(4444) << endl;
	//findName 오류 테스트
	cout << "Finding Name Error test - " << pb->findName(112345) << endl;

	cout << endl << "***List All Updated Entry" << endl;
	pb->listAll();

}

void testPhoneBookList(PhoneContact* pb){
	string pbType = "List";
	cout << "***Test "+pbType+"PhoneBook***" << endl;

		// Create PhoneBook made of vector and array
		for (int i=0; i < incount; i++){
			if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){
				cout << "***Error in Insert***" + nameData[i]+"-"+pbType[0]<< endl;
			};
		}

		cout << "***List All "+pbType+" PhoneBook" << endl;
		pb->listAll();

		/* project-4 테스트 내용
		 *
		 * 1. operator+=, [] 테스트
		 * 2. Big3 테스트
		 * 3.
		 *
		 */

		cout << endl << "***List All Updated Entry" << endl;
		pb->listAll();


}
int main ()
{
	/*
	PhoneContact* pBooks[] = { &pbList , &pbMap , &pbVector };
	string pbTypes[] = { "List", "Map", "Vector" };

	for (int i=0; i<3; ++i){
		testPhoneBook(pBooks[i], pbTypes[i]);
		cout << endl;
	}
	*/
	testPhoneBookList(&pbList);


	return 0;
}



