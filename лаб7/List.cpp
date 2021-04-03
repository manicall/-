#include "List.h"


template <class Data>
void List<Data>::check_index(int index, std::string action)
{
	if ((action == "��������" || action == "�������") && index >= size)
		throw std::exception((action + " ������� ����������: ����� �� ������� ������.").c_str());
	if (index > size)
		throw std::exception((action + " ������� ����������: ������ ��������� ������ ������.").c_str());
	else if (index < 0)
		throw std::exception((action + " ������� ����������: ������ �������� ������ ����.").c_str());
}

template <class Data>
void List<Data>::erase(int index)
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

template <class Data>
void List<Data>::pop_back()
{
	if (end == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = end;
	end = temp->prev;
	delete temp;
	size--;
}

template <class Data>
void List<Data>::pop_front()
{
	if (begin == nullptr) { std::cout << "�������� ����������" << std::endl; return; }
	Node* temp = begin;
	begin = temp->next;
	delete temp;
	size--;
}

template <class Data>
void List<Data>::insert(Data data, int index) {
	std::cout << "�� �������: " << index << " ��������: " << data; // ������� 
	try { check_index(index, "��������"); }
	catch (std::exception ex) { throw std::exception(ex.what()); }

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
			����� ����� �������,
			�������� ������� �������� ��������� �� �����
			*/
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node* temp = current->next; // ��������� ������ ���������
			current->next = new Node(data, temp, current);  // current <-> NewNode ->  temp
			temp->prev = current->next;   // current <-> NewNode <->  temp
		}
		else {
			Node* current = end;

			for (int i = 0; i < size - index - 1; i++) {
				current = current->prev;
			}
			Node* temp = current->prev; // ��������� ������ ���������
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
		std::cout << i << ") " << at(i)->data;
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
		end->prev = begin; // begin <-> end
	}
	else {
		Node* current = begin;
		current->prev = new Node(data, current, nullptr);
		begin = current->prev;
	}
	size++;
}
