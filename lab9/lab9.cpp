#include "QueueOfLong.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	QueueOfLong Queue;
	try {
		cout << "Начало: " << Queue.front()->Long << endl;
		cout << "Конец: " << Queue.back()->Long << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
	Queue.push_back(1);
	cout << "Начало: " << Queue.front()->Long << endl;
	cout << "Конец: " << Queue.back()->Long << endl;
	Queue.push_back(2);
	cout << "Начало: " << Queue.front()->Long << endl;
	cout << "Конец: " << Queue.back()->Long << endl;
	Queue.push_back(3);
	cout << "Начало: " << Queue.front()->Long << endl;
	cout << "Конец: " << Queue.back()->Long << endl;
	Queue.pop_front();
	cout << "Начало: " << Queue.front()->Long << endl;
	cout << "Конец: " << Queue.back()->Long << endl;
	Queue.pop_front();
	cout << "Начало: " << Queue.front()->Long << endl;
	cout << "Конец: " << Queue.back()->Long << endl;
	Queue.pop_front();
	try {
		cout << "Начало: " << Queue.front()->Long << endl;
		cout << "Конец: " << Queue.back()->Long << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }

}