#include <iostream>
#include <vector>
using namespace std;
//поиск путей из вершины q в вершины графа
int n;
int c[6];                  // номера предшествующих вершин
vector < vector<int> > a = { // матрица смежности ориентированного графа
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
        cout << "путь из "<< p << " в " << i << " состоит из вершин:";
        path(p, i);
        cout << endl;
    }
}
/* 
поиск из какого маршрута куда можно прийти
    c[i] - точка отправки;
    i - точка назначения.
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

/*выводим маршрут из p в q*/
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