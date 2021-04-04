#include "FindCoefficients.h"

int main() {
	setlocale(LC_ALL, "ru");
	vector<double> x = { -1, -9 };
	
	FindCoefficients findCoef(x);
	findCoef.findCoefficients();
	findCoef.PrintCoefficients();
	findCoef.PrintCheck();
}
