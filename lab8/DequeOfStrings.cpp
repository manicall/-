#include "DequeOfStrings.h"

void DequeOfStrings::pop_back()
{
	std::cout << "�������� ����� �� �����: " << std::endl;// �������
	if (end == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = end;
	end = temp->prev;
	delete temp;
	size--;
}

void DequeOfStrings::pop_front()
{
	std::cout << "�������� ����� �� ������: " << std::endl;// �������
	if (begin == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
}

void DequeOfStrings::push_back(std::string NewStr)
{
	std::cout << "��������� ����� " << NewStr << " � �����: " << std::endl;// �������
	if (end == nullptr) {
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

void DequeOfStrings::push_front(std::string NewStr)
{ 
	std::cout << "��������� ����� " << NewStr << " � ������: " << std::endl;// �������
	if (begin == nullptr) {
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
