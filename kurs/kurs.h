#pragma once

#include "Lists.h"

INT_PTR CALLBACK    GameWindowProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void get_information(std::string fileName, std::string caption) {
    std::ifstream fin(fileName);
    std::string text = "";
    std::string str;
    if (!fin) MessageBoxA(0, "Не удалось открыть файл!", "Ошибка открытия файла", 0 | MB_ICONERROR);
    while (std::getline(fin, str))
    {
        text += str + "\n";
    }
    fin.close();
    MessageBoxA(0, text.c_str(), caption.c_str(), 0);

}

void get_about() {
    get_information("about.txt", "О программе");
}
void get_help() {
    get_information("help.txt", "Помощь");
}
void get_rules() {
    get_information("rules.txt", "Правила");
}

HWND hList, hDays, hMonths;
ListOfDates LOD;

void accept() {
    bool checkDays = Button_GetCheck(hDays);
    bool checkMonths = Button_GetCheck(hMonths);
    if (checkDays) LOD.ChangeDaysState(hList);
    else if (checkMonths) LOD.ChangeMonthsState(hList);
    else {
        MessageBoxA(0, "Невозможно подтвердить выбор,\nтак как необходимо выбрать дни или месяцы", 0, 0 | MB_ICONERROR);
        return;
    }
    LOD.ListBoxClear(hList);
}

INT_PTR CALLBACK GameWindowProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        hList = GetDlgItem(hDlg, IDC_LIST1);
        hDays = GetDlgItem(hDlg, IDC_DAYS);
        hMonths = GetDlgItem(hDlg, IDC_MONTHS);
        return (INT_PTR)TRUE;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam); 
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDOK: {
            accept();
            break;
        }
        case IDCANCEL:
            DestroyWindow(hDlg);
            break;
        case IDC_DAYS:
            LOD.DaysInListBox(hList);
            break;
        case IDC_MONTHS:
            LOD.MonthInListBox(hList);
            break;
        case IDM_NEWGAME:
            MessageBoxA(0, "IDM_NEWGAME", 0, 0);
            break;
        case IDM_EXIT:
            DestroyWindow(hDlg);
            break;
        case IDM_ABOUT:
            get_about();
            break;
        case IDM_HELP:
            get_help();
            break;
        case IDM_RULES:
            get_rules();
            break;
        }
    }
    }
    return (INT_PTR)FALSE;
}