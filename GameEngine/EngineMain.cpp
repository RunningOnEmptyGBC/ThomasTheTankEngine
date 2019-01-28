#include "DXapp.h"
#include "../Source/EnigineInit.h"
#include "../Source/EventHandler.h"
#include "../Source/InputHandler.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
EnigineInit engine = EnigineInit();
class TestApp : public DXapp
{
public:
	TestApp(HINSTANCE hInstance);
	~TestApp();

	bool Init() override;
	void Update(float dt) override;
	void Render(float dt) override;
	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//Things Matthews added 
	void KeyHandler();
	

	//End Things Matthews added
};

TestApp::TestApp(HINSTANCE hInstance) : DXapp(hInstance)
{
	AllocConsole();
	// Get STDOUT handle
	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	int SystemOutput = _open_osfhandle(intptr_t(ConsoleOutput), _O_TEXT);
	FILE *COutputHandle = _fdopen(SystemOutput, "w");

	freopen_s(&COutputHandle, "CONOUT$", "w", stdout);
	cout << "This works" << endl;

	//engine.eventHandler.AddListener(KeyDown, &KeyHandler);
}
TestApp::~TestApp()
{

}

bool TestApp::Init()
{
	if (!DXapp::Init()) {
		return false;
	}

	return true;
}

void TestApp::Update(float dt)
{

}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::Red);

	HR(m_pSwapChain->Present(0, 0));
}

LRESULT TestApp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	engine.inputHandler.GetInput(msg, engine.eventHandler, wParam, lParam);
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

void KeyHandler() {
	//Checks the InputHandlers MyButtons Array and runs code for each button press
	if (engine.inputHandler.myButtons[87] == true) {
		//Do what we want when W is pressed
		OutputDebugStringW(L"W key was pressed. \n"); //Move Up
	}
	else	if (engine.inputHandler.myButtons[83] == true) { //Move Down
		//Do what we want when S is pressed
		OutputDebugStringW(L"S key was pressed. \n");
		
	}if (engine.inputHandler.myButtons[65] == true) { //Move Left
		//Do what we want when A is pressed
		OutputDebugStringW(L"A key was pressed. \n");
	}
	else	if (engine.inputHandler.myButtons[68] == true) { //Move Right
		//Do what we want when D is pressed
		OutputDebugStringW(L"D key was pressed. \n");
	}
	if (engine.inputHandler.myButtons[49] == true) {
		OutputDebugStringW(L"1 key was pressed. \n");
	}
	else if (engine.inputHandler.myButtons[50] == true) { 
		OutputDebugStringW(L"2 key was pressed. \n");
		
	}
	else if (engine.inputHandler.myButtons[51] == true) { 
		OutputDebugStringW(L"3 key was pressed. \n");
		
	}
	else if (engine.inputHandler.myButtons[52] == true) {
		OutputDebugStringW(L"4 key was pressed. \n");
		
	}
	else if (engine.inputHandler.myButtons[53] == true) {
		OutputDebugStringW(L"5 key was pressed. \n");
		
	}


}


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	
	TestApp tApp(hInstance);
	engine.eventHandler.AddListener(KeyDown, &KeyHandler);
	if (!tApp.Init()) {
		return 1;
	}

	return tApp.Run();
}
