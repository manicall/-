#include "Function.h"
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "������� n: "; cin >> n;
    Function f;
    int m = f(n);
    if (m == -1) {
        cout << "������������ �������� n!" << endl;
    }
    else {
        cout << "��������� �������: " << m << endl;
    }
}

