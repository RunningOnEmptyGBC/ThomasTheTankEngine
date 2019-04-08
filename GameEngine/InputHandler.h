#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>
#include "EventHandler.h"


class InputHandler
{
public:
	bool myButtons[256] = { false };
	InputHandler();
	void GetInput(UINT uMsg, EventHandler eventHandler, WPARAM wParam, LPARAM lParam);
	~InputHandler();
};