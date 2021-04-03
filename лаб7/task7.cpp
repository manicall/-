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
			default: std::cout << "Невозможно выбрать пункт";
			}
		}
		catch (std::exception ex) { std::cout << ex.what(); }
	} while (true);

}

int menu() {
	std::cout << "====================Меню===================" << std::endl;
	std::cout << "1) добавить элемент в список"   << std::endl;
	std::cout << "2) удалить элемент из списка"   << std::endl;
	std::cout << "3) вывести все значения элементов списка" << std::endl;
	std::cout << "4) получить значение узла на позиции" << std::endl;
	std::cout << "5) очистить консоль" << std::endl;
	std::cout << "6) выход" << std::endl;
	std::cout << ">";
	std::string answer; std::cin >> answer;
	int result = atoi(answer.c_str());
	return result;
}
template<class Data>
void read(List<Data>& const List) {
	if (List.isEmpty()) { std::cout << "Cписок пуст" << std::endl; }
	else {
		std::cout << "Введите позицию элемента (от 0 до " + std::to_string(List.get_size() - 1) + "): ";
		int index; std::cin >> index;
		std::cout << "значение узла: " << List.at(index)->data << std::endl;
	}
}
template<class Data>
void add(List<Data>& List) { 
	std::cout << "вставить элемент:\n";
	Data data;
	std::cin >> data;
	std::cout << "на позицию (от 0 до " + std::to_string(List.get_size()) + "): ";
	int index; std::cin >> index;
	List.insert(data, index);
	std::cout << std::endl;
}
template<class Data>
void erase(List<Data>& List) {
	if (List.isEmpty()) { std::cout << "Cписок пуст" << std::endl; }
	else {
		std::cout << "удалить элемент с позиции (от 0 до " + std::to_string(List.get_size() - 1) + "): ";
		int index; std::cin >> index;
		List.erase(index);
	}
}
template<class Data>
void print(List<Data>& const List) {
	if (List.isEmpty()) { std::cout << "Cписок пуст" << std::endl; }
	else {
		std::cout << "элементы списка:\n";
		List.print_list();
	}
}
