#pragma once
#include <iostream>
class xyPoint {
public:
	double x, y;
	xyPoint() : x(0), y(0) { }
	xyPoint(double x, double y) : x(x), y(y) { }

	friend std::ostream& operator << (std::ostream& out, xyPoint& pt) { // �����
		return out << "(" << pt.x << "; " << pt.y << ")" << std::endl;
	}
};
