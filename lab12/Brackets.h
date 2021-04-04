#pragma once
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

class Brackets {
    stack<char> brackets;
    string expression;
public:
    Brackets() {
        ifstream file("input.txt");
        while (!file.eof()) {
            string temp;
            file >> temp;
            expression += temp;
        }
    }

    bool IsBracketsMatch();
    void PrintAnswer();
    void PrintExpression();
    bool IsExpressionEmpty() {
        if (expression == "")
            return true;
    }
};

bool Brackets::IsBracketsMatch() {
    for (char c : expression) {
        if (c == '<' || c == '{') { // ��������� ������������ ������
            brackets.push(c);
            continue;
        }
        if (c != '<' && c != '{' && c != '>' && c != '}') // ���� ������� ����� ������ ����� ������
            continue;
        if (!brackets.empty()) {
            if (c == '>' && brackets.top() != '<')  // ������������ ������� ������
                return false;
            if (c == '}' && brackets.top() != '{')  // ������������ �������� ������
                return false;
            brackets.pop();
        }
        else
            return false;
    }
    return brackets.empty();
}

void Brackets::PrintAnswer() {
    if (IsExpressionEmpty())
        cout << "������ �����������" << endl;
    else {
        if (IsBracketsMatch())
            cout << "������ ���������" << endl;
        else
            cout << "������ �� ���������" << endl;
    }
}

void Brackets::PrintExpression() {
    if (!IsExpressionEmpty())
        cout << expression << endl;
    else
        cout << "��������� ������" << endl;
}