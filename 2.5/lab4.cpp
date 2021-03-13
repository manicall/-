#include <iostream>
#include <vector>
using namespace std;
//����� ����� �� ������� q � ������� �����
int n;
int c[6];                  // ������ �������������� ������
vector < vector<int> > a = { // ������� ��������� ���������������� �����
    {0,0,0,1,0,0},
    {0,0,1,0,1,0},
    {1,0,0,0,1,0},
    {0,0,1,0,0,1},
    {0,0,0,0,1,0},
    {0,1,0,0,1,0}
};

void rec(int p);
void path(int s, int v);
void print_matrix(vector < vector<int> >);

int main()
{
    setlocale(LC_ALL, "ru");
    int p = 0;
    n = a[0].size();
    print_matrix(a);
    for (int i = 0; i < n; i++) c[i] = -1;
    c[p] = p;

    rec(p);
    for (int i = 0; i < n; i++)
    {
        cout << "���� �� "<< p << " � " << i << " ������� �� ������:";
        path(p, i);
        cout << endl;
    }
}
/* 
����� �� ������ �������� ���� ����� ������
    c[i] - ����� ��������;
    i - ����� ����������.
*/
void rec(int p) 
{
    for (int i = 0; i < n; i++)
        if ((a[p][i]) && (c[i] < 0))
        {
            c[i] = p; rec(i); 
            cout << "i = " << i << "; " <<  c[i] << ". ";
        }
}

/*������� ������� �� p � q*/
void path(int p, int q)
{
    if (q == p) { cout << " " << p; return; } 
    if (c[q] >= 0)
    {
        path(p, c[q]); cout << " " << q;
    }
}

void print_matrix(vector < vector<int> > A) {
    int i = 0;
    for (auto r : A)
    {
        cout << i << ") ";
        for (auto c : r)
            cout << c << " ";
        cout << endl;
        i++;
    }
}