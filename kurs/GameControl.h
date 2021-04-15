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
	// вывод дней в листбокс начина€ от текущего + 1
	void DaysInListBox();   
	// вывод мес€цев в листбокс начина€ от текущего + 1
	void MonthsInListBox(); 
	// изменение строки состо€ни€ с текущей датой
	void StateDateUpdate() { 
		Static_SetText(hCurrentDate, ("“екуща€ дата: " + std::to_string(currentDay) + " " + months[currentMonth]).c_str());
	}
	// изменение строки состо€ни€ с информацией о том кто делает ход
	void CurrentMoveUpdate() {
		ChangeCurrentMove();
		if (currentMove == PLAYER)
			Static_SetText(hCurrentMove, "’од игрока");
		else
			Static_SetText(hCurrentMove, "’од компьтера");
	}
	void CountMoveUpdate() {
		CountMove++;
		Static_SetText(hCountMove, ("“екущий ход: " + std::to_string(CountMove)).c_str());
	}
public:
	// прин€тие хода игрока
	void PlayerMakeAMove();
	// обновление дат, после сделанного хода
	void ListBoxUpdate();
	// начало новой игры
	void StartNewGame();
	// обновление текущей даты
	void SetCurrentDay() { 
		SetCurrentDay(ListBox_GetCaretIndex(hList));
	}
	// обновление текущей даты
	void SetCurrentDay(int index);
	// обновление текущего мес€ца
	void SetCurrentMonth() { 
		SetCurrentMonth(ListBox_GetCaretIndex(hList));
	}
	// обновление текущего мес€ца
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
	for (int day = currentDay + CURRENT; day <= days[months[currentMonth]]; day++) // от выбранного дн€ до количества дней в мес€це
		ListBox_AddString(hList, (std::to_string(day) + " " + months[currentMonth]).c_str());
	ListBox_SetCurSel(hList, 0);
}

inline void GameControl::MonthsInListBox()
{
	ListBoxClear(hList);
	// вывести в список мес€цы от текущего до декабр€ 
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
		MessageBoxA(0, "Ќевозможно подтвердить выбор,\nтак как необходимо выбрать дни или мес€цы", 0, 0 | MB_ICONERROR);	
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
			ListBoxUpdate(); // если список пуст
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

