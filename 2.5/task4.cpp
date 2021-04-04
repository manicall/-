#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Paths     //поиск путей из вершины p в вершины q
{
    int size;
    int p; 
    int connections[6];  // номера предшествующих вершин
    vector < vector<int> > cities;
public:
    Paths() {
        cities = { // матрица смежности ориентированного графа
        {0,1,0,0,0,0},
        {0,0,1,0,1,0},
        {1,0,0,0,1,0},
        {0,0,1,0,0,1},
        {0,0,1,1,0,0},
        {0,0,0,0,1,0}
        };
        size = cities[0].size();    
    }
    Paths(int p) : Paths() {
        this->p = p;
        for (int i = 0; i < size; i++) connections[i] = -1;
        connections[p] = p;
    }
    void Rec(int const p);
    /*выводим маршрут из p в q*/
    void Path(int const p, int const q)
    {
        if (q == p) { cout << " " << p; return; }
        Path(p, connections[q]); cout << " " << q;
    }
    void PrintMatrix();
    void PrintPaths();
    int GetSize() { return size; }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int size = (new Paths)->GetSize() - 1;
    cout << "Введите p (от 0 до " + to_string(size) +  " ): ";
    int city; cin >> city;
    if (city >= 0 && city <= size) {
        Paths paths(city);
        paths.PrintMatrix();
        paths.Rec(city);
        paths.PrintPaths();
    }
    else {
        cout << "Выход за границы массива" << endl;
    }
}

void Paths::Rec(int const p)
{
/*
поиск из какого маршрута куда можно прийти
    c[i] - точка отправки;
    i - точка назначения.
*/
    for (int i = 0; i < size; i++)
        if ((cities[p][i]) && (connections[i] < 0))
        {
            connections[i] = p;
            Rec(i);
        }
}

void Paths::PrintMatrix() {
    int i = 0;
    for (auto r : cities)
    {
        cout << i << ") ";
        for (auto c : r)
            cout << c << " ";
        cout << endl;
        i++;
    }
}

void Paths::PrintPaths() {

    for (int i = 0; i < size; i++)
    {
        if (connections[i] == -1) {
            cout << "пути из " << p << " в " << i << " Не существует." << endl; continue;
        }
        if (i != p) {
            cout << "путь из " << p << " в " << i << " состоит из вершин:";
            Path(p, i);
            cout << endl;
        }
    }
}