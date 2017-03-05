/*
 * Main.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: Administrator
 */

#include "Rational.h"
#include <iostream>

using namespace std;

int main(void){
	Rational a,b;
	//Make two rationals and assign values
	//a = 1/8, b = 3/2
	a.setNumerator(1);
	a.setDenominator(8);
	b.setNumerator(3);
	b.setDenominator(2);

	//Test for addition
	cout << a.getNumerator()<<"/"<<a.getDenominator()
			<< " + " << b.getNumerator() << "/" << b.getDenominator()
			<< " = ";
	a.add(b);

	//Test for subtraction
	cout << a.getNumerator()<<"/"<<a.getDenominator()
				<< " - " << b.getNumerator() << "/" << b.getDenominator()
				<< " = ";
		a.sub(b);

	//Test for multiplication
	cout << a.getNumerator()<<"/"<<a.getDenominator()
				<< " X " << b.getNumerator() << "/" << b.getDenominator()
	     		<< " = ";
		a.mult(b);

	//Test for division
	cout << a.getNumerator()<<"/"<<a.getDenominator()
				<< " / " << b.getNumerator() << "/" << b.getDenominator()
				<< " = ";
		a.div(b);


	return 0;
}


