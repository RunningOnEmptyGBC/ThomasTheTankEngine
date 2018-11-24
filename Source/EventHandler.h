#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 
class EventHandler
{
public:
	EventHandler();
	void HandleKeyEvent( LPARAM lParam);
	void HandleMouseEvent(int mouseButton);
	~EventHandler();


};