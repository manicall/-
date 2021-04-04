#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "ru");
    int size = (new Graph)->GetSize() - 1;
    cout << "Введите номер вершины (от 0 до " + to_string(size) + " ): ";
    int startVertex; cin >> startVertex;
    if (startVertex >= 0 && startVertex <= size) {
        Graph graph(startVertex);
        graph.PrintLayers();
    }
    else {
        cout << "Выход за границы массива" << endl;
    }

}
