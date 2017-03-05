/*
 * Rational.h
 *
 *  Created on: 2016. 11. 3.
 *      Author: Administrator
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_
/*
 * This is for declaration of Rational Class
 * parameter:
 * 		private: int numerator, denominator
 * 		public: setNumerator, setDenominator, getNumerator, getDenominator
 * 				printRational, getGcd, reduce, add, sub, mult, div
 *
 */
class Rational{
private:
	int numerator;
	int denominator;

public:
	Rational(){ //Constructor set both num and den to 0
		this->numerator=0;
		this->denominator=0;
	}
	void setNumerator(int n);
	void setDenominator(int n);
	void setRational(int n, int d);
	int getNumerator();
	int getDenominator();
	void printRational();
	int getGcd();
	void reduce();
	void add(Rational x);
	void sub(Rational x);
	void mult(Rational x);
	void div(Rational x);
};



#endif /* RATIONAL_H_ */
