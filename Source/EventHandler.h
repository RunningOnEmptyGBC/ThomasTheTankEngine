#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 
#include <map>
#include <vector>
#include  "FastDelegate.h"
//#include "lib/FastDelegates/FastDelegateb.h"
using namespace std;

enum eventType {
	KeyDown,
	MouseButton,
	MouseMovement,
	KeyUp,
	OnOverlap
};

class EventHandler
{
public:
	
	EventHandler();
	void TriggerEvent(eventType name);
	void AddListener(eventType name, fastdelegate::FastDelegate0<> function);
	void HandleKeyEvent( LPARAM lParam);
	void HandleMouseEvent(int mouseButton);
	~EventHandler();


};