#include "InputHandler.h"


InputHandler::InputHandler() 
{

}

//LPSTR temp = new char[1];
//int Newx = 0;
void InputHandler::GetInput(UINT uMsg,EventHandler eventHandler, WPARAM wParam, LPARAM lParam)
{
	//int x = LOWORD(lParam);
	int x = LOBYTE(wParam);
	switch (uMsg)
	{
	case WM_KEYDOWN:
		//x++;
		//int x = LOWORD(lParam);
		//GetKeyNameTextA(lParam, temp, 10);
		//Newx = LOWORD(temp);
		myButtons[x] = true;
		OutputDebugStringW(L"My output string. \n");
		//eventHandler.TriggerEvent("Key Pressed");
		//eventHandler.HandleKeyEvent(lParam);
		break;

	case WM_KEYUP:
		//x++;
		//int x = LOWORD(lParam);
		//GetKeyNameTextA(lParam, temp, 10);
		//Newx = LOWORD(temp);
		myButtons[x] = false;
		OutputDebugStringW(L"My output string FALSE. \n");
		//eventHandler.TriggerEvent("Key Pressed");
		//eventHandler.HandleKeyEvent(lParam);
		break;
	case WM_LBUTTONDOWN:
		//x++;
		//eventHandler.HandleMouseEvent(1);
		//eventHandler.TriggerEvent(/*Mouse event 1*/);


		break;
	case WM_RBUTTONDOWN:
		//x++;
		//eventHandler.HandleMouseEvent(2);


		break;
	case WM_MBUTTONDOWN:
		//x++;
		//eventHandler.HandleMouseEvent(3);

		break;
	}
}

InputHandler::~InputHandler()
{

}