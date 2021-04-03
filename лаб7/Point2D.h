#pragma once
#include <iostream>
class Point2D {
	double x, y;
public:
	Point2D() : x(0), y(0) { }
	Point2D(double x, double y) : x(x), y(y) { }

	friend std::istream& operator >> (std::istream& in, Point2D& pt) { // Ввод
		std::cout << "Введите x: "; in >> pt.x;
		std::cout << "Введите y: "; in >> pt.y;
		return in;
	}

	friend std::ostream& operator << (std::ostream& out, Point2D& pt) { // Вывод
		return out << "(" << pt.x << "; " << pt.y << ")";
	}
};
