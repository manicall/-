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
* ¬ариант графа, в котором может произойти зацикливание
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
    bool Rec(set<int> passedVertexs, int currentVertex);
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
        firstVertex = 1; // обход начинаетс€ с вершины с номером 1
    }
    void FindVertexs();
};

int main()
{
    setlocale(LC_ALL, "ru");
    Maze().FindVertexs();
}

queue<int> Maze::traversal() {
    queue<int> HasPathToExit;
    for (int i = firstVertex; i < size; i++) {
        HasPathToExit.push(DFS(i));
    }
    return HasPathToExit;
}

int Maze::DFS(int startVertex)
{
    set<int> passedVertexs; // используетс€, чтобы избежать зацикливани€
    for (int i = 0; i < size; i++)
        // если существует путь к вершине i из currentVertex
        if ((mazeGraph[startVertex][i]))
        {
            passedVertexs.emplace(startVertex);
            // начинаем обход в глубину
            if (Rec(passedVertexs, i)) {
                return startVertex; // обнарушен путь к выходу
            }
        }
    return -1; // обошли весь граф и не нашли выход
}
bool Maze::Rec(set<int> passedVertexs, int currentVertex)
{
    if (currentVertex == 0) // очередна€ вершина оказалась выходом
        return true;
    else if (passedVertexs.find(currentVertex) != passedVertexs.end()) // если текущую вершину уже прошли
        return false;
    for (int i = 0; i < size; i++)
        if ((mazeGraph[currentVertex][i]))
        {
            passedVertexs.emplace(currentVertex);
            if (Rec(passedVertexs, i)) {
                return true; // обнарушен путь к выходу
            }
        }
    return false;
}

void Maze::FindVertexs() {
    queue<int> result = traversal();
    cout << "Ќомера вершин, имеющих путь к выходу: ";
    while (!result.empty()) {
        if (result.front() != -1) 
            cout << result.front() << " ";
        result.pop();
    }
}