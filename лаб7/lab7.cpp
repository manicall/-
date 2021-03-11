#include <iostream>

class xyPoint {
public:
	double x, y;
	xyPoint() : x(0), y(0) { }
	xyPoint(double x, double y) : x(x), y(y) { }

	friend std::ostream& operator << (std::ostream& out, xyPoint& pt) { // ¬ывод
		return out << "(" << pt.x << "; " << pt.y << ")" << std::endl;
	}
};


class ListOfPoints {
	int size;
	class Node {
	public:
		Node *next, *prev;
		xyPoint pt;

		Node(xyPoint pt, Node* next = nullptr, Node* prev = nullptr) : pt(pt), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	ListOfPoints() : size(0), begin(nullptr), end(nullptr) {};
	//----------------
	xyPoint& at(int);
	void check_index(int, std::string str); // str - действие, при котором индекс оказалс€ некорректным
	int get_size() { return size; }
	void pop(int);
	void insert(xyPoint, int);
	void print_list();
	void push_back(xyPoint);
	void push_front(xyPoint);




};


xyPoint& ListOfPoints::at(int index)
{
	try { check_index(index, "ѕолучить"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }

	Node* current = this->begin;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	return current->pt;
}

void ListOfPoints::check_index(int index, std::string action)
{
	if (action == "ѕолучить" && index >= size) 
		throw std::exception((action + " элемент невозможно: выход за пределы списка.").c_str()); 
	if (index > size)
		throw std::exception((action + " элемент невозможно: индекс превышает размер списка.").c_str());
	else if (index < 0)
		throw std::exception((action + " элемент невозможно: индекс оказалс€ меньше нул€.").c_str());
}

void ListOfPoints::pop(int index)
{
	try { check_index(index, "”далить"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }


}

void ListOfPoints::insert(xyPoint pt, int index = 0) {
	try { check_index(index, "ƒобавить"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }

    if (!index){
		push_front(pt);
		return;
	}
	else if (index == size) {
		push_back(pt);
		return;
	}
	else {

		if (index <= size / 2)
		{
			Node* current = begin;
			/*
			нужно найти элемент,
			которому следует передать указатель на новый
			*/
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node* temp = current->next; // сохран€ем старый указатель
			current->next = new Node(pt, temp, current);  // current <-> NewNode ->  temp
			temp->prev = current->next;   // current <-> NewNode <->  temp
		}
		else {
			Node* current = end;

			for (int i = 0; i < index / 2 - 1; i++) {
				current = current->prev;
			}
			Node* temp = current->prev; // сохран€ем старый указатель
			current->prev = new Node(pt, current, temp); // temp <- NewNode <-> current
			temp->next = current->prev;  // temp <-> prev <-> current
		}
	}
	size++;
}

void ListOfPoints::print_list()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << at(i);
	}
	std::cout << std::endl;
}

void ListOfPoints::push_back(xyPoint pt)
{

	if (end == nullptr) {
		end = new Node(pt);
		begin = end;
	}
	else if (size == 1) {
		end = new Node(pt, nullptr, begin); // begin <- end
		begin->next = end;   // begin <-> end
	}
	else {
		Node* current = end;
		current->next = new Node(pt, nullptr, current);
		end = current->next;
	}
	size++;
}

void ListOfPoints::push_front(xyPoint pt)
{
	if (begin == nullptr) {
		begin = new Node(pt);
		end = begin;
	}
	else if (size == 1) {
		begin = new Node(pt, end, nullptr); // begin -> end
		end->prev = begin; // begin <-> end
	}
	else {
		Node* current = begin;
		current->prev = new Node(pt, current, nullptr);
		begin = current->prev;
	}
	size++;	
}

int main()
{
	setlocale(LC_ALL, "ru");
	ListOfPoints List;

	try {
		List.insert(xyPoint(1, 2));
		List.insert(xyPoint(4, 5), 1);
		List.insert(xyPoint(40, 50), 1);
		List.print_list();
		List.insert(xyPoint(400, 500), 1);
		List.print_list();
		List.insert(xyPoint(11, 45), 1);
		List.print_list();
		List.insert(xyPoint(1, 111), 4);
		List.print_list();
		List.insert(xyPoint(55, 55), 3);
		List.print_list();

	
		//std::cout << List.at(10);
		//List.pop(-10);
	}
	catch (std::exception ex) { std::cerr << ex.what()<<std::endl; }

}