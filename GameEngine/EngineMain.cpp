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

	
	// Get STDOUT handle
	AllocConsole();
	HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	int SystemOutput = _open_osfhandle(intptr_t(ConsoleOutput), _O_TEXT);
	FILE *COutputHandle = _fdopen(SystemOutput, "w");

	freopen_s(&COutputHandle, "CONOUT$", "w", stdout);
	cout << "This works." << endl;

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