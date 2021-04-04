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

int main() {
	setlocale(LC_ALL, "ru");
	string str;
	int x, y;
	cout << "������� x (�� ������ 0): ";  cin >> str;  x = atoi(str.c_str());
	cout << "������� y (�� ������ 0): ";  cin >> str;  y = atoi(str.c_str()); 
	if (!x || !y)
		cout << "��������� �����" << endl;
	else {
		GreatestCommonDivisor divisor(x, y);
		cout << "���������� ����� ��������: " << divisor.FindGCD() << endl;
	}
}