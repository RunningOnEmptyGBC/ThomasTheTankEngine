#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 
#include "InputHandler.h"
#include "EventHandler.h"
class EnigineInit
{
public:
	EnigineInit();
	~EnigineInit();
	//bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	InputHandler inputHandler;
	EventHandler eventHandler;
	//CompatCheck  compatCheck;
};

