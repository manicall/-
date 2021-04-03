#pragma once
#include <iostream>
class Queue {
	int size;
	class Node {
	public:
		Node* next, * prev;
		long long Long;

		Node(long long Long, Node* next = nullptr, Node* prev = nullptr) : Long(Long), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	Queue() : size(0), begin(nullptr), end(nullptr) {};
	//----------------
	Node* back() {
		if (isEmpty())
			throw std::exception("Очередь пуста\n");
		else
			return end;
	}
	Node* front() {
		if (isEmpty())
			throw std::exception("Очередь пуста\n");
		else
			return begin;
	}
	int get_size() { return size; }
	bool isEmpty() { return !size; }
	void pop_front();
	void push_back(long long);
};

void Queue::pop_front()
{
	std::cout << "Удаление слова из начала: " << std::endl;// отладка
	if (isEmpty()) { std::cout << "Очередь пуста" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
	if (isEmpty())
		end = nullptr;
}


void Queue::push_back(long long NewLong)
{
	std::cout << "Добавляем число " << NewLong << " в конец: " << std::endl;// отладка
	if (end == nullptr) {
		end = new Node(NewLong);
		begin = end;
	}
	else if (size == 1) {
		end = new Node(NewLong, nullptr, begin); // begin <- end
		begin->next = end;   // begin <-> end
	}
	else {
		Node* current = end;
		current->next = new Node(NewLong, nullptr, current);
		end = current->next;
	}
	size++;
}
