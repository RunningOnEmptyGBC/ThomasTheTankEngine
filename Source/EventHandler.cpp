#include "EventHandler.h"


EventHandler::EventHandler()
{

}

void EventHandler::HandleKeyEvent(LPARAM lParam)
{ 
	LPSTR temp = new char[1];
	GetKeyNameTextA(lParam, temp, 10);
	OutputDebugString(temp);
	OutputDebugString("\n");
}

void EventHandler::HandleMouseEvent(int mouseButton)
{
	switch (mouseButton)
	{
	case 1:
		//x++;
		OutputDebugString("Left Mouse Button \n");
		break;
	case 2:
		//x++;
		OutputDebugString("Right Mouse Button \n");
		break;
	case 3:
		//x++;
		OutputDebugString("Middle Mouse Button \n");
		break;
	}
}

EventHandler::~EventHandler()
{
	
}