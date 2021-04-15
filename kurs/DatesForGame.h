#pragma once
#include <map>
#include <string>
#include <vector>

class DatesForGame {
protected:
	std::map<std::string, int> days;
	std::vector<std::string> months;
public:
	DatesForGame() {
		months = {
			"€нвар€",	"феврал€",	"марта",
			"апрел€",	"ма€",		"июн€",
			"июл€",		"августа",	"сент€бр€",
			"окт€бр€",	"но€бр€",	"декабр€"
		};
		for (int i = 0; i < 12; i++) // формирование дней дл€ каждого мес€ца
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
				days[months[i]] = 31;
			else if (i == 3 || i == 5 || i == 8 || i == 10)
				days[months[i]] = 30;
			else
				days[months[i]] = 28;
		}
	}
	std::map<std::string, int> GetDays() { return days; }
	std::vector<std::string> GetMonths() { return months; }
};