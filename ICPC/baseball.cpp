/*
 * baseball.cpp
 *
 *  Created on: 2016. 9. 20.
 *      Author: Yongsuk
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, w, L;
int trucks[1001];
queue<int> bridge;


int main(void){
	cin >> n >> w >> L;
	for(int i = 0; i < n; ++i){
		int value;
		cin >> value;
		trucks[i] = value;
	}

	int currentWeight = 0;
	int count = 0;
	for(int i = 0; i < n;){
		if(bridge.size() == L){
			currentWeight -= bridge.front();
			bridge.pop();
			cout << bridge.front();

		}

		if(bridge.size() < L){
			if(currentWeight + trucks[i] <= w){
				bridge.push(trucks[i]);
				currentWeight+=trucks[i];
				i++;
			}
			else
				bridge.push(0);
		}
		count++;

	}
	cout << count+w;

	return 0;
}
