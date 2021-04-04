#include "Paths.h"
int main()
{
    setlocale(LC_ALL, "ru");
    int size = (new Paths)->GetSize() - 1;
    cout << "������� p (�� 0 �� " + to_string(size) +  " ): ";
    int city; cin >> city;
    if (city >= 0 && city <= size) {
        Paths paths(city);
        paths.PrintMatrix();
        paths.Rec(city);
        paths.PrintPaths();
    }
    else {
        cout << "����� �� ������� �������" << endl;
    }
}
