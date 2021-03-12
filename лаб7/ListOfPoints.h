#pragma once
#include "xyPoint.h"
class ListOfPoints {
	int size;
	class Node {
	public:
		Node* next;
		Node * prev;
		xyPoint pt;

		Node(xyPoint pt, Node* next = nullptr, Node* prev = nullptr) : pt(pt), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	ListOfPoints() : size(0), begin(nullptr), end(nullptr) {};
	//----------------
	Node* at(int index)
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
	int get_size() { return size; }
	void pop(int);
	void pop_back();
	void pop_front();
	void insert(xyPoint, int);
	void print_list();
	void push_back(xyPoint);
	void push_front(xyPoint);
};

