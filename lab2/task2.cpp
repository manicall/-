#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//int n = 3;
//double x[3] = {9.66, 1.84, -0.50 };
int n = 2;
double x[2] = { -1, -9 };
double a(int n, int i);
void check(double x, vector<double> c);
void full_check(double* x, vector<double> c);
int main() {
	setlocale(LC_ALL, "ru");
	vector<double> coefficients;
	cout << "Коэффициенты: ";
	for (int i = 0; i <= n; i++)
		coefficients.push_back(a(n, n - i));
	for (auto x : coefficients)
		cout << x << " ";
	cout << endl << "Проверка: " << endl; 

	full_check(x, coefficients);
}

double a(int n, int i) {
	double temp;
	if (i == n) {
		temp = 1.0;
	}
	else if (i == 0) {
		temp = -a(n - 1, 0) * x[n-1];
	}
	else if (i >= 1 && i < n - 1) {
		temp = a(n - 1, i - 1) - a(n - 1, i) * x[n-1];
	}
	else if (i == n - 1) {
		temp = a(n - 1, n - 2) - x[n-1];
	}

	return temp;
}

void check(double x, vector<double> c) {
	double sum = 0;
	for (int i = n; i >= 0; i--)
		sum += pow(x, i) * c[c.size() - i - 1];
	cout <<"x = " << x << "; P(x) = " << sum << endl;
};

void full_check(double* x, vector<double> c) {
	for (int i = 0; i < n; i++)
		check(x[i], c);
}