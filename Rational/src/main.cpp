/*
 * main.cpp
 *
 *  Created on: 2016. 11. 17.
 *      Author: Yongsuk
 */
#include <iostream>
using namespace std;

class Rational{
	/*
	 * 1. constructor():n(x), d(y)
	 * 2. reduce()
	 * 3. int+Rational
	 * 4. Rational+int
	 * 5. main --> Rat+Rat, Rat+int, int+Rat
	 *
	 */
private:
	int n, d;

public:
	Rational():n(0), d(1) {/* Default Constructor */}
	Rational(int x): n(x), d(1) {/* Constructor(int x) */}
	Rational(int x, int y): n(x), d(y) {/* Constructor(int x, int y) */}

	int getGCD(){
		int gcd = 1;
			for(int i = 1; i<=n; ++i)
				if(n%i == 0 && d%i == 0)
					gcd=i;
			return gcd;
	}

	void reduce(){
		int gcd = getGCD();
		n = n/gcd;
		d = d/gcd;
	}
	friend ostream& operator <<(ostream& os, const Rational& x){
		os << x.n << "/" << x.d;
		return os;
	}

	friend Rational operator+(const Rational& x, const Rational& y){
		Rational result;
		result.d = x.d * y.d;
		result.n = x.n*y.d + y.n*x.d;
		result.reduce();
		return result;
	}

	friend Rational operator+(const Rational& x, const int& y){
		Rational result;
		result.d = x.d;
		result.n = x.n+y*x.d;
		result.reduce();
		return result;
	}

	friend Rational operator+(const int& y, const Rational& x){
		Rational result;
		result.d = x.d;
		result.n = x.n+y*x.d;
		result.reduce();
		return result;
	}

	~Rational(){}
};

int main(void){
	Rational r1;//0/1
	Rational r2(2);//2/1
	Rational r3(2,3);//2/3

	r1 = r3+r3; // (2/3) + (2/3) = (4/3)
	cout << r3 << " + " << r3 << " = " << r1 <<  endl;
	r1 = 2+r3;  // (2/1) + (2/3) = (8/3)
	cout << 2 << " + " << r3 << " = " << r1 <<  endl;
	r1 = r3+4;  // (2/3) + (2/1) = (8/3)
	cout << r3 << " + " << 4 << " = " << r1 <<  endl;

	return 0;
}

