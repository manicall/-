#pragma once
#undef UNICODE

#include "framework.h"
#include "Resource.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <windowsx.h>

class ListOfDates {
	std::map<std::string, int> days;
	std::vector<std::string> months;
	int curDay = 1, curMonth = 0, 
		turn = 0; // ���������� ��������� �����
	bool curturn; // �� ������ ���� �� �������� ��� ���

public:
	ListOfDates() {
		months = {
			"������",	"�������",	"�����",
			"������",	"���",		"����",
			"����",		"�������",	"��������",
			"�������",	"������",	"�������"
		};
		for (int i = 0; i < 12; i++) // ������������ ���� ��� ������� ������
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
				days[months[i]] = 31;
			else if (i == 3 || i == 5 || i == 8 || i == 10)
				days[months[i]] = 30;
			else
				days[months[i]] = 28;
		}
	}


	void ListBoxClear(HWND hList) {
		for (int Count = ListBox_GetCount(hList); Count > 0; Count--)
			ListBox_DeleteString(hList, 0);
	}

	void ChangeDaysState(HWND hList) {
		if (!ListBox_GetCaretIndex(hList))
			MessageBoxA(0, "���������� ����������� �����, ��� ��� ���� �������� �������", 0, 0 | MB_ICONERROR);
		else {
			curDay += ListBox_GetCaretIndex(hList);
		}
	}
	void ChangeMonthsState(HWND hList) {
		if (!ListBox_GetCaretIndex(hList))
			MessageBoxA(0, "���������� ����������� �����, ��� ��� ����� �������� �������", 0, 0 | MB_ICONERROR);
		else {
			curMonth += ListBox_GetCaretIndex(hList);
		}
	}

	void DaysInListBox(HWND hList) {
		ListBoxClear(hList);
		for (int day = curDay; day <= days[months[curMonth]]; day++) // �� ���������� ��� �� ���������� ���� � ������
			ListBox_AddString(hList, (std::to_string(day) + " " + months[curMonth]).c_str());
		ListBox_SetCurSel(hList, 0);
	}
	void MonthInListBox(HWND hList) {
		ListBoxClear(hList);
		// ������� � ������ ������ �� �������� �� ������� 
		std::for_each(months.begin() + curMonth, months.end(), [&](std::string month) { 
				ListBox_AddString(hList, (std::to_string(curDay) + " " + month).c_str());
			}
		);
		ListBox_SetCurSel(hList, 0);
	}
};