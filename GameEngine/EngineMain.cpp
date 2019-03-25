#include "EngineSystem.h"


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	EngineSystem* System;
	bool result;

	System = new EngineSystem;
	if (!System)
	{
		return 0;
	}

	result = System->Init();
	if (result)
	{
		System->Run();
	}

	System->Shutdown();
	delete System;
	System = 0;

	return 0;
}