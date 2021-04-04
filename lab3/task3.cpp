#include "Function.h"
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите n: "; cin >> n;
    Function f;
    int m = f(n);
    if (m == -1) {
        cout << "Недопустимое значение n!" << endl;
    }
    else {
        cout << "Результат функции: " << m << endl;
    }
}

