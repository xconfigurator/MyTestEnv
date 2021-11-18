#ifndef _COORDINATE_
#define _COORDINATE_
#include <iostream>
using namespace std;

class Coordinate {
	friend ostream& operator<<(ostream& os, const Coordinate& c) {
		os << "(" << c.m_iX << "," << c.m_iY << ")" << endl;
		return os;
	}
public:
	Coordinate(int _x = 0, int _y = 0) {
		cout << "Coordinate()" << endl;
		m_iX = _x;
		m_iY = _y;
	}
	virtual ~Coordinate() {
		cout << "~Coordinate()" << endl;
	}
private:
	int m_iX;
	int m_iY;
};

#endif 

