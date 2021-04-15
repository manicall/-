#pragma once

#include "GameControl.h"
#include "framework.h"
#include "Resource.h"
#include <fstream>

INT_PTR CALLBACK    GameWindowProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void GetInformation(std::string fileName, std::string caption) {
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

void GetAbout() {
    GetInformation("about.txt", "О программе");
}
void GetHelp() {
    GetInformation("help.txt", "Помощь");
}
void GetRules() {
    GetInformation("rules.txt", "Правила");
}



INT_PTR CALLBACK GameWindowProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static GameControl gameControl;

    switch (message)
    {
    case WM_INITDIALOG:
        static HWND hList, hDays, hMonths, hCurrentDate, hCurrentMove, hCountMove;
        hList =        GetDlgItem(hDlg, IDC_LIST);
        hDays =        GetDlgItem(hDlg, IDC_DAYS);
        hMonths =      GetDlgItem(hDlg, IDC_MONTHS);
        hCurrentDate = GetDlgItem(hDlg, IDC_CURRENTDATE);
        hCurrentMove = GetDlgItem(hDlg, IDC_CURRENTMOVE);
        hCountMove = GetDlgItem(hDlg, IDC_COUNTMOVE);

        gameControl.SetControls(hList, hDays, hMonths, hCurrentDate, hCurrentMove, hCountMove);
        gameControl.ListBoxUpdate();
        return (INT_PTR)TRUE;
    case WM_COMMAND:
    {

        int wmId = LOWORD(wParam); 
        // Разобрать выбор в меню:
        switch (wmId)
        {

        case IDOK:        gameControl.Move(); break;
        case IDCANCEL:    DestroyWindow(hDlg);  break;
        case IDC_DAYS:    gameControl.ListBoxUpdate();  break;
        case IDC_MONTHS:  gameControl.ListBoxUpdate();  break;
        case IDM_NEWGAME: gameControl.StartNewGame();  break;
        case IDM_EXIT:    DestroyWindow(hDlg);  break;
        case IDM_ABOUT:   GetAbout();  break;
        case IDM_HELP:    GetHelp();  break;
        case IDM_RULES:   GetRules(); break;

        }
    }
    }
    return (INT_PTR)FALSE;
}