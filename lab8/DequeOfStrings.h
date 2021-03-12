#pragma once
#include <iostream>
class DequeOfStrings {
	int size;
	class Node {
	public:
		Node* next;
		Node *prev;
		std::string str;

		Node(std::string str, Node* next = nullptr, Node* prev = nullptr) : str(str), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	DequeOfStrings() : size(0), begin(nullptr), end(nullptr) {};
	//----------------
	Node* back() { 
		if (!size)
			throw std::exception("Обработка ошибки: Очередь пуста."); 
		else
			return end;
	}
	Node* front() {
		if (!size)
			throw std::exception("Обработка ошибки: Очередь пуста.");
		else
			return begin;
	}
	int get_size() { return size; }
	void pop_back();
	void pop_front();         
	void push_back(std::string);
	void push_front(std::string);
};