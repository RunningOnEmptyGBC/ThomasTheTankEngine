#include "EditorMenuHandler.h"

MenuHandler::MenuHandler()
{
}

MenuHandler::MenuHandler(const MenuHandler &)
{
}

MenuHandler::~MenuHandler()
{
}

void MenuHandler::InitMenus(HWND hwnd)
{
	hMenu = CreateMenu();
	hFileMenu = CreateMenu();
	hEditMenu = CreateMenu();
	hCreateNewMenu = CreateMenu();
	hHelpMenu = CreateMenu();


	///File Menu
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hFileMenu, MF_STRING, FILEMENU_NEW, "New");
	AppendMenu(hFileMenu, MF_STRING, FILEMENU_OPEN, "Open");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILEMENU_SAVE, "Save");
	AppendMenu(hFileMenu, MF_STRING, FILEMENU_SAVEAS, "Save As");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILEMENU_EXIT, "Exit");


	///Edit Menu
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hEditMenu, "Edit");

	AppendMenu(hEditMenu, MF_POPUP, (UINT_PTR)hCreateNewMenu, "Create New");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_PLANE, "Plane");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_CUBE, "Cube");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_PYRAMID, "Pyramid");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_SPHERE, "Sphere");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_HEXAGON, "Hexagon");
	AppendMenu(hCreateNewMenu, MF_STRING, EDITMENU_CREATENEW_CYLINDER, "Cylinder");

	AppendMenu(hEditMenu, MF_SEPARATOR, NULL, NULL);

	AppendMenu(hEditMenu, MF_STRING, EDITMENU_UNDO, "Undo");
	AppendMenu(hEditMenu, MF_STRING, EDITMENU_REDO, "Redo");
	AppendMenu(hEditMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hEditMenu, MF_STRING, EDITMENU_CUT, "Cut");
	AppendMenu(hEditMenu, MF_STRING, EDITMENU_COPY, "Copy");
	AppendMenu(hEditMenu, MF_STRING, EDITMENU_PASTE, "Paste");
	AppendMenu(hEditMenu, MF_STRING, EDITMENU_DELETE, "Delete");


	///Help Menu
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");
	AppendMenu(hHelpMenu, MF_STRING, HELPMENU_ABOUT, "About");


	SetMenu(hwnd, hMenu);
}

void MenuHandler::HandleMenus(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (wparam)
	{
	case FILEMENU_NEW:
	{
		MessageBeep(MB_OK);
		break;
	}
	case FILEMENU_OPEN:
	{
		MessageBeep(MB_ICONERROR);
		break;
	}
	case FILEMENU_SAVE:
	{
		MessageBox(hwnd,
			_T("Hello World"),
			_T("Test"),
			MB_YESNOCANCEL | MB_ICONEXCLAMATION);
	}
	case HELPMENU_ABOUT:
		break;
	}
}

void MenuHandler::RegisterAboutWindow()
{
	WNDCLASSEX about;

	m_hAboutWndInstance = GetModuleHandle(NULL);
	m_aboutWndName = "About";

	ZeroMemory(&about, sizeof(WNDCLASSEX));
	about.cbClsExtra = 0;
	about.cbWndExtra = 0;
	about.cbSize = sizeof(about);
	about.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	about.lpfnWndProc = AboutWndProc;
	about.hInstance = m_hAboutWndInstance;
	about.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	about.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	about.hCursor = LoadCursor(NULL, IDC_ARROW);
	about.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	about.lpszMenuName = nullptr;
	about.lpszClassName = m_aboutWndName;

}


LRESULT CALLBACK AboutWndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	return 0;
}