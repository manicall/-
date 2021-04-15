#pragma once
#include <iostream>
#include <vector>
#include <list>
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
    void InitializateLayers(list<list<int>>& Layers);
    // �������� ������������� ����������
    vector<int> GetIntermediateResults(list<int> vertexes, list<int>& newVertexes);
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
    list<list<int>> Layers;   // �������, ������� �������� ������� ������ ������� ����
    InitializateLayers(Layers);
    while (!Layers.empty()) {
        list<int> newVertexes; // �������� ������� ������ ����
        vector<int> intermediateResult = GetIntermediateResults(Layers.front(), newVertexes);
        if (!intermediateResult.empty())
            result.push_back(intermediateResult);
        if (!newVertexes.empty())
            Layers.push_back(newVertexes);
        Layers.pop_front();
    }
    return result;
}

// ��������� � ���� ��������� ��������
void Graph::InitializateLayers(list<list<int>>& Layers) {
    list<int> vertexes;
    vertexes.push_back(startVertex);
    marked[startVertex] = true;
    Layers.push_back(vertexes);
}

vector<int> Graph::GetIntermediateResults(list<int> vertexes, list<int>& newVertexes) {
    vector<int> intermediateResult;
    while (!vertexes.empty()) {
        int vertex = vertexes.front(); // �������� ������� �� ������ ������ �������� ����
        for (int i = 0; i < size; i++) {
            if (graph[vertex][i] && !marked[i]) {
                marked[i] = true;
                newVertexes.push_back(i);
                intermediateResult.push_back(i);
            }
        }
        vertexes.pop_front();
    }
    return intermediateResult;
}
