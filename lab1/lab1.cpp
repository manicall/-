#include <iostream>

using namespace std;

int NOD(int x, int y) {
	if (x > y) x -= y;
	else if (x < y) y -= x;
	if (x == y) return x;
	return NOD(x, y);
}

int main() {
	setlocale(LC_ALL, "ru");
	string str;
	int x, y;
	cout << "Введите x (не равное 0): ";  cin >> str;  x = atoi(str.c_str());
	cout << "Введите y (не равное 0): ";  cin >> str;  y = atoi(str.c_str()); 
	if (!x || !y)
		cout << "Ожидалось число" << endl;
	else
		cout << "Наибольший общий делитель:" << NOD(x, y) << endl;
}