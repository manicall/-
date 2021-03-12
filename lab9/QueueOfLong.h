#pragma once
#include <iostream>
class QueueOfLong {
	int size;
	class Node {
	public:
		Node* next, * prev;
		int long Long;

		Node(int long Long, Node* next = nullptr, Node* prev = nullptr) : Long(Long), next(next), prev(prev) { }
	};
	Node* begin;
	Node* end;

public:
	QueueOfLong() : size(0), begin(nullptr), end(nullptr) {};
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
	void pop_front();
	void push_back(int long);
};

