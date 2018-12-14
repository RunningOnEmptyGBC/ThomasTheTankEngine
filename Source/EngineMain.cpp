// GT_HelloWorldWin32.cpp  
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c  

#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>
#include "InputHandler.h"
#include "EventHandler.h"
#include "EnigineInit.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#ifndef _USE_OLD_IOSTREAMS
using namespace std;
#endif

void KeyHandler();
void Test();
// Global variables  
EnigineInit engine = EnigineInit();
int x = 0;
const int Size = 200;
TCHAR greeting[Size] = _T("");
int y = 0;
// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Thomas the Tank Engine Main Window");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	AllocConsole();
	// Get STDOUT handle
	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	int SystemOutput = _open_osfhandle(intptr_t(ConsoleOutput), _O_TEXT);
	FILE *COutputHandle = _fdopen(SystemOutput, "w");
	
	freopen_s(&COutputHandle, "CONOUT$", "w", stdout);
	cout << "THis works" << endl;
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1500, 500,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}
	
	engine.eventHandler.AddListener(KeyDown, &KeyHandler);
	//engine.eventHandler.AddListener(KeyDown, &Test);
	//engine.eventHandler.AddListener(KeyDown, &Test);
	cout << &KeyHandler << endl;
	
	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
	}

	return (int)msg.wParam;
}



//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
//  
//  
int rec1 = 300;
int rec2 = 150;
int rec3 = 500;
int rec4 = 300;


int temp = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	LPSTR temp = new char[1];
	
	engine.inputHandler.GetInput(uMsg, engine.eventHandler, wParam, lParam);
	//engine.eventHandler.TriggerEvent(KeyDown);
	switch (uMsg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		//    Initializing original object
		HGDIOBJ original = NULL;

		//    Saving the original object
		original = SelectObject(hdc, GetStockObject(DC_PEN));

		//    Rectangle function is defined as...
		//    BOOL Rectangle(hdc, xLeft, yTop, yRight, yBottom);

		//    Drawing a rectangle with just a black pen
		//    The black pen object is selected and sent to the current device context
		//  The default brush is WHITE_BRUSH
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		Rectangle(hdc, 0, 0, 200, 200);

		//    Select DC_PEN so you can change the color of the pen with
		//    COLORREF SetDCPenColor(HDC hdc, COLORREF color)
		SelectObject(hdc, GetStockObject(DC_PEN));

		//    Select DC_BRUSH so you can change the brush color from the 
		//    default WHITE_BRUSH to any other color
		SelectObject(hdc, GetStockObject(DC_BRUSH));

		//    Set the DC Brush to Red
		//    The RGB macro is declared in "Windowsx.h"
		SetDCBrushColor(hdc, RGB(255, 0, 0));

		//    Set the Pen to Blue
		SetDCPenColor(hdc, RGB(0, 0, 255));

		//    Drawing a rectangle with the current Device Context    
		Rectangle(hdc, 100, 300, 200, 400);

		//    Changing the color of the brush to Green
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		Rectangle(hdc, rec1, rec2, rec3, rec4);

		//    Restoring the original object
		SelectObject(hdc, original);

		// It is not necessary to call DeleteObject to delete stock objects.
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		// for example:
		
		// EventHandler.AddListener(/*Key Down*/, WKeyHandler);
		// tell the event manager that I need to listen to the key down event, and when this event happens, please call the inputhandle function
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	
	
	
	

	//PAINTSTRUCT ps;
	//HDC hdc;
	//TCHAR greeting[] = _T("Hello, World!");

	//switch (message)
	//{
	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);

	//	// Here your application is laid out.  
	//	// For this introduction, we just print out "Hello, World!"  
	//	// in the top left corner.  
	//	TextOut(hdc,
	//		5, 5,
	//		greeting, _tcslen(greeting));
	//	// End application-specific layout section.  

	//	EndPaint(hWnd, &ps);
	//	break;
	//case WM_DESTROY:
	//	PostQuitMessage(0);
	//	break;
	//default:
	//	return DefWindowProc(hWnd, message, wParam, lParam);
	//	break;
	//}

	//return 0;
}
void KeyHandler() {
	if (engine.inputHandler.myButtons[87] == true) {
		//Do what we want when W is pressed
		OutputDebugStringW(L"W key was pressed. \n"); //Move Up
		//rec1++;
		rec2--;
		//rec3++;
		rec4--;
	}else	if (engine.inputHandler.myButtons[83] == true) { //Move Down
		OutputDebugStringW(L"S key was pressed. \n");
		//rec1--;
		rec2++;
		//rec3--;
		rec4++;
	}if (engine.inputHandler.myButtons[65] == true) { //Move Left
		OutputDebugStringW(L"A key was pressed. \n");
		rec1--;
		//rec2++;
		rec3--;
		//rec4++;
	}
	else	if (engine.inputHandler.myButtons[68] == true) { //Move Right
		OutputDebugStringW(L"A key was pressed. \n");
		rec1++;
		//rec2++;
		rec3++;
		//rec4++;
	}
	else {
		OutputDebugStringW(L"Some other key was pressed. \n");
	}

}

class IKeyboardHandler {
	virtual bool VOnKeyDown(unsigned int const kcode) = 0;
	virtual bool VOnKeyUp(unsigned int const kcode) = 0;
};

void Test() {
	OutputDebugStringW(L"This is the Test function. \n");
	
}

void WTestEvent() {

}




/*
int WINAPI WinMain()
{
	const char szUniqueNamedMutex[] = "com_mycompany_apps_appname";
	HANDLE hHandle = CreateMutex(NULL, TRUE, szUniqueNamedMutex);
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Program already running somewhere
		return(1); // Exit program
	}

	// Program runs...

	// Upon app closing:
	ReleaseMutex(hHandle); // Explicitly release mutex
	CloseHandle(hHandle); // close handle before terminating
	return(1);
}
*/
/*
bool CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters;
	neededClusters = diskSpaceNeeded /(diskfree.sectors_per_cluster *diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don’t have enough disk space!
		GCC_ERROR("CheckStorage Failure: Not enough physical storage.");
		return false;
	}
	return true;
}
*/


