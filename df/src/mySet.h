/*
 * mySet.h
 *
 *  Created on: 2016. 11. 10.
 *      Author: Administrator
 */

#ifndef MYSET_H_
#define MYSET_H_

#include <iostream>
using namespace std;

class mySet{

private:
	int *data;	// 동적할당 data
	int currentSize, sizeMax;	//현재크기 , 집합의 크기
	string name;	// 집합의 이름을 위한 변수
public:

	mySet()	//default 설정자
	{
		cout<<"default Constructor"<<endl;
		name = "default";	//이름을 defalut로 설정
		sizeMax = 3;	//총 집합�� 크기는 3
		data = new int[sizeMax];	//동적할당
		currentSize = 0;
	}

	mySet(int n)	// 설정자 ver2
	{
		cout<<"Constructor2"<<endl;
		name = "default"; //이름은 default로 설정
		sizeMax = n;	//입력받은 n만큼 크기설정
		data = new int[sizeMax];//동적할당
		currentSize = 0;//현재크기는 0
	}

	mySet(int n, string str)	// 설정자 ver3
	{
		cout<<"Constructor3"<<endl;
		name = str;	//입력받은 이름을 배열의 이름으로 설정
		sizeMax = n;//크기 또한 입력
		data = new int[sizeMax];	//크기동적할당
		currentSize = 0;//현재크기는 0
	}
	~mySet()	//소멸자
	{
		cout<<" 소멸자: "<<name<<endl;
		delete[] data;//메모리해제
	}

	void add(int x)
	{	// currentSize > = sizeMax return;
		if (currentSize >= sizeMax)	//현재크기가 총 크기보다 크다면
		{
			cout<<"error_ no space"<<endl;	//공간이없다는 에러 출력
			return ;
		}
		if (contains(x))//만약 넣고자하는 원소가 이미 존재한다면
		{
			cout<<"error_ existed value"<<endl;//이미존재한다는 에러 출력
			return ;
		}

		data[currentSize++] =x;//위의 조건이 아니라면   집합에 값을 넣고 현재크기 증가
	}

	bool contains(int x)//x의 값이 있는지 없는지  확인을 위한 변수
	{
		// loop을 이용하여 값을 하나씩 검사 있으면 true 없으면 false
		for(int i=0; i<currentSize; i++)
		{
			if(data[i] == x)
			{
				return true;
			}
		}
		return false;
	}

};


#endif /* MYSET_H_ */
