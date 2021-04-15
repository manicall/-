#pragma once
#undef UNICODE
#include "Windows.h"

class CurrentInformation {
protected:
	enum Move { PLAYER, COMPUTER };
	int currentDay;    // текущий день
	int currentMonth;  // текущий месяц
	int CountMove;     // количество сделанных ходов
	/*до начала игры не известно чей ход*/

	bool currentMove;  // текущий ход
	// проверка, достигнута ли выйгрышная ситуация
	void CheckWin() {
		if (IsGameOver()) {
			MessageBox(0, "Игра окончена", "Конец игры", 0);
		}
	}
	// проверка, достигнута ли выйгрышная ситуация
	bool IsGameOver() {
		return currentDay == 31 && currentMonth == 11;
	}
	// обновление полей для начала новой игры
	void NewGame() {
		currentDay = 1;
		currentMonth = 0;
		CountMove = 0;
		currentMove = Move::PLAYER;
	}
	void ChangeCurrentMove() {
		if (currentMove == PLAYER)
			currentMove = COMPUTER;
		else
			currentMove = PLAYER;
	}
public:
	CurrentInformation() {
		NewGame();
	}
};
