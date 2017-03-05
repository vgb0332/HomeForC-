/*
 *
 *  Created on: Mar 30, 2012
 *      Author: cskim
 */

#include <iostream>
#include <string>

using namespace std;

#include "PhoneContactList.h"
#include "PhoneContactMap.h"
#include "CPhoneContact.h"

//5개 임의의 값 추가
string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				      "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY",
				      "Kim KK", "Lee MS", "Jung JY", "Go BS", "Park JY"};

int numberData[] = {5023, 5002, 5008, 5067, 5038,
					5381, 5125, 5165, 5684, 5752,
					1234, 4321, 4567, 7654, 8765};

string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com",
		"kimkk@email.com", "leems@email.com", "jungjy@email.com", "gobs@email.com", "parkjy@email.com"};

PhoneContactList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 15;
void testPhoneBook(PhoneContact* pb, string pbType){
	cout << "***테스트 "+pbType+"PhoneBook***" << endl;
	// 리스트와 벡터와 맵에 삽입
	for (int i=0; i < incount; i++){
		if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){
			cout << "***입력오류***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}

	cout << "***번호 리스트 "+pbType+" PhoneBook" << endl;
	pb->listAll();
	cout << endl << "    /////// 테스트 오류 ////////" << endl;

	if (!pb->update(string("Kim KK-")+pbType[0], 2882, "KK@email.com")){
		cout << "***업데이트 오류 --" + string("Kim KK-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->insert(string("Go BS-")+pbType[0], 3113, "BD@email.com")){
		cout << "***삽입 오류 --" + string("Go BS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->remove(string("삭제 테스트-")+pbType[0])){
		cout << "***삭제 오류 --" + string("삭제 테스트-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->update(string("업데이트 테스트-")+pbType[0], 0000, "TTTT@email.com")){
			cout << "***업데이트 오류 --" + string("업데이트 테스트-")+pbType[0] + " ***"<< endl;
		};
	cout << endl;
	cout << "이메일로 이름 찾기(kimkk@email.com) - " << pb->findName("kimkk@email.com") << endl;
	cout << "번호로 이름 찾기(1234) - " << pb->findName(1234) << endl;
	cout << "이릅찾기 오류 - " << pb->findName(112345) << endl;

	cout << endl << "***업데이트된 리스트" << endl;
	pb->listAll();

}

int main ()
{

	PhoneContact* pBooks[] = { &pbList , &pbMap , &pbVector };
	string pbTypes[] = { "List", "Map", "Vector" };

	for (int i=0; i<3; ++i){
		testPhoneBook(pBooks[i], pbTypes[i]);
		cout << endl;
	}

	return 0;
}



