#pragma once
#undef UNICODE
#include "Windows.h"
#include <string>

class CurrentInformation {
protected:
	enum Move { PLAYER, COMPUTER };
	const int MAXDAY = 31, MAXMONTH = 11;
	int currentDay;    // текущий день
	int currentMonth;  // текущий месяц
	int countMove;     // количество сделанных ходов
	/*до начала игры не известно чей ход*/

	bool currentMove;  // текущий ход
	// проверка, достигнута ли выйгрышная ситуация
	void CheckWin() {
		if (IsGameOver()) {
			std::string winner = currentMove ? "игрок" : "компьютер";
			std::string count = std::to_string(countMove);
			MessageBox(0, ("Игра окончена. Победил " + winner + " за " + count + " ходов").c_str(), "Конец игры", 0);
		}
	}
	// проверка, достигнута ли выйгрышная ситуация
	bool IsGameOver() {
		return currentDay == MAXDAY && currentMonth == MAXMONTH;
	}
	// обновление полей для начала новой игры
	void NewGame() {
		currentDay = 1;
		currentMonth = 0;
		countMove = 0;
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
