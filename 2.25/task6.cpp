#include "Descendants.h"
int main()
{
	setlocale(LC_ALL, "ru");

    int size = (new Descendants)->GetSize() - 1;
    cout << "������� p (�� 0 �� " + to_string(size) + " ): ";
    int ancestor; cin >> ancestor;
    if (ancestor >= 0 && ancestor <= size) {
        Descendants descendants(ancestor);
        descendants.traversal();
    }
    else {
        cout << "����� �� ������� �������" << endl;
    }

}