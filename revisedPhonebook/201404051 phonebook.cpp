/*
 * phonebook.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Yongsuk
 */


/*
 * phonecontactarray.cpp
 *
 *  Created on: 2016. 3. 13.
 *      Author: cskim
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACT_ENTRY = 100;

string nameData[] = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH",
				  "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY",
				  "Jung YS", "Jung MW" , "Kim GH", "Choi EJ", "Hong JM" }; //Chun WY���ķ� 5�� �߰�
int numberData[] = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752,
					5084, 5846, 5475, 5123, 5321}; //��ȣ 5�� �߰�
string emailData[] = {
		"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com",
		"baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com",
		"jungys@email.com", "jungmw@email.com", "kimgh@email.com", "choiej@email.com", "hongjm@email.com"}; //5���߰�

class Entry {
public:
	string phoneName;
	int phoneNumber;
	string emailAddress;
	Entry(){
		phoneName = "";
		phoneNumber = -1;
		emailAddress = "";
	}
	Entry(string s, int n, string em) {
		phoneName = s;
		phoneNumber = n;
		emailAddress = em;
	}
};

class ValueInfo {
public:
	int phoneNumber;
	string emailAddress;
	ValueInfo(int n, string em){
		phoneNumber = n;
		emailAddress = em;
	}
};
Entry arrayPhoneBook[MAX_CONTACT_ENTRY];
int lastp = 0;

void insert(string name, int number, string email);
void remove(string name);
void update(string name, int number, string email);
int findPhoneNumber(string name);
string findEmailAddress(string name);

string findName(int number , string email); //findName ���� ����
string find(int number, string email); //��ȣ�� �̸����ּҷ� �̸��� ã���ִ� �Լ�(�߰�)

int findLoc(string name){
	for (int i=0; i<lastp; ++i){
		if (arrayPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}
int findPhoneNumber(string name){
	int loc = findLoc(name);
	if (loc == -1)
		return -1; // not found
	return arrayPhoneBook[loc].phoneNumber;
}
string findEmailAddress(string name){
	int loc = findLoc(name);
	if (loc == -1)
		return ""; // not found
	return arrayPhoneBook[loc].emailAddress;
}
string findName(int number) //�߰�
{
	 for(int i = 0; i < lastp; i++)
	 {
		 if(arrayPhoneBook[i].phoneNumber == number)
			 return (arrayPhoneBook[i].phoneName);
	 }
	 return "NO MATCHING USER FOUND"; //Error Text
}
string findName(string email) //�߰�
{
	for(int i = 0; i < lastp; i++)
	{
		if(arrayPhoneBook[i].emailAddress == email)
			return arrayPhoneBook[i].phoneName;
	}
	return "NO MATCHING USER FOUND"; //Error Text
}
string findName(int number, string email) //�߰�
{
	for(int i = 0 ; i < lastp; i ++)
	{
		if(arrayPhoneBook[i].phoneNumber == number && arrayPhoneBook[i].emailAddress == email)
			return arrayPhoneBook[i].phoneName;
	}
	return "NO MATCHING USER FOUND"; //Error Text
}
void insert(string name, int number, string email){
	int loc = findLoc(name);
	if (loc == -1){ // insert
		if (lastp > MAX_CONTACT_ENTRY){
			cout << "***Error -- PhoneBook Overflow" << endl;
		}
		else {
			arrayPhoneBook[lastp].phoneName = name;
			arrayPhoneBook[lastp].phoneNumber = number;
			arrayPhoneBook[lastp].emailAddress = email;
			lastp++;
		}
	}
	else {
		cout << "***Error -- Duplicated Name" << endl;
	}
}
void insert(string name, int number) //�߰�����
{
	int loc = findLoc(name);
		if (loc == -1){ // insert
			if (lastp > MAX_CONTACT_ENTRY){
				cout << "***Error -- PhoneBook Overflow" << endl;
			}
			else {
				arrayPhoneBook[lastp].phoneName = name;
				arrayPhoneBook[lastp].phoneNumber = number;
				arrayPhoneBook[lastp].emailAddress = "    EMPTY    ";
				lastp++;
			}
		}
		else {
			cout << "***Error -- Duplicated Name" << endl;
		}
}
void remove(string name){
	int loc = findLoc(name);
	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (int i=loc+1; i<lastp; ++i){
			arrayPhoneBook[i-1].phoneName = arrayPhoneBook[i].phoneName;
			arrayPhoneBook[i-1].phoneNumber = arrayPhoneBook[i].phoneNumber;
			arrayPhoneBook[i-1].emailAddress = arrayPhoneBook[i].emailAddress;
		}
		lastp--;
	}
	else {
		cout << "***Error -- Name not found" << endl;
	}
}
void update(string name, int number, string email){//��������
	int loc = findLoc(name);
	int newNumber = number;
		string newEmailAddress = email;
	if(loc == -1)
		cout << "ERROR! THERE IS NO MATCHING NAME USER" << endl;
	else{
		arrayPhoneBook[loc].phoneNumber = newNumber;
		arrayPhoneBook[loc].emailAddress = newEmailAddress;
	}
	//remove(name);
	//insert(name, number, email);
}
void update(string name, int number){//�̰͵� ��������;
	int loc = findLoc(name);
	int newNumber = number;

	if(loc == -1)
		cout << "***Error -- No matching user name" << endl;
	else
	{
		arrayPhoneBook[loc].phoneNumber = newNumber;
	}

}
void update(string name, string email){ //�̰͵� ��������;

	int loc = findLoc(name);
		string newEmailAddress = email;

		if(loc == -1)
			cout << "ERROR" << endl;
		else
		{
			arrayPhoneBook[loc].emailAddress = newEmailAddress;
		}

}
void listAll(){

	cout << "Name" << "		" << "Number" << "	"<< "Email" << endl;
	for (int i=0; i<lastp; ++i){
		cout << arrayPhoneBook[i].phoneName << "		"
			 <<	arrayPhoneBook[i].phoneNumber << "	"
			 << arrayPhoneBook[i].emailAddress << endl;
	}
}

int main ()
{
	int incount = 15; //10 -> 15�� �ٲ�
	for (int i=0; i < incount; ++i){
		insert(nameData[i], numberData[i], emailData[i]);
	}
	cout << "List All Inserted Entry" << endl;

	listAll();

	remove("Park SH");          //���� 5
	remove("Kang JH");          //���� 5
	remove("Kim KS");           //���� 5
	insert("Won GS", 5462);     //���� 6
	insert("Kwon KY", 5825);    //���� 6
	insert("Kim MG", 5957);     //���� 6
	insert("Jung YS", 5);       //���� 6
	insert("Lee SH", 5068);     //���� 6: �ߺ� �׽�Ʈ
	update("Jung YS", 5457);    //���� 7

	insert("Lee YH", 5000);     //���� 8
	remove("Lee YH");           //���� 8
	update("Lee YH", 5068);     //���� 8


	cout << endl;
	cout << "List All Updated Entry" << endl;
	listAll();                  //���� 9
	return 0;
}

