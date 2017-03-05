/*
 * test.cpp
 *
 *  Created on: 2016. 10. 25.
 *      Author: Yongsuk
 */
#include <iostream>
using namespace std;

class Car{
public:
	int speed;
	float dist;
	string name;

	void printCar();
	void updateDist(int a);
	void updateSpeed(int a);
	void accelerate(int a);
};

void Car::printCar(){
	cout << "name: " << name << endl;
	cout << "speed: " << speed << endl;
	cout << "dist: "  << dist << endl;
}

void Car::updateDist(int a){
	float s = speed + a/2.0;
	dist += s;
}

void Car::updateSpeed(int a){
	speed += a;
}

void Car::accelerate(int a){
	updateDist(a);
	updateSpeed(a);
}

int main(void){
	Car a;
	a.name = "Audi";
	a.speed = 200;
	a.dist = 0;
	a.printCar();

	a.accelerate(10);
	a.printCar();

	return 0;
}

