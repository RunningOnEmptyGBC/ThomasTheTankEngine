#include "EventHandler.h"
//EventType is Enum, funcitonDelegate is from a lib
map < eventType, vector <fastdelegate::FastDelegate0<>>> ourMap;

EventHandler::EventHandler()
{

}

void EventHandler::AddListener(eventType name,fastdelegate::FastDelegate0<> function) {
	// add call back function to list of listeners of (event name) list
	ourMap[name].push_back(function);
	
}

void EventHandler::TriggerEvent(eventType name) {
	// go through list of listers of (event name) and call the call back functions
	for (vector <fastdelegate::FastDelegate0<>>::const_iterator b = ourMap[name].begin(); b != ourMap[name].end(); ++b)
	{
		OutputDebugStringW(L"My output string. \n");
		b;
	}
}
//
//void EventHandler::HandleKeyEvent(LPARAM lParam)
//{ 
//	LPSTR temp = new char[1];
//	GetKeyNameTextA(lParam, temp, 10);
//	
//	OutputDebugString(temp);
//	OutputDebugString("\n");
//}

//void EventHandler::HandleMouseEvent(int mouseButton)
//{
//	switch (mouseButton)
//	{
//	case 1:
//		//x++;
//		OutputDebugString("Left Mouse Button \n");
//		break;
//	case 2:
//		//x++;
//		OutputDebugString("Right Mouse Button \n");
//		break;s
//	case 3:
//		//x++;
//		OutputDebugString("Middle Mouse Button \n");
//		break;
//	}
//}

EventHandler::~EventHandler()
{
	
}