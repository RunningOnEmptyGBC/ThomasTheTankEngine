#include "EventHandler.h"
#include <iostream>
#include "../Source/EnigineInit.h"

EventHandler::EventHandler()
{
	//cout << "Event Handler Initialized" << endl;
	OutputDebugStringW(L"Event Handler Initialized\n");
}

void EventHandler::AddListener(eventType name,fastdelegate::FastDelegate0<> function) {
	// add call back function to list of listeners of (event name) list
	fastdelegate::FastDelegate0<> noparameterdelegate(function);
	ourMap[name].push_back(noparameterdelegate);
	
	//noparameterdelegate();  //THIS LINE SUCESSFULLY RUNS THE FUNCTION
}

/* THIS IS AN ATTEMPT AT AN OVERLOAD TO THE ADDLISTENER FUNCTION THAT ACCEPTS 
	FUNCITONS WITH PARAMATERS. IT DOES NOT WORK AT THE MOMENT
void EventHandler::AddListener(eventType name, fastdelegate::FastDelegate1<EnigineInit*> function) {
	// add call back function to list of listeners of (event name) list
	fastdelegate::FastDelegate1<EnigineInit*> noparameterdelegate(function);
	ourMap[name].push_back(noparameterdelegate);

	//noparameterdelegate();  //THIS LINE SUCESSFULLY RUNS THE FUNCTION
}*/

void EventHandler::TriggerEvent(eventType name) {
	// go through list of listers of (event name) and call the call back functions
	
	for (int i = 0; i < ourMap[name].size();i++) {
		ourMap[name][i]();
	}
}

EventHandler::~EventHandler()
{
	
}

void EventHandler::TestHandlerEvent() {

}