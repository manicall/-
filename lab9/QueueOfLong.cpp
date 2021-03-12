#include "QueueOfLong.h"

void QueueOfLong::pop_front()
{
	std::cout << "Удаление слова из начала: " << std::endl;// отладка
	if (begin == nullptr) { std::cout << "Удаление невозможно" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
}


void QueueOfLong::push_back(int long NewLong)
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
