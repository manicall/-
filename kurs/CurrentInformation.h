#pragma once
#undef UNICODE
#include "Windows.h"
#include <string>

class CurrentInformation {
protected:
	enum Move { PLAYER, COMPUTER };
	const int MAXDAY = 31, MAXMONTH = 11;
	int currentDay;    // ������� ����
	int currentMonth;  // ������� �����
	int countMove;     // ���������� ��������� �����
	/*�� ������ ���� �� �������� ��� ���*/

	bool currentMove;  // ������� ���
	// ��������, ���������� �� ���������� ��������
	void CheckWin() {
		if (IsGameOver()) {
			std::string winner = currentMove ? "�����" : "���������";
			std::string count = std::to_string(countMove);
			MessageBox(0, ("���� ��������. ������� " + winner + " �� " + count + " �����").c_str(), "����� ����", 0);
		}
	}
	// ��������, ���������� �� ���������� ��������
	bool IsGameOver() {
		return currentDay == MAXDAY && currentMonth == MAXMONTH;
	}
	// ���������� ����� ��� ������ ����� ����
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
