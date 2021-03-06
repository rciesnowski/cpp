// apka.cpp : definiuje punkt wejścia dla aplikacji
//

#include "stdafx.h"
#include "apka.h"

#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego

// Przekaż dalej deklaracje funkcji dołączonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieść kod.

    // Zainicjuj ciągi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_APKA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_APKA));

    MSG msg;

    // Główna pętla wiadomości:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klasę okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APKA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_APKA);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje dojście wystąpienia i tworzy okno główne
//
//   KOMENTARZE:
//
//        W tej funkcji dojście wystąpienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyświetlane okno główne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojście wystąpienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

VOID mojaTworczosc(HDC hdc) {
	HBRUSH hbrush;
	HPEN hpen;
	RECT rect = { 110, 10, 200, 80 };
	POINT pt[4] = { 800,400,400,300,600,400,600,40 };
	
	hpen = CreatePen(PS_SOLID, 2, RGB(140, 0, 0));
	hbrush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 200));
	
	SelectObject(hdc, hpen);
	Ellipse(hdc, 120, 210, 20, 110);
	SelectObject(hdc, hbrush);
	Ellipse(hdc, 120, 210, 20, 110);
	hpen = CreatePen(PS_SOLID, 4, RGB(50, 205, 50));
	SelectObject(hdc, hpen);
	MoveToEx(hdc, 70, 50, (LPPOINT)NULL);
	LineTo(hdc, 65, 120);
	hbrush = CreateHatchBrush(HS_DIAGCROSS, RGB(50, 205, 50));
	SelectObject(hdc, hbrush);
	Ellipse(hdc, 70, 50, 30, 70);

	int i, a;

	for (i = 1, a = 50; i <= 8; i++, a+=5) {
		hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		SelectObject(hdc, hpen);
		MoveToEx(hdc, 230, a, (LPPOINT)NULL);
		LineTo(hdc, 300, a);
	}
	for (i = 1, a = 50; i <= 4; i++, a += 5) {
		SelectObject(hdc, hpen);
		MoveToEx(hdc, 230, a, (LPPOINT)NULL);
		a += 5;
		LineTo(hdc, 230, a);
	}
	for (i = 1, a = 55; i <= 3; i++, a += 5) {
		SelectObject(hdc, hpen);
		MoveToEx(hdc, 300, a, (LPPOINT)NULL);
		a += 5;
		LineTo(hdc, 300, a);
	}

	SelectObject(hdc, hpen);
	MoveToEx(hdc, 300, 50, (LPPOINT)NULL);
	LineTo(hdc, 330, 55);
	LineTo(hdc, 420, 55);
	MoveToEx(hdc, 300, 85, (LPPOINT)NULL);
	LineTo(hdc, 335, 70);
	LineTo(hdc, 420, 70);
	MoveToEx(hdc, 420, 55, (LPPOINT)NULL);
	LineTo(hdc, 420, 70);

	MoveToEx(hdc, 230, 100, (LPPOINT)NULL);
	LineTo(hdc, 420, 100);
	MoveToEx(hdc, 230, 100, (LPPOINT)NULL);
	LineTo(hdc, 350, 130);
	LineTo(hdc, 350, 115);
	LineTo(hdc, 420, 115);
	LineTo(hdc, 420, 100);

	SetTextColor(hdc, RGB(20, 100, 100));
	TextOut(hdc, 100, 250, TEXT("jedzenie jabłka nożem i widelcem"), 35);

}
//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomości dla okna głównego.
//
//  WM_COMMAND — przetwarzaj menu aplikacji
//  WM_PAINT — pomaluj okno główne
//  WM_DESTROY — opublikuj komunikat o rezygnacji i wróć
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
            switch (wmId)
            {
            case ID_KLIKNIJTUTAJ_A:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, About);
                break;
			case ID_ALBOTU_O:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, About);
				break;
			case ID_GR2_RAFA32779:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, About);
				break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: tutaj dodaj kod rysowania używający elementu hdc...
			mojaTworczosc(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obsługi wiadomości dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
