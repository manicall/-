#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// используется для обхода вершин графа в ширину и вывода каждого слоя 
class Graph {
    int size;
    vector<bool> marked; // имеет значение false, если вершину еще не обошли
    int startVertex; // стартовая вершина (вершины везде нумеруются с нуля)
    vector <vector<int>> graph;  // матрица смежности неориентированного графа

    vector<vector<int>> BFS(); // обход вершин графа в ширину
    // добавляем в слой начальное значение
    void InitializateLayers(queue<queue<int>>& Layers);
    // получаем промежуточные результаты
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
        cout << "Слой " << to_string(++i) << ": ";
        for (auto vertex : vertexes) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> Graph::BFS() {
    vector<vector<int>> result; // массив слоев графа
    queue<queue<int>> Layers;   // очередь, которая содержит очередь вершин каждого слоя
    InitializateLayers(Layers);
    while (!Layers.empty()) {
        queue<int> newVertexes; // содержит вершины нового слоя
        vector<int> intermediateResult = GetIntermediateResults(Layers.front(), newVertexes);
        if (!intermediateResult.empty())
            result.push_back(intermediateResult);
        if (!newVertexes.empty())
            Layers.push(newVertexes);
        Layers.pop();
    }
    return result;
}

// добавляем в слой начальное значение
void Graph::InitializateLayers(queue<queue<int>>& Layers) {
    queue<int> vertexes;
    vertexes.push(startVertex);
    marked[startVertex] = true;
    Layers.push(vertexes);
}

vector<int> Graph::GetIntermediateResults(queue<int> vertexes, queue<int>& newVertexes) {
    vector<int> intermediateResult;
    while (!vertexes.empty()) {
        int vertex = vertexes.front(); // получаем вершину из списка вершин текущего слоя
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
