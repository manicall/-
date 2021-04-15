#pragma once
#include "DatesForGame.h"
#include <vector>
#include <random> 
#include <ctime>
#include <algorithm>
#include <list>

class Date {
	int day;
	int month;
public:
	Date(int _day, int _month) : day(_day), month(_month) {}
	int GetDay() { return day; }
	int GetMonth() { return month; }

	Date& operator++() {
		if (month < 12)
			++month;
		else
			++day;
		return *this;
	}
	bool operator<(const Date& right) {
		return day < right.day || month < right.month;
	}
};

class PositionEval {
	int eval;
public:
	int CalculateEval(int currentDay, int currentMonth) {
		if (currentDay % 2 == 1 && currentMonth % 2 == 1)
			return 5;
		else if (currentDay % 2 == 0 && currentMonth % 2 == 0)
			return 5;
		else
			return -5;
	}
};

class  Opponent : protected DatesForGame {

	PositionEval positionEval;

	int random(int min, int max)
	{
		std::mt19937 gen(time(0));
		std::uniform_int_distribution<> uid(min, max);
		return uid(gen);
	}

	std::list<Date> GenerateDates(Date& const date) {
		std::list<Date> dates;
		for (int i = date.GetDay() + 1; i <= days[months[date.GetMonth() - 1]]; i++)
			dates.push_back(Date(i, date.GetMonth()));
		for (int i = date.GetMonth() + 1; i <= 12; i++)
			dates.push_back(Date(date.GetDay(), i));
		return dates;
	}

	int minimax(Date date, int depth, int alpha, int beta,  bool maximizingPlayer) {
		if (depth == 0 || (date.GetDay() == 31 && date.GetMonth() == 12))
			return positionEval.CalculateEval(date.GetDay(), date.GetMonth());
		
		std::list<Date> dates = GenerateDates(date);

		if (maximizingPlayer) {
			int maxEval = INT_MIN;
			for (auto child : dates) {
				int eval = minimax(child, depth - 1, alpha, beta, false);
				maxEval = max(maxEval, eval);
				alpha = max(alpha, eval);
				if (beta <= alpha)
					break;
			}
			return maxEval;
		}
		else {
			int minEval = INT_MAX;
			for (auto child : dates) {
				int eval = minimax(child, depth - 1, alpha, beta, true);
				minEval = min(minEval, eval);
				beta = min(beta, eval);
				if (beta <= alpha) 
					break;		
			}
			return minEval;
		}

	}

public:
	void MakeAMove(int currentDay, int currentMonth) {
		int month = currentMonth + 1; // тк currentMonth начинает отсчет с нуля;
		int a = minimax(Date(currentDay, month), 4, INT_MIN, INT_MAX, false);
		MessageBox(0, std::to_string(a).c_str(), 0, 0);
	}

};