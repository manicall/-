#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// ������������ ��� ������ ������ ����� � ������ � ������ ������� ���� 
class Graph {
    int size;
    vector<bool> marked; // ����� �������� false, ���� ������� ��� �� ������
    int startVertex; // ��������� ������� (������� ����� ���������� � ����)
    vector <vector<int>> graph;  // ������� ��������� ������������������ �����

    vector<vector<int>> BFS(); // ����� ������ ����� � ������
    // ��������� � ���� ��������� ��������
    void InitializateLayers(queue<queue<int>>& Layers);
    // �������� ������������� ����������
    vector<int> GetIntermediateResults(queue<int> vertexes, queue<int>& newVertexes);
public:
    Graph() {
        graph = {
            {0,1,1,0,0,0,0,0,0}, // 0)
            {1,0,0,1,1,1,0,0,0}, // 1)
            {1,0,0,0,0,0,1,1,0}, // 2)
            {0,1,0,0,0,0,0,0,0}, // 3)
            {0,1,0,0,0,0,0,0,0}, // 4)
            {0,1,0,0,0,0,0,0,0}, // 5)
            {0,0,1,0,0,0,0,0,1}, // 6)
            {0,0,1,0,0,0,0,0,1}, // 7)
            {0,0,0,0,0,0,1,1,0}  // 8)
        };
        size = graph.size();
        for (int i = 0; i < size; i++)
            marked.push_back(false);
    }
    Graph(int vertex) : Graph() {
        startVertex = vertex;
    }
    void PrintLayers();
    int GetSize() { return size; }
};


void Graph::PrintLayers() {
    vector<vector<int>> vectors = BFS();
    int i = 0;
    for (auto vertexes : vectors) {
        cout << "���� " << to_string(++i) << ": ";
        for (auto vertex : vertexes) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> Graph::BFS() {
    vector<vector<int>> result; // ������ ����� �����
    queue<queue<int>> Layers;   // �������, ������� �������� ������� ������ ������� ����
    InitializateLayers(Layers);
    while (!Layers.empty()) {
        queue<int> newVertexes; // �������� ������� ������ ����
        vector<int> intermediateResult = GetIntermediateResults(Layers.front(), newVertexes);
        if (!intermediateResult.empty())
            result.push_back(intermediateResult);
        if (!newVertexes.empty())
            Layers.push(newVertexes);
        Layers.pop();
    }
    return result;
}

// ��������� � ���� ��������� ��������
void Graph::InitializateLayers(queue<queue<int>>& Layers) {
    queue<int> vertexes;
    vertexes.push(startVertex);
    marked[startVertex] = true;
    Layers.push(vertexes);
}

vector<int> Graph::GetIntermediateResults(queue<int> vertexes, queue<int>& newVertexes) {
    vector<int> intermediateResult;
    while (!vertexes.empty()) {
        int vertex = vertexes.front(); // �������� ������� �� ������ ������ �������� ����
        for (int i = 0; i < size; i++) {
            if (graph[vertex][i] && !marked[i]) {
                marked[i] = true;
                newVertexes.push(i);
                intermediateResult.push_back(i);
            }
        }
        vertexes.pop();
    }
    return intermediateResult;
}
