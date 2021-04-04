#include "GreatestCommonDivisor.h"

int main() {
	setlocale(LC_ALL, "ru");
	string str;
	int x, y;
	cout << "Введите x (не равное 0): ";  cin >> str;  x = atoi(str.c_str());
	cout << "Введите y (не равное 0): ";  cin >> str;  y = atoi(str.c_str()); 
	if (!x || !y)
		cout << "Ожидалось число" << endl;
	else {
		GreatestCommonDivisor divisor(x, y);
		cout << "Наибольший общий делитель: " << divisor.FindGCD() << endl;
	}
}