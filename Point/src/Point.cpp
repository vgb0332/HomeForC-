//============================================================================
// Name        : Point.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point{//(x,y)
int x, y;
public:
	Point() : x(0), y(0){}
	Point(int a, int b): x(a), y(b){}
	Point(const Point& p): x(p.x), y(p.y){}

	friend ostream& operator<<(ostream& os, const Point& p){
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}

	friend Point operator+(const Point& a, const Point& b){
		return Point(a.x + b.x, a.y + b.y);
	}

	friend Point operator+(const int& a, const Point& b){
		return Point(a + b.x, a + b.y);
	}

	friend int operator*(const Point& a, const Point& b){
		return (a.x * b.x) + (a.y * b.y);
	}

	friend Point scale(const Point& a, const Point& b){
		return Point(a.x * b.x, a.y * b.y);
	}

	friend Point transpose(const Point& p){
		return Point(p.y, p.x);

	}
};

class Rect{
	Point p,q;
public:
	Rect():p(0,0),q(0,0){}
	Rect(int x1, int y1, int x2, int y2):p(x1,y1), q(x2,y2){}
	Rect(const Point& a, const Point& b):p(a), q(b){}
	/*
	 *
	 * 1. operator<< overloading
	 * 				(1,2)-(2,3)
	 * 2. operator+ overloading
	 * 			2.1 Rect + point
	 *			2.2 Rect + int
	 *
	 * 3. operator* overloading
	 * 			3.1 Rect * point(x,y)
	 * 				current Rect's width and height --> Point(w,h)
	 * 				(w, h)  current width and height
	 * 				(w*x, h*y): scale()
	 * 				(p.x+w*x, p.y+h*y): new coordinate of q -> Point
	 * 				return Rect(p, new q)
	 *
	 *
	 * 4. int area()
	 *
	 */
	friend ostream& operator<<(ostream& os, Rect& a){
		os << a.p << "-" << a.q;
		return os;
	}

	friend Rect operator+(const Rect& r, const Point& p){
		return Rect(r.p + p, r.q + p);
	}
	friend Rect operator+(const Rect& r, const int& x){
		return Rect(x + r.p, x + r.q);
	}
	friend Rect operator*(const Rect& r, const Point& p){
		/*current Rect's width and height --> Point(w,h)
			 * 				(w, h)  current width and height
			 * 				(w*x, h*y): scale()
			 * 				(p.x+w*x, p.y+h*y): new coordinate of q -> Point
			 * 				return Rect(p, new q)
			 * 				*/
		Point minus = Point(-1,-1);
		Point wh = r.q + scale(minus, r.p);
		Point newWH = scale(wh, p);
		Point newQ = newWH+r.p;
		return Rect(r.p, newQ);

	}

	int area(){
		//find the width and height as Point and
		//multiply with transpose of width and height and divide by 2
		// ex) width and height = (10,20)
		//	   Area = (10, 20) X (20, 10) = 200 + 200 /2
		//     since the area has been added twice\

		Point minus = Point(-1,-1);
		Point wh = q + scale(minus, p);
		int area = wh*transpose(wh)/2;
		return area;

	}
};

int main() {
	Rect r(2,0,3,4);
	Point p(2,3);

	cout << "Rect Points: " << r << endl;

	Rect RplusP = r + p;
	cout << "r(2,0,3,4) + p(2,3) = " << RplusP << endl;

	Rect RplusInt = r + 5;
	cout << "r(2,0,3,4) + 5 = " << RplusInt << endl;

	Rect RmulP = r * p;
	cout << "r(2,0,3,4) X p(2,3) = " << RmulP << endl;

	int Area = r.area();
	cout << "Area of r(2,0,3,4) = " << Area << endl;
	return 0;
}
