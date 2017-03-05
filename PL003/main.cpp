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

//5�� ������ �� �߰�
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
	cout << "***�׽�Ʈ "+pbType+"PhoneBook***" << endl;
	// ����Ʈ�� ���Ϳ� �ʿ� ����
	for (int i=0; i < incount; i++){
		if (!pb->insert(nameData[i]+"-"+pbType[0], numberData[i], emailData[i])){
			cout << "***�Է¿���***" + nameData[i]+"-"+pbType[0]<< endl;
		};
	}

	cout << "***��ȣ ����Ʈ "+pbType+" PhoneBook" << endl;
	pb->listAll();
	cout << endl << "    /////// �׽�Ʈ ���� ////////" << endl;

	if (!pb->update(string("Kim KK-")+pbType[0], 2882, "KK@email.com")){
		cout << "***������Ʈ ���� --" + string("Kim KK-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->insert(string("Go BS-")+pbType[0], 3113, "BD@email.com")){
		cout << "***���� ���� --" + string("Go BS-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->remove(string("���� �׽�Ʈ-")+pbType[0])){
		cout << "***���� ���� --" + string("���� �׽�Ʈ-")+pbType[0] + " ***"<< endl;
	};
	if (!pb->update(string("������Ʈ �׽�Ʈ-")+pbType[0], 0000, "TTTT@email.com")){
			cout << "***������Ʈ ���� --" + string("������Ʈ �׽�Ʈ-")+pbType[0] + " ***"<< endl;
		};
	cout << endl;
	cout << "�̸��Ϸ� �̸� ã��(kimkk@email.com) - " << pb->findName("kimkk@email.com") << endl;
	cout << "��ȣ�� �̸� ã��(1234) - " << pb->findName(1234) << endl;
	cout << "�̸�ã�� ���� - " << pb->findName(112345) << endl;

	cout << endl << "***������Ʈ�� ����Ʈ" << endl;
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



