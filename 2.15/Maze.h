#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
* случайный вариант графа
mazeGraph = {
    {0,0,1,1,0,0}, // выход
    {0,0,1,0,1,1}, // 1)
    {1,1,0,0,1,0}, // 2)
    {1,0,0,0,0,1}, // 3)
    {0,1,1,0,0,1}, // 4)
    {0,1,0,1,1,0}  // 5)
};
*/


/*
* Вариант графа, в котором может произойти зацикливание
mazeGraph = {
    {0,0,0,0,0,0,1}, // выход
    {0,0,1,1,1,0,0}, // 1)
    {0,1,0,1,0,0,0}, // 2)
    {0,1,1,0,0,0,0}, // 3)
    {0,1,0,0,0,1,0}, // 4)
    {0,0,0,0,1,0,1}, // 5)
    {1,0,0,0,0,1,0}  // 6)
};
*/

class Maze {
    int size;
    int firstVertex;
    vector <vector<int>> mazeGraph;// матрица смежности неориентированного графа

    int DFS(int startVertex);
    queue<int> traversal();
    bool Rec(set<int> passedVertexes, int currentVertex);
public:
    Maze() {
        mazeGraph = {
            {0,0,0,0,0,0,1}, // выход
            {0,0,1,1,1,0,0}, // 1)
            {0,1,0,1,0,0,0}, // 2)
            {0,1,1,0,0,0,0}, // 3)
            {0,1,0,0,0,1,0}, // 4)
            {0,0,0,0,1,0,1}, // 5)
            {1,0,0,0,0,1,0}  // 6)
        };
        size = mazeGraph.size();
        firstVertex = 1; // обход начинается с вершины с номером 1
    }
    void FindVertexes();
};

queue<int> Maze::traversal() {
    queue<int> HasPathToExit; // результат обхода вершин
    for (int i = firstVertex; i < size; i++) {
        HasPathToExit.push(DFS(i));
    }
    return HasPathToExit;
}

int Maze::DFS(int startVertex)
{
    set<int> passedVertexes; // используется, чтобы избежать зацикливания
    for (int i = 0; i < size; i++)
        // если существует путь к вершине i из currentVertex
        if ((mazeGraph[startVertex][i]))
        {
            passedVertexes.emplace(startVertex);
            // начинаем обход в глубину
            if (Rec(passedVertexes, i)) {
                return startVertex; // обнарушен путь к выходу
            }
        }
    return -1; // обошли весь граф и не нашли выход
}
bool Maze::Rec(set<int> passedVertexes, int currentVertex)
{
    if (currentVertex == 0) // очередная вершина оказалась выходом
        return true;
    else if (passedVertexes.find(currentVertex) != passedVertexes.end()) // если текущую вершину уже прошли
        return false;
    for (int i = 0; i < size; i++)
        if ((mazeGraph[currentVertex][i]))
        {
            passedVertexes.emplace(currentVertex);
            if (Rec(passedVertexes, i)) {
                return true; // обнарушен путь к выходу
            }
        }
    return false;
}

void Maze::FindVertexes() {
    queue<int> result = traversal();
    cout << "Номера вершин, имеющих путь к выходу: ";
    while (!result.empty()) {
        if (result.front() != -1)
            cout << result.front() << " ";
        result.pop();
    }
}