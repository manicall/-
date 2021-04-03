#pragma once
#include <iostream>
class Point3D {
	double x, y, z;
public:
	Point3D() : x(0), y(0), z(0) { }
	Point3D(double x, double y, double z) : x(x), y(y), z(z) { }

	friend std::istream& operator >> (std::istream& in, Point3D& pt) { // Ввод
		std::cout << "Введите x: "; in >> pt.x;
		std::cout << "Введите y: "; in >> pt.y;
		std::cout << "Введите z: "; in >> pt.z;
		return in;
	}

	friend std::ostream& operator << (std::ostream& out, Point3D& pt) { // Вывод
		return out << "(" << pt.x << "; " << pt.y << "; " << pt.z << ")";
	}
};