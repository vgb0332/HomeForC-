/*
 * Rational.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: Administrator
 */
#include "Rational.h"
#include <iostream>
using namespace std;

/*
 * This is for definition of Rational Class declared in 'Rational.h'
 * created by Yongsuk Jung
 */

void Rational::setNumerator(int n){
	numerator = n;
}

void Rational::setDenominator(int n){
	denominator = n;
}

void Rational::setRational(int n, int d){
	numerator = n;
	denominator = d;
}

int Rational::getNumerator(){
	return numerator;
}

int Rational::getDenominator(){
	return denominator;
}

void Rational::printRational(){
	cout << numerator<< "/" << denominator << endl;
}

int Rational::getGcd(){
	//if no gcd to find, it's 1
	int gcd = 1;
	for(int i = 1; i<=numerator; ++i)
		if(numerator%i == 0 && denominator%i == 0)
			gcd=i;
	return gcd;
}

void Rational::reduce(){
	//Divide numerator and denominator by their GCD.
	int gcd = this->getGcd();
	numerator = numerator/gcd;
	denominator = denominator/gcd;
	printRational();
}

void Rational::add(Rational x){
	int n1 = this->numerator;
	int d1 = this->denominator;
	int n2 = x.getNumerator();
	int d2 = x.getDenominator();

	this->numerator = n1*d2 + n2*d1;
	this->denominator = d1*d2;
	//Simplify
	this->reduce();
}

void Rational::sub(Rational x){
	int n1 = this->numerator;
	int d1 = this->denominator;
	int n2 = x.getNumerator();
	int d2 = x.getDenominator();

	this->numerator = n1*d2 - n2*d1;
	this->denominator = d1*d2;
	//Simplify
	this->reduce();
}

void Rational::mult(Rational x){
	this->numerator = this->numerator * x.numerator;
	this->denominator = this->denominator * x.denominator;
	//Simplify
	this->reduce();
}

void Rational::div(Rational x){
	// (A/B)/(C/D) = (A/B)X(D/C)

	this->numerator = this->numerator * x.denominator;
	this->denominator = this->denominator * x.numerator;
	//Simplify
	this->reduce();
}


