#pragma once
#include <iostream>
class Deque {
	int size;
	class Node {
	public:
		Node *next;
		Node *prev;
		std::string str;

		Node(std::string str, Node* next = nullptr, Node* prev = nullptr) : str(str), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	Deque() : size(0), begin(nullptr), end(nullptr) {};
	//----------------
	Node* back() { 
		if (isEmpty())
			throw std::exception("Дек пуст\n"); 
		else
			return end;
	}
	Node* front() {
		if (isEmpty())
			throw std::exception("Дек пуст\n");
		else
			return begin;
	}
	int get_size() { return size; }
	bool isEmpty() { return !size; }
	void pop_back();
	void pop_front();         
	void push_back(std::string);
	void push_front(std::string);
};

void Deque::pop_back()
{
	if (isEmpty()) { std::cout << "Дек пуст" << std::endl; return; }
	Node* temp = end;
	end = temp->prev;
	delete temp;
	size--;
	if (isEmpty())
		begin = nullptr;
}

void Deque::pop_front()
{
	if (isEmpty()) { std::cout << "Дек пуст" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
	if (isEmpty())
		end = nullptr;
}

void Deque::push_back(std::string NewStr)
{
	std::cout << "Добавляем \"" << NewStr << "\" в конец: " << std::endl;// отладка
	if (isEmpty()) {
		end = new Node(NewStr);
		begin = end;
	}
	else if (size == 1) {
		end = new Node(NewStr, nullptr, begin); // begin <- end
		begin->next = end;   // begin <-> end
	}
	else {
		Node* current = end;
		current->next = new Node(NewStr, nullptr, current);
		end = current->next;
	}
	size++;
}

void Deque::push_front(std::string NewStr)
{
	std::cout << "Добавляем \"" << NewStr << "\" в начало: " << std::endl;// отладка
	if (isEmpty()) {
		begin = new Node(NewStr);
		end = begin;
	}
	else if (size == 1) {
		begin = new Node(NewStr, end, nullptr); // begin -> end
		end->prev = begin; // begin <-> end
	}
	else {
		Node* current = begin;
		current->prev = new Node(NewStr, current, nullptr);
		begin = current->prev;
	}
	size++;
}
