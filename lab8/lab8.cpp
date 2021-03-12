#include "DequeOfStrings.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	DequeOfStrings Deque;
	try {
		cout << "������: " << Deque.front()->str << endl;
		cout << "�����: " << Deque.back()->str << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
	Deque.push_front("�����1");
	cout << "������: " << Deque.front()->str << endl;
	cout << "�����: " << Deque.back()->str << endl;
	Deque.push_front("�����2");
	cout << "������: " << Deque.front()->str << endl;
	cout << "�����: " << Deque.back()->str << endl;
	Deque.push_back("�����3");
	cout << "������: " << Deque.front()->str << endl;
	cout << "�����: " << Deque.back()->str << endl;
	Deque.pop_back();
	cout << "������: " << Deque.front()->str << endl;
	cout << "�����: " << Deque.back()->str << endl;
	Deque.pop_front();
	cout << "������: " << Deque.front()->str << endl;
	cout << "�����: " << Deque.back()->str << endl;
	Deque.pop_front();
	try{
		cout << "������: " << Deque.front()->str << endl;
		cout << "�����: " << Deque.back()->str << endl;
	}
	catch (exception ex) { cerr << ex.what() << endl; }
}