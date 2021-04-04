#include <iostream>
#include <string>

using namespace std;

class Function {
public:
    int operator() (int n) {
        int m = 0;
        if (n == 1) {
            // cout << "F(1)" << endl;
            return 1;
        }
        else if (n >= 2) {
            for (int i = 2; i <= n; i++) {
                //cout << "n = " <<  n << "; F(" << to_string(i) << ")" << endl;
                m += operator()(n / i);
            }
            return m;
        }
        else
            return -1;
    }
};



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

