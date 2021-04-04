#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//double* x = new double[n]{9.66, 1.84, -0.50 };
//double* x = new double[n]{ -1, -9 };

class FindCoefficients {
	vector<double> coefficients;
	int n;
	vector<double> x;
	double a(int n, int i); // коэфициент
	void Check(double x, vector<double> c);
	void FullCheck(vector<double> x, vector<double> c);
public:
	FindCoefficients(vector<double> x) {
		this->n = x.size();
		this->x = x;
	}
	void findCoefficients() {
		cout << "Коэффициенты: ";
		for (int i = 0; i <= n; i++)
			coefficients.push_back(a(n, n - i));
	}	
	void PrintCheck() {
		cout << endl << "Проверка: " << endl;
		FullCheck(x, coefficients);
	}
	void PrintCoefficients() {
		for (auto x : coefficients)
			cout << x << " ";
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	vector<double> x = { -1, -9 };
	
	FindCoefficients findCoef(x);
	findCoef.findCoefficients();
	findCoef.PrintCoefficients();
	findCoef.PrintCheck();
}

double FindCoefficients::a(int n, int i) {
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

void FindCoefficients::Check(double x, vector<double> c) {
	double sum = 0;
	for (int i = n; i >= 0; i--)
		sum += pow(x, i) * c[c.size() - i - 1];
	cout <<"x = " << x << "; P(x) = " << sum << endl;
};

void FindCoefficients::FullCheck(vector<double> x, vector<double> c) {
	for (int i = 0; i < n; i++)
		Check(x[i], c);
}