#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
bool check_brackets(string expression) {
    stack<char> brackets;
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
int main() {
    ifstream file("input.txt");
    string expression;
    while (!file.eof()) { 
        string temp;
        file >> temp;
        expression += temp;
    }
    cout << expression;
    if (check_brackets(expression)) { 
        std::cout << "true" << endl;
    }
    else {
        std::cout << "false" << endl;
    }
        
}