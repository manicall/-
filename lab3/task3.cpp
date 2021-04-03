#include <iostream>

using namespace std;

int f(int);

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите n: "; cin >> n;
    int m = f(n);
    if (m == -1) {
        cout << "Недопустимое значение n!" << endl;
    }
    else {
        cout << "Результат функции: " << m << endl;
    }
}

int f(int n) {
    int m = 0;
    if (n == 1) {
        //System.out.println("F(1)");
        return 1;
    }
    else if (n >= 2) {
        for (int i = 2; i <= n; i++) {
            //System.out.println("n = " + n + "; F("+Integer.toString(i)+")");
            m += (int)f(n / i);
        }
        return m;
    }
    else {
        return -1;
    }

}