#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Descendants {
    int size;
    int ancestor; // ��������� ������� (������� ����� ���������� � ����)
    vector <vector<int>> people;
public:
    Descendants() {
        people = { // ������� ��������� ���������������� �����
            {0,1,0,0,1,1,0}, // 0)
            {0,0,0,0,0,0,0}, // 1)
            {0,0,0,0,0,0,0}, // 2)
            {1,0,1,0,0,0,0}, // 3)
            {0,0,0,0,0,0,1}, // 4)
            {0,0,0,0,0,0,0}, // 5)
            {0,0,0,0,0,0,0}  // 6)
        };
        size = people.size();
    }
    Descendants(int ancestor) : Descendants() {
        this->ancestor = ancestor;
        size = people.size();
    }
    void traversal() {
        queue<int> DescendantsQueue;
        Rec(DescendantsQueue, ancestor);
        if (DescendantsQueue.empty())
            cout << "� �������� � ������� " + to_string(ancestor) + " ������� �����������";
        else {
            cout << "������� �������� � ������� " + to_string(ancestor) + ":";
            while (!DescendantsQueue.empty()) {
                cout << " " << DescendantsQueue.front();
                DescendantsQueue.pop();
            }
        }
    }
    void Rec(queue<int>& DescendantsQueue, int ancestor)
    {
        for (int i = 0; i < size; i++)
            if ((people[ancestor][i]))
            {
                Rec(DescendantsQueue, i);
                DescendantsQueue.push(i);
            }
    }
    int GetSize() { return size; }

};
