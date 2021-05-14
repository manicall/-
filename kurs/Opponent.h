#pragma once
#include "DatesForGame.h"
#include "Windows.h"
#include <vector>
#include <deque>
#include <random> 
#include <ctime>

class Date {
	int day;
	int month;
public:
	Date(int _day, int _month) : day(_day), month(_month) {}
	int GetDay() { return day; }
	int GetMonth() { return month; }
	bool operator==(Date date) {
		return day == date.day && month == date.month;
	}
	bool operator!=(Date date) {
		return !(Date(day, month) == date);
	}
};

class  Opponent : protected DatesForGame {
	std::deque<Date> Strategy;
	std::vector<Date> LoseDates;
	const int MAXDAY = 31, MAXMONTH = 11;
	int random(int min, int max);
	Date RandomDate(int currentDay, int currentMonth);
	Date LoseDate(int currentDay, int currentMonth);
	Date TryWin(int currentDay, int currentMonth);
	bool RecFindLoseDate(std::vector<Date>::iterator ItLoseDates, Date date);
	int getEval(Date Date);
	void FindMoves(Date date, int depth, std::deque<Date>& Dates, bool flag);
	void SetNewDate(int& currentDay, int& currentMonth) {
		Date newDate = Strategy.front();
		currentDay = newDate.GetDay();
		currentMonth = newDate.GetMonth();
		Strategy.pop_front();
	}
public:
	Opponent();
	void MakeAMove(int& currentDay, int& currentMonth);
};

int Opponent::random(int min, int max)
{
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(min, max);
	return uid(gen);
}

Date Opponent::RandomDate(int currentDay, int currentMonth) {
	if (currentMonth < MAXMONTH - 1 && currentDay < MAXDAY - 1) {
		if (!random(0, 1))
			currentDay += random(1, currentDay < MAXDAY - 3 ? 3 : 1);
		else
			currentMonth += random(1, currentMonth < MAXMONTH - 3 ? 3 : 1);
	}
	else {
		if (currentDay == MAXDAY - 1)
			currentMonth = MAXMONTH;
		else
			currentDay = MAXDAY;
	}
	return Date(currentDay, currentMonth);
}

Date Opponent::LoseDate(int currentDay, int currentMonth) {
	if (currentDay >= 20) {
		if (currentMonth < LoseDates[currentDay - 20].GetMonth())
			currentMonth = LoseDates[currentDay - 20].GetMonth();
		else if (currentDay < LoseDates[currentMonth].GetDay())
			currentDay = LoseDates[currentMonth].GetDay();
	}
	else
		currentDay = LoseDates[currentMonth].GetDay();
	return Date(currentDay, currentMonth);
}

Date Opponent::TryWin(int currentDay, int currentMonth) {
	if (currentDay == MAXDAY || currentMonth == MAXMONTH)
		return Date(MAXDAY, MAXMONTH);
	else
		return Date(currentDay, currentMonth);
}

Opponent::Opponent() {
	for (int i = 20, j = 0; i < MAXDAY; i++, j++)
		LoseDates.push_back(Date(i, j));
}

void Opponent::MakeAMove(int& currentDay, int& currentMonth) {
	if(Strategy.empty()) {
		if (!RecFindLoseDate(LoseDates.begin(), Date(currentDay, currentMonth)))
			FindMoves(Date(currentDay, currentMonth), 3, Strategy, true);  // компьютер будет максимизатором
		else
			FindMoves(Date(currentDay, currentMonth), 3, Strategy, false); // компьютер будет минимизатором	
	}
	if (Strategy.size() % 2 != 0) {
		SetNewDate(currentDay, currentMonth);
	}
	else {
		if (Strategy.front() != Date(currentDay, currentMonth)) {
			while (!Strategy.empty()) 
				Strategy.pop_front();
			MakeAMove(currentDay, currentMonth);
		}
		else {
			Strategy.pop_front();
			SetNewDate(currentDay, currentMonth);
		}
	}
} 

bool Opponent::RecFindLoseDate(std::vector<Date>::iterator ItLoseDates, Date date) {
	if (ItLoseDates == LoseDates.end())
		return false;
	else if (*ItLoseDates == date)
		return true;
	return RecFindLoseDate(++ItLoseDates, date);
}

int Opponent::getEval(Date Date) {
	if (RecFindLoseDate(LoseDates.begin(), Date))
		return 10;
	else
		return -10;
}

void Opponent::FindMoves(Date date, int depth, std::deque<Date>& Dates, bool maxPlayer) {
	if (depth == 0) {
		return;
	}
	else if (date.GetDay() == MAXDAY) {
		Dates.push_back(Date(date.GetDay(), MAXMONTH));
		return;
	}
	else if (date.GetMonth() == MAXMONTH) {
		Dates.push_back(Date(MAXDAY, date.GetMonth()));
		return;
	}
	if (maxPlayer) {
		for (int d = date.GetDay() + 1; d <= days[months[date.GetMonth()]]; d++) {
			int m = date.GetMonth();
			if (getEval(Date(d, m)) == 10) {
				Dates.push_back(Date(d, m));
				FindMoves(Date(d, m), depth - 1, Dates, false);
				return;
			}
		}
		for (int m = date.GetMonth() + 1; m <= MAXMONTH; m++) {
			int d = date.GetDay();
			if (getEval(Date(d, m)) == 10) {
				Dates.push_back(Date(d, m));
				FindMoves(Date(d, m), depth - 1, Dates, false);
				return;
			}
		}
	}
	if (!maxPlayer) {
		Date Rdate = RandomDate(date.GetDay(), date.GetMonth());
		Dates.push_back(Rdate);
		FindMoves(Rdate, depth - 1, Dates, true);
	}
}