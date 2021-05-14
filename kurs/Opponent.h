#pragma once
#include "DatesForGame.h"
#include "Windows.h"
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
	bool operator==(Date date) {
		return day == date.day && month == date.month;
	}
};

class  Opponent : protected DatesForGame {

	std::vector<Date> LoseDates;
	const int MAXDAY = 31, MAXMONTH = 11;
	int random(int min, int max);
	Date RandomDate(int currentDay, int currentMonth);
	Date LoseDate(int currentDay, int currentMonth);
	Date TryWin(int currentDay, int currentMonth);
	bool RecFindLoseDate(std::vector<Date>::iterator ItLoseDates, Date date) {
		if (ItLoseDates == LoseDates.end())
			return false;
		else if (*ItLoseDates == date)
			return true;
		return RecFindLoseDate(++ItLoseDates, date);
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
	Date newDate = TryWin(currentDay, currentMonth);
	if (newDate == Date(currentDay, currentMonth))
	{
		if (RecFindLoseDate(LoseDates.begin(), Date(currentDay, currentMonth)))
			newDate = RandomDate(currentDay, currentMonth);
		else
			newDate = LoseDate(currentDay, currentMonth);
	}
	currentDay = newDate.GetDay();
	currentMonth = newDate.GetMonth();


} 

