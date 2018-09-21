#pragma once
#include <windows.h>
#include <shlwapi.h>
#include <iostream>
#include "string.h"

using namespace std;

class CompatCheck 
{
public:
	CompatCheck();
	~CompatCheck();

	bool MultipleInstanceCheck(const char* gameTitle);
	double MemoryCheck();
	double VirtualMemoryCheck();
	bool AvailableStorageCheck(int requiredSize);

	DWORD ReadCPUSpeed();
	//void ReadProcessorIdentifier(string *IdentifierValue);
	DWORD ReadProcessorArchitecture();
};
