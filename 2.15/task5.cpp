#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*
* ��������� ������� �����
mazeGraph = {
    {0,0,1,1,0,0}, // �����
    {0,0,1,0,1,1}, // 1)
    {1,1,0,0,1,0}, // 2)
    {1,0,0,0,0,1}, // 3)
    {0,1,1,0,0,1}, // 4)
    {0,1,0,1,1,0}  // 5)
};
*/


/*
* ������� �����, � ������� ����� ��������� ������������
mazeGraph = {
    {0,0,0,0,0,0,1}, // �����
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
    vector <vector<int>> mazeGraph;// ������� ��������� ������������������ �����

    int DFS(int startVertex);
    queue<int> traversal();
    bool Rec(set<int> passedVertexs, int currentVertex);
public:
    Maze() {
        mazeGraph = {
            {0,0,0,0,0,0,1}, // �����
            {0,0,1,1,1,0,0}, // 1)
            {0,1,0,1,0,0,0}, // 2)
            {0,1,1,0,0,0,0}, // 3)
            {0,1,0,0,0,1,0}, // 4)
            {0,0,0,0,1,0,1}, // 5)
            {1,0,0,0,0,1,0}  // 6)
        };
        size = mazeGraph.size();
        firstVertex = 1; // ����� ���������� � ������� � ������� 1
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
    set<int> passedVertexs; // ������������, ����� �������� ������������
    for (int i = 0; i < size; i++)
        // ���� ���������� ���� � ������� i �� currentVertex
        if ((mazeGraph[startVertex][i]))
        {
            passedVertexs.emplace(startVertex);
            // �������� ����� � �������
            if (Rec(passedVertexs, i)) {
                return startVertex; // ��������� ���� � ������
            }
        }
    return -1; // ������ ���� ���� � �� ����� �����
}
bool Maze::Rec(set<int> passedVertexs, int currentVertex)
{
    if (currentVertex == 0) // ��������� ������� ��������� �������
        return true;
    else if (passedVertexs.find(currentVertex) != passedVertexs.end()) // ���� ������� ������� ��� ������
        return false;
    for (int i = 0; i < size; i++)
        if ((mazeGraph[currentVertex][i]))
        {
            passedVertexs.emplace(currentVertex);
            if (Rec(passedVertexs, i)) {
                return true; // ��������� ���� � ������
            }
        }
    return false;
}

void Maze::FindVertexs() {
    queue<int> result = traversal();
    cout << "������ ������, ������� ���� � ������: ";
    while (!result.empty()) {
        if (result.front() != -1) 
            cout << result.front() << " ";
        result.pop();
    }
}