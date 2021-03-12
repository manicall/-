#include <iostream>

int a(int n, int i);

int main() {
	setlocale(LC_ALL, "ru");


}

int a(int n, int i) {
	double x = -9;

	if (n > 0 && i == 0)
		return x * a(n - 1, 0);

}