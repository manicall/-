#pragma once
#undef UNICODE
#include "Windows.h"

class CurrentInformation {
protected:
	enum Move { PLAYER, COMPUTER };
	int currentDay;    // ������� ����
	int currentMonth;  // ������� �����
	int CountMove;     // ���������� ��������� �����
	/*�� ������ ���� �� �������� ��� ���*/

	bool currentMove;  // ������� ���
	// ��������, ���������� �� ���������� ��������
	void CheckWin() {
		if (IsGameOver()) {
			MessageBox(0, "���� ��������", "����� ����", 0);
		}
	}
	// ��������, ���������� �� ���������� ��������
	bool IsGameOver() {
		return currentDay == 31 && currentMonth == 11;
	}
	// ���������� ����� ��� ������ ����� ����
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
