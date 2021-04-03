#include <string>
#include "List.h"
#include <list>

enum {ADD = 1, ERASE, PRINT, READ, CLEAR, EXIT};
int menu();
template<class Data>
void read(List<Data>& List);
template<class Data>
void add(List<Data>& );
template<class Data>
void erase(List<Data>&);
template<class Data>
void print(List<Data>& const);

int main()
{
	setlocale(LC_ALL, "ru");
	List<Point2D> Points2D;

	do {
		try {
			switch (menu()) {
			case ADD:   add(Points2D);   break;
			case ERASE: erase(Points2D); break;
			case PRINT: print(Points2D); break;
			case READ:  read(Points2D); break;
			case CLEAR: system("cls");   break;
			case EXIT:  return 0;
			default: std::cout << "���������� ������� �����";
			}
		}
		catch (std::exception ex) { std::cout << ex.what(); }
	} while (true);

}

int menu() {
	std::cout << "====================����===================" << std::endl;
	std::cout << "1) �������� ������� � ������"   << std::endl;
	std::cout << "2) ������� ������� �� ������"   << std::endl;
	std::cout << "3) ������� ��� �������� ��������� ������" << std::endl;
	std::cout << "4) �������� �������� ���� �� �������" << std::endl;
	std::cout << "5) �������� �������" << std::endl;
	std::cout << "6) �����" << std::endl;
	std::cout << ">";
	std::string answer; std::cin >> answer;
	int result = atoi(answer.c_str());
	return result;
}
template<class Data>
void read(List<Data>& const List) {
	if (List.isEmpty()) { std::cout << "C����� ����" << std::endl; }
	else {
		std::cout << "������� ������� �������� (�� 0 �� " + std::to_string(List.get_size() - 1) + "): ";
		int index; std::cin >> index;
		std::cout << "�������� ����: " << List.at(index)->data << std::endl;
	}
}
template<class Data>
void add(List<Data>& List) { 
	std::cout << "�������� �������:\n";
	Data data;
	std::cin >> data;
	std::cout << "�� ������� (�� 0 �� " + std::to_string(List.get_size()) + "): ";
	int index; std::cin >> index;
	List.insert(data, index);
	std::cout << std::endl;
}
template<class Data>
void erase(List<Data>& List) {
	if (List.isEmpty()) { std::cout << "C����� ����" << std::endl; }
	else {
		std::cout << "������� ������� � ������� (�� 0 �� " + std::to_string(List.get_size() - 1) + "): ";
		int index; std::cin >> index;
		List.erase(index);
	}
}
template<class Data>
void print(List<Data>& const List) {
	if (List.isEmpty()) { std::cout << "C����� ����" << std::endl; }
	else {
		std::cout << "�������� ������:\n";
		List.print_list();
	}
}
