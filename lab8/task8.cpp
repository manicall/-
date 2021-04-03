#include "Windows.h"
#include "Deque.h"
#include <string>
using namespace std;

enum {ADDFRONT = 1, ADDBACK, POPFRONT, POPBACK, GETFRONT, GETBACK, CLEAR, EXIT};
void AddFront(Deque&);
void AddBack(Deque&);
int menu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Deque Deque;

	do {
		try {
			switch (menu()) {
			case ADDFRONT:  AddFront(Deque);	break;
			case ADDBACK:   AddBack(Deque);		break;
			case POPFRONT:  Deque.pop_front();	break;
			case POPBACK:   Deque.pop_back();	break;
			case GETFRONT:  cout << "������: " << Deque.front()->str << endl; break;
			case GETBACK:   cout << "�����: "  << Deque.back()->str  << endl; break;
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
	std::cout << "1) �������� ������� � ������ ����" << std::endl;
	std::cout << "2) �������� ������� � ����� ����" << std::endl;
	std::cout << "3) ������� ������� �� ������ ����" << std::endl;
	std::cout << "4) ������� ������� �� ����� ����" << std::endl;
	std::cout << "5) ������� ������ ������� ����" << std::endl;
	std::cout << "6) ������� ��������� ������� ����" << std::endl;
	std::cout << "7) �������� �������" << std::endl;
	std::cout << "8) �����" << std::endl;
	std::cout << ">";
	std::string answer; std::cin >> answer;
	int result = atoi(answer.c_str());
	return result;
}
void AddFront(Deque& Deque) {
	cout << "������� �������: ";
	std::string element; 
	cin.ignore();  getline(cin, element);
	Deque.push_front(element);
}
void AddBack(Deque& Deque) {
	cout << "������� �������: ";
	std::string element; 
	cin.ignore();  getline(cin, element);
	Deque.push_back(element);
}