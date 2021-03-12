#include "ListOfPoints.h"


void ListOfPoints::check_index(int index, std::string action)
{
	if ((action == "��������" || action == "�������") && index >= size)
		throw std::exception((action + " ������� ����������: ����� �� ������� ������.").c_str());
	if (index > size)
		throw std::exception((action + " ������� ����������: ������ ��������� ������ ������.").c_str());
	else if (index < 0)
		throw std::exception((action + " ������� ����������: ������ �������� ������ ����.").c_str());
}

void ListOfPoints::pop(int index)
{
	std::cout << "������� ������� � �������: " << index << std::endl; // ������� 
	try { check_index(index, "�������"); }
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
	Node* pNext = current->next; // ��������� ������ ���������
	Node* pPrev = current->prev; // ��������� ������ ���������
	pNext->prev = pPrev;
	pPrev->next = pNext;
	delete current;
	size--;
}

void ListOfPoints::pop_back()
{
	if (end == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = end;
	end = temp->prev;
	delete temp;
	size--;
}

void ListOfPoints::pop_front()
{
	if (begin == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
}

void ListOfPoints::insert(xyPoint pt, int index) {
	std::cout << "�� �������: " << index << " ��������: " << pt; // ������� 
	try { check_index(index, "��������"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }

	if (!index) {
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
			����� ����� �������,
			�������� ������� �������� ��������� �� �����
			*/
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node* temp = current->next; // ��������� ������ ���������
			current->next = new Node(pt, temp, current);  // current <-> NewNode ->  temp
			temp->prev = current->next;   // current <-> NewNode <->  temp
		}
		else {
			Node* current = end;

			for (int i = 0; i < size - index - 1; i++) {
				current = current->prev;
			}
			Node* temp = current->prev; // ��������� ������ ���������
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
		std::cout << i << ") "<< at(i)->pt;
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
