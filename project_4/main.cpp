/*
 * main.cpp
 *
 *  Created on: May 15, 2016
 *      Author: Yongsuk
 */

#include <iostream>
#include "String.h"
#include "PhoneContactList.h"
using namespace std;

/*********************     5개 나만의 데이터 추가      **********************/
String nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
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

int incount = 15;

void testPhoneBookList()
{
	String pbType = "List";
	PhoneContact* pb = &pbList;

	cout << "***Test "+pbType+"PhoneBook***" << endl;

	// Create PhoneBook made of vector and array
	/*nameData[i]+pbType[0]이 안되는 이유: String class의 +operator가 정의되어있지 않다.		 */
	for (int i=0; i < incount; i++){
		if (!pb->insert(nameData[i], numberData[i], emailData[i])){
			cout << "***Error in Insert***" + nameData[i]<< endl;
			};
		}
	cout << "***List All pb1 "+pbType+" PhoneBook" << endl;
	pb->listAll();
	/************  Test 내용     *************/
	/*
	 *  1. += operator
	 *  2. [] operator
	 *  3. Big 3
	 *  4. Node nCount 출력
	 *
	 */

	cout << endl << endl;
	cout <<"*****  Test Examples for Project 4 ***** " << endl << endl;
	PhoneContactList pbList2;
	PhoneContact* pb2 = &pbList2;
	pb2->insert("ADD1", 111111, "ADD1@email.com");
	pb2->insert("ADD2", 222222, "ADD2@email.com");
	pb2->insert("Add3", 333333, "Add3@email.com");
	cout << "***List All pb2 "+pbType+" PhoneBook" << endl;
	pb2->listAll();
	cout << endl;

	//3. Copy Constructor, =operator test
	PhoneContactList pbList3;

	pbList3 = pbList2;
	cout << "***List All pbList3 = pbList2 PhoneBook" << endl;
	pbList3.listAll();
	cout << endl;

	//1. += operator test
	pbList += pbList3;
	cout << "***List All pbList += pbList3 PhoneBook" << endl;
	pbList.listAll();
	cout << endl;

	//2. [] operator test
	cout << "****Testing [] operator" << endl;
	cout << "Finding phonenumber for the name 'ADD1' in pbList : ";
	cout << pbList["ADD1"] << endl;

	cout << "Finding phonenumber for the name 'Lee DI' in pbList : ";
	cout << pbList["Lee DI"] << endl << endl;

	//4. Node n Count 출력
	cout << "Current number of Nodes: " << Node::get_Count() << endl;
	delete(&pbList3);
	cout << "After deleting pbList3..." << endl;
	cout << "Current number of Nodes: " << Node::get_Count() << endl;
	cout << "After deleting pbList2..." << endl;
	delete(&pbList2);
	cout << "Current number of nodes: " << Node::get_Count() << endl;
	cout << "After removing 'ADD1' from pbList..." << endl;
	pb->remove("ADD1");
	cout << "Current number of nodes: " << Node::get_Count() << endl << endl;
	cout << "*******   End of Test Examples   *******" << endl << endl;

	cout << "***List All updated List PhoneBook" << endl;
	pb->listAll();
}

int main()
{
	testPhoneBookList();
	return 0;
}


