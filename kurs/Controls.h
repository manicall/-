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
};