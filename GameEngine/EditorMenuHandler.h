#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include "MenuDefinitions.h"

class MenuHandler
{
public:
	MenuHandler();
	MenuHandler(const MenuHandler&);
	~MenuHandler();

	void InitMenus(HWND);
	void HandleMenus(HWND, UINT, WPARAM, LPARAM);
	void RegisterAboutWindow();

private:
	HMENU hMenu;
	HMENU hFileMenu;
	HMENU hEditMenu;
	HMENU hCreateNewMenu;

	HMENU hHelpMenu;

	
	LPCSTR m_aboutWndName;
	HINSTANCE m_hAboutWndInstance;
	HWND m_hAboutWnd;
};

static LRESULT CALLBACK AboutWndProc(HWND, UINT, WPARAM, LPARAM);