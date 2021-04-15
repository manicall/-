#pragma once
#undef UNICODE

#include "Controls.h"
#include "CurrentInformation.h"
#include "DatesForGame.h"
#include "Opponent.h"
#include <algorithm>

class GameControl : public DatesForGame, public CurrentInformation, public Controls {

	const short CURRENT = 1;
	Opponent computer;
	// ����� ���� � �������� ������� �� �������� + 1
	void DaysInListBox();   
	// ����� ������� � �������� ������� �� �������� + 1
	void MonthsInListBox(); 
	// ��������� ������ ��������� � ������� �����
	void StateDateUpdate() { 
		Static_SetText(hCurrentDate, ("������� ����: " + std::to_string(currentDay) + " " + months[currentMonth]).c_str());
	}
	// ��������� ������ ��������� � ����������� � ��� ��� ������ ���
	void CurrentMoveUpdate() {
		ChangeCurrentMove();
		if (currentMove == PLAYER)
			Static_SetText(hCurrentMove, "��� ������");
		else
			Static_SetText(hCurrentMove, "��� ���������");
	}
	void CountMoveUpdate() {
		CountMove++;
		Static_SetText(hCountMove, ("������� ���: " + std::to_string(CountMove)).c_str());
	}
public:
	// �������� ���� ������
	void PlayerMakeAMove();
	// ���������� ���, ����� ���������� ����
	void ListBoxUpdate();
	// ������ ����� ����
	void StartNewGame();
	// ���������� ������� ����
	void SetCurrentDay() { 
		SetCurrentDay(ListBox_GetCaretIndex(hList));
	}
	// ���������� ������� ����
	void SetCurrentDay(int index);
	// ���������� �������� ������
	void SetCurrentMonth() { 
		SetCurrentMonth(ListBox_GetCaretIndex(hList));
	}
	// ���������� �������� ������
	void SetCurrentMonth(int index);
	void SetControls(HWND hList, HWND hDays, HWND hMonths, HWND hCurrentDate, HWND hCurrentMove, HWND); 

	void AcceptMove() {
		ListBoxUpdate();
		CurrentMoveUpdate();
		CountMoveUpdate();

	}
	void Move() {
		if (!IsGameOver()) {
			PlayerMakeAMove();
			AcceptMove();

			computer.MakeAMove(currentDay, currentMonth);
			//AcceptMove();
		}
		CheckWin();
	}
};

inline void GameControl::DaysInListBox()
{
	ListBoxClear(hList);
	for (int day = currentDay + CURRENT; day <= days[months[currentMonth]]; day++) // �� ���������� ��� �� ���������� ���� � ������
		ListBox_AddString(hList, (std::to_string(day) + " " + months[currentMonth]).c_str());
	ListBox_SetCurSel(hList, 0);
}

inline void GameControl::MonthsInListBox()
{
	ListBoxClear(hList);
	// ������� � ������ ������ �� �������� �� ������� 
	std::for_each(months.begin() + currentMonth + CURRENT, months.end(), [&](std::string month) {
		ListBox_AddString(hList, (std::to_string(currentDay) + " " + month).c_str());
		}
	);
	ListBox_SetCurSel(hList, 0);
}

inline void GameControl::PlayerMakeAMove() {
	if (Button_GetCheck(hDays))
		SetCurrentDay();			
	else if (Button_GetCheck(hMonths))
		SetCurrentMonth();
	else 
		MessageBoxA(0, "���������� ����������� �����,\n��� ��� ���������� ������� ��� ��� ������", 0, 0 | MB_ICONERROR);	
	ListBoxClear(hList);
}

inline void GameControl::ListBoxUpdate()
{
	if (Button_GetCheck(hMonths))
		MonthsInListBox();
	else {
		Button_SetCheck(hDays, true);
		DaysInListBox();
	}
	if (IsListBoxEmpty()){
		ChangeRadioButton();
		if (!IsGameOver())
			ListBoxUpdate(); // ���� ������ ����
	}
	StateDateUpdate();	
}

inline void GameControl::StartNewGame()
{
	NewGame();
	Button_Enable(hDays, true);
	Button_Enable(hMonths, true);
	if (Button_GetCheck(hMonths))
		ChangeRadioButton();
	ListBoxUpdate();
}

inline void GameControl::SetCurrentDay(int index)
{
	currentDay += index + CURRENT;
}

inline void GameControl::SetCurrentMonth(int index)
{
	currentMonth += index + CURRENT;
}

inline void GameControl::SetControls(HWND hList, HWND hDays, HWND hMonths, HWND hCurrentDate, HWND hCurrentMove, HWND hCountMove)
{
	this->hList = hList;
	this->hDays = hDays;
	this->hMonths = hMonths;
	this->hCurrentDate = hCurrentDate;
	this->hCurrentMove = hCurrentMove;
	this->hCountMove = hCountMove;
}

