#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

enum name { Moly, Katy, Rachel, Charlotte, Caitlyn, Violet, Isobelle};
class Descendants {
    int size;
    int ancestor; // ��������� ������� (������� ����� ���������� � ����)
    vector <vector<int>> people;
public:
    Descendants() {
        people = { // ������� ��������� ���������������� �����
            {0,1,0,0,1,1,0}, // 0)
            {0,0,0,0,0,0,0}, // 1)
            {0,0,0,0,0,0,0}, // 2)
            {1,0,1,0,0,0,0}, // 3)
            {0,0,0,0,0,0,1}, // 4)
            {0,0,0,0,0,0,0}, // 5)
            {0,0,0,0,0,0,0}  // 6)
        };
        size = people.size();
    }
    Descendants(int ancestor) : Descendants() {
        this->ancestor = ancestor;
        size = people.size();
    }
    void traversal() {
        queue<int> DescendantsQueue;
        Rec(DescendantsQueue, ancestor);
        if (DescendantsQueue.empty())
            cout << "� �������� � ������� " + to_string(ancestor) + " ������� �����������";
        else {
            cout << "������� �������� � ������� " + to_string(ancestor) + ":";
            while (!DescendantsQueue.empty()) {
                cout << " " << DescendantsQueue.front();
                DescendantsQueue.pop();
            }
        }
    }
    void Rec(queue<int> & DescendantsQueue, int ancestor)
    {
        for (int i = 0; i < size; i++)
            if ((people[ancestor][i]))
            {
                Rec(DescendantsQueue, i);
                DescendantsQueue.push(i);
            }
    }
    int GetSize() { return size; }

};

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