#include "QueueOfLong.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	QueueOfLong Queue;
	try {
		cout << "������: " << Queue.front()->Long << endl;
		cout << "�����: " << Queue.back()->Long << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
	Queue.push_back(1);
	cout << "������: " << Queue.front()->Long << endl;
	cout << "�����: " << Queue.back()->Long << endl;
	Queue.push_back(2);
	cout << "������: " << Queue.front()->Long << endl;
	cout << "�����: " << Queue.back()->Long << endl;
	Queue.push_back(3);
	cout << "������: " << Queue.front()->Long << endl;
	cout << "�����: " << Queue.back()->Long << endl;
	Queue.pop_front();
	cout << "������: " << Queue.front()->Long << endl;
	cout << "�����: " << Queue.back()->Long << endl;
	Queue.pop_front();
	cout << "������: " << Queue.front()->Long << endl;
	cout << "�����: " << Queue.back()->Long << endl;
	Queue.pop_front();
	try {
		cout << "������: " << Queue.front()->Long << endl;
		cout << "�����: " << Queue.back()->Long << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }

}