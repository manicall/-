#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Brackets {
    stack<char> brackets;
    string expression;
public:
    Brackets() {
        cout << "������� ������: "; getline(cin, expression);
    }

    bool IsBracketsMatch();
    void PrintAnswer();
    void PrintExpression();
    bool IsBracketsExist() {
        for (auto c : expression)
        { 
            if(c == '<' || c == '{' || c == '>' || c == '}')
            return true; 
        }
        return false;
    }
    bool IsExpressionEmpty() {
        if (expression == "")
            return true;
        else return false;
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
    if (!IsBracketsExist())
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