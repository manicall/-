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
        if (c == '<' || c == '{') { // добавляем открывающуюю скобку
            brackets.push(c);
            continue;
        }
        if (c != '<' && c != '{' && c != '>' && c != '}') // если попался любой символ кроме скобки
            continue;
        if (!brackets.empty()) {
            if (c == '>' && brackets.top() != '<')  // соответствие угловых скобок
                return false;
            if (c == '}' && brackets.top() != '{')  // соответствие фигурных скобок
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
        cout << "Скобки отсутствуют" << endl;
    else {
        if (IsBracketsMatch())
            cout << "Скобки совпадают" << endl;
        else
            cout << "Скобки не совпадают" << endl;
    }
}

void Brackets::PrintExpression() {
    if (!IsExpressionEmpty())
        cout << expression << endl;
    else
        cout << "Выражение пустое" << endl;
}