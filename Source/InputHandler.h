#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>
#include "EventHandler.h"

class InputHandler
{
public:
	InputHandler();
	void GetInput(UINT uMsg, EventHandler eventHandler, LPARAM lParam);
	~InputHandler();
};