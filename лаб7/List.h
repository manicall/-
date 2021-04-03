#pragma once
#include "Point2D.h"
#include "Point3D.h"


template <class Data>
class List {
	int size;
	class Node {
	public:
		Node *next;
		Node *prev;
		Data data;

		Node(Data data, Node* next = nullptr, Node* prev = nullptr) 
			: data(data), next(next), prev(prev) { }
	};
	Node *begin;
	Node *end;

public:
	List() : size(0), begin(nullptr), end(nullptr) {};
	//--------------------------------------------------

	Node *at(int index)
	{
		try { check_index(index, "Получить"); }
		catch (std::exception ex) { throw std::exception(ex.what()); }

		Node* current = this->begin;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current;
	}

	void check_index(int, std::string str); // str - действие, при котором индекс оказался некорректным
	int  get_size() { return size; }
	bool isEmpty()  { return !size; }
	void erase(int);
	void pop_back();
	void pop_front();
	void insert(Data, int);
	void print_list();
	void push_back(Data);
	void push_front(Data);
};

template <class Data>
void List<Data>::check_index(int index, std::string action)
{
	if ((action == "Получить" || action == "Удалить") && index >= size)
		throw std::exception((action + " элемент невозможно: выход за пределы списка.\n").c_str());
	if (index > size)
		throw std::exception((action + " элемент невозможно: индекс превышает размер списка.\n").c_str());
	else if (index < 0)
		throw std::exception((action + " элемент невозможно: индекс оказался меньше нуля.\n").c_str());
}

template <class Data>
void List<Data>::erase(int index)
{
	try { check_index(index, "Удалить"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }

	if (!index) {
		pop_front();
		return;
	}
	else if (index == size - 1) {
		pop_back();
		return;
	}

	Node* current;
	if (index <= size / 2) {
		current = begin;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
	}
	else {
		current = end;
		for (int i = 0; i < size - index - 1; i++) {
			current = current->prev;
		}
	}
	Node* pNext = current->next; // сохраняем старый указатель
	Node* pPrev = current->prev; // сохраняем старый указатель
	pNext->prev = pPrev;
	pPrev->next = pNext;
	delete current;
	std::cout << "Удалили элемент с позиции: " << index << std::endl; // отладка 
	size--;	
}

template <class Data>
void List<Data>::pop_back()
{
	if (end == nullptr) { std::cout << "Удаление невозможно" << std::endl; return; }
	Node* temp = end;
	end = temp->prev;
	end->next = begin;
	begin->prev = end;
	delete temp;
	size--;
}

template <class Data>
void List<Data>::pop_front()
{
	if (begin == nullptr) { std::cout << "Удаление невозможно" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	begin->prev = end;
	end->next = begin;
	delete temp;
	size--;
}

template <class Data>
void List<Data>::insert(Data data, int index) {
	
	try { check_index(index, "Добавить"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }
	std::cout << "На позицию: " << index << " Добавили: " << data; // отладка 
	if (!index) {
		push_front(data);
		return;
	}
	else if (index == size) {
		push_back(data);
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
			Node* temp = current->next; // сохраняем старый указатель
			current->next = new Node(data, temp, current);  // current <-> NewNode ->  temp
			temp->prev = current->next;   // current <-> NewNode <->  temp
		}
		else {
			Node* current = end;
			for (int i = 0; i < size - index - 1; i++) {
				current = current->prev;
			}
			Node* temp = current->prev; // сохраняем старый указатель
			current->prev = new Node(data, current, temp); // temp <- NewNode <-> current
			temp->next = current->prev;  // temp <-> prev <-> current
		}
	}
	size++;
}

template <class Data>
void List<Data>::print_list()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << ") " << at(i)->data << std::endl;
	}
	std::cout << std::endl;
}

template <class Data>
void List<Data>::push_back(Data data)
{
	if (end == nullptr) {
		end = new Node(data);
		begin = end;
	}
	else if (size == 1) {
		end = new Node(data, nullptr, begin); // begin <- end
		begin->prev = end;
		begin->next = end;   // begin <-> end
	}
	else {
		Node* current = end;
		current->next = new Node(data, nullptr, current);
		end = current->next;
	}
	size++;
}

template <class Data>
void List<Data>::push_front(Data data)
{
	if (begin == nullptr) {
		begin = new Node(data);
		end = begin;
	}
	else if (size == 1) {
		begin = new Node(data, end, nullptr); // begin -> end
		end->next = begin;
		end->prev = begin; // begin <-> end
	}
	else {
		Node* current = begin;
		current->prev = new Node(data, current, nullptr);
		begin = current->prev;
	}
	size++;
}
