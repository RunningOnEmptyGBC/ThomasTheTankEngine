#include "InputHandler.h"


InputHandler::InputHandler() 
{

}

void InputHandler::GetInput(UINT uMsg,EventHandler eventHandler, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		//x++;
		//OutputDebugStringW(L"My output string. \n");
		eventHandler.HandleKeyEvent(lParam);

		break;
	case WM_LBUTTONDOWN:
		//x++;
		eventHandler.HandleMouseEvent(1);


		break;
	case WM_RBUTTONDOWN:
		//x++;
		eventHandler.HandleMouseEvent(2);


		break;
	case WM_MBUTTONDOWN:
		//x++;
		eventHandler.HandleMouseEvent(3);

		break;
	}
}

InputHandler::~InputHandler()
{

}