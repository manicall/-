#include "Queue.h"
using namespace std;
enum { ADDBACK = 1, POPFRONT, GETFRONT, GETBACK, CLEAR, EXIT };
int menu();
void AddBack(Queue&);
int main()
{
	setlocale(LC_ALL, "ru");
	Queue Queue;

	do {
		try {
			switch (menu()) {		
			case ADDBACK:   AddBack(Queue);		break;
			case POPFRONT:  Queue.pop_front();	break;
			case GETFRONT:  cout << "������: " << Queue.front()->Long << endl; break;
			case GETBACK:   cout << "�����: " << Queue.back()->Long << endl; break;
			case CLEAR: system("cls");   break;
			case EXIT:  return 0;
			default: std::cout << "���������� ������� �����\n";
			}
		}
		catch (std::exception ex) { std::cout << ex.what(); }
	} while (true);

}
int menu() {
	std::cout << "====================����===================" << std::endl;
	std::cout << "1) �������� ������� � ����� �������" << std::endl;
	std::cout << "2) ������� ������� �� ������ �������" << std::endl;
	std::cout << "3) ������� ������ ������� �������" << std::endl;
	std::cout << "4) ������� ��������� ������� �������" << std::endl;
	std::cout << "5) �������� �������" << std::endl;
	std::cout << "6) �����" << std::endl;
	std::cout << ">";
	std::string answer; std::cin >> answer;
	int result = atoi(answer.c_str());
	return result;
}
void AddBack(Queue& Queue) {
	cout << "������� �������: ";
	long long element; std::cin >> element;
	Queue.push_back(element);
}