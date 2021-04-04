#pragma once
#include <iostream>

using namespace std;

class GreatestCommonDivisor {
	int x, y;

public:
	GreatestCommonDivisor(int x, int y) : x(x), y(y) {}
	int FindGCD() {
		return FindGCD(x, y);
	}
	int FindGCD(int x, int y) {
		if (x > y) x -= y;
		else if (x < y) y -= x;
		if (x == y) return x;
		return FindGCD(x, y);
	}
};
