#include "GreatestCommonDivisor.h"

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