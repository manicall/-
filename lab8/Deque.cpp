#include "Deque.h"

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
	std::cout << "Добавляем слово " << NewStr << " в конец: " << std::endl;// отладка
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
	std::cout << "Добавляем слово " << NewStr << " в начало: " << std::endl;// отладка
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
