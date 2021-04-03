#pragma once
#include <iostream>
class Point3D {
	double x, y, z;
public:
	Point3D() : x(0), y(0), z(0) { }
	Point3D(double x, double y, double z) : x(x), y(y), z(z) { }

	friend std::istream& operator >> (std::istream& in, Point3D& pt) { // ����
		std::cout << "������� x: "; in >> pt.x;
		std::cout << "������� y: "; in >> pt.y;
		std::cout << "������� z: "; in >> pt.z;
		return in;
	}

	friend std::ostream& operator << (std::ostream& out, Point3D& pt) { // �����
		return out << "(" << pt.x << "; " << pt.y << "; " << pt.z << ")";
	}
};