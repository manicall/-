#include "DequeOfStrings.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	DequeOfStrings Deque;
	try {
		cout << "Начало: " << Deque.front()->str << endl;
		cout << "Конец: " << Deque.back()->str << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
	Deque.push_front("слово1");
	cout << "Начало: " << Deque.front()->str << endl;
	cout << "Конец: " << Deque.back()->str << endl;
	Deque.push_front("слово2");
	cout << "Начало: " << Deque.front()->str << endl;
	cout << "Конец: " << Deque.back()->str << endl;
	Deque.push_back("слово3");
	cout << "Начало: " << Deque.front()->str << endl;
	cout << "Конец: " << Deque.back()->str << endl;
	Deque.pop_back();
	cout << "Начало: " << Deque.front()->str << endl;
	cout << "Конец: " << Deque.back()->str << endl;
	Deque.pop_front();
	cout << "Начало: " << Deque.front()->str << endl;
	cout << "Конец: " << Deque.back()->str << endl;
	Deque.pop_front();
	try{
		cout << "Начало: " << Deque.front()->str << endl;
		cout << "Конец: " << Deque.back()->str << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
}