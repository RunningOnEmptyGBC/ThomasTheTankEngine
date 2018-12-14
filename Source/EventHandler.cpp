#include "EventHandler.h"
#include <iostream>



EventHandler::EventHandler()
{
	
}

void EventHandler::AddListener(eventType name,fastdelegate::FastDelegate0<> function) {
	// add call back function to list of listeners of (event name) list
	fastdelegate::FastDelegate0<> noparameterdelegate(function);
	ourMap[name].push_back(noparameterdelegate);
	
	//noparameterdelegate();  //THIS LINE SUCESSFULLY RUNS THE FUNCTION
	ourMap[name];
	
	
	
}


void EventHandler::TriggerEvent(eventType name) {
	// go through list of listers of (event name) and call the call back functions
	//for (vector <fastdelegate::FastDelegate0<>>::iterator  b = ourMap[name].begin(); b != ourMap[name].end(); b++)
	//{
	//	OutputDebugStringW(L"This is the event handler triggering events. \n");
	//	//ourMap[name].b();
	//	
	//	//ourMap[name](&b);
	//	cout << &b << endl;
	//	//ourMap[name].size();
	//	
	//	
	//}
	for (int i = 0; i < ourMap[name].size();i++) {
		ourMap[name][i]();
	}
	//for (auto const& x : ourMap)
	//{
	//	x.second;
	//	(this->*(x.second))();

	//	//Or
	//	((*this)->*(x.second))();
	//	OutputDebugStringW(L"This is the event handler triggering events \n");
	//	//(this->*x->second)();
	//	
	//}
	
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

void EventHandler::TestHandlerEvent() {

}