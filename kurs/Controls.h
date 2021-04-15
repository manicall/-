#pragma once
#include <Windows.h>
#include <windowsx.h>

class Controls {
protected:


	HWND hList, hDays, hMonths, hCurrentDate, hCurrentMove, hCountMove;
	bool IsListBoxEmpty() { return !ListBox_GetCount(hList); }
	void ListBoxClear(HWND hList) {
		for (int Count = ListBox_GetCount(hList); Count > 0; Count--)
			ListBox_DeleteString(hList, 0);
	}
	void ChangeRadioButton() {
		if (Button_GetCheck(hMonths)) {
			Button_SetCheck(hDays, true);
			Button_SetCheck(hMonths, false);
			Button_Enable(hMonths, false);
		}
		else {
			Button_SetCheck(hMonths, true);
			Button_SetCheck(hDays, false);
			Button_Enable(hDays, false);
		}
	}

public:

};