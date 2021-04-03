#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Paths
{
    //����� ����� �� ������� q � ������� �����
    int size;
    int p;
    int connections[6];                    // ������ �������������� ������
    vector < vector<int> > a = { // ������� ��������� ���������������� �����
        {0,0,0,1,0,0},
        {0,0,1,0,1,0},
        {1,0,0,0,1,0},
        {0,0,1,0,0,1},
        {0,0,0,0,1,0},
        {0,1,0,0,1,0}
    };

public:
    Paths()  
    {
        p = 0;
        size = a[0].size();
        for (int i = 0; i < size; i++) connections[i] = -1;
        connections[p] = p;
    }
    Paths(int p) : p(p)
    {
        size = a[0].size();
        for (int i = 0; i < size; i++) connections[i] = -1;
        connections[p] = p;
    }
    /*
    ����� �� ������ �������� ���� ����� ������
        c[i] - ����� ��������;
        i - ����� ����������.
    */
    void Rec(int const p)
    {
        for (int i = 0; i < size; i++)
            if ((a[p][i]) && (connections[i] < 0))
            {
                connections[i] = p;
                Rec(i);
            }
    }
    /*������� ������� �� p � q*/
    void Path(int const p, int const q)
    {
        if (q == p) { cout << " " << p; return; }
        if (connections[q] >= 0)
        {
            Path(p, connections[q]); cout << " " << q;
        }
    }
    void PrintMatrix() {
        int i = 0;
        for (auto r : a)
        {
            cout << i << ") ";
            for (auto c : r)
                cout << c << " ";
            cout << endl;
            i++;
        }
    }
    void PrintPaths() {

        for (int i = 0; i < size; i++)
        {
            if (i != p) {
                cout << "���� �� " << p << " � " << i << " ������� �� ������:";
                Path(p, i);
                cout << endl;
            }
        }
    }
    int GetSize() { return size; }
};

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
