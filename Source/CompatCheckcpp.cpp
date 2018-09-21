#include "CompatCheck.h"
#define DIV 1024
#define BUFFER 8192

CompatCheck::CompatCheck()
{

}
CompatCheck::~CompatCheck()
{

}
bool CompatCheck::MultipleInstanceCheck(const char* gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		//HWND hWnd = FindWindow(gameTitle, NULL);
		//if (hWnd) {
			// An instance of your game is already running.
			//ShowWindow(hWnd, SW_SHOWNORMAL);
			//SetFocus(hWnd);
			//SetForegroundWindow(hWnd);
			//SetActiveWindow(hWnd);
			return true;
		//}
	}
	return false;
	
}

double CompatCheck::MemoryCheck()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	double displayRAM = (statex.ullAvailPhys / DIV) / DIV;
	return displayRAM;
}

double CompatCheck::VirtualMemoryCheck()
{
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	double displayVir = (statex.ullAvailVirtual / DIV) / DIV;
	return displayVir;
}

bool CompatCheck::AvailableStorageCheck(int requiredSize)
{
	ULARGE_INTEGER Freebytes;
	unsigned long long displayStorage = 0;
	GetDiskFreeSpaceEx(TEXT("C:\\"), &Freebytes, 0, 0);
	displayStorage = (Freebytes.QuadPart / DIV) / DIV;
	if (displayStorage > requiredSize) {
		return true;
	}
	
	return false;
}

DWORD  CompatCheck::ReadCPUSpeed() {
	DWORD BufferSize = sizeof(DWORD);
	DWORD SpeedValue = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&SpeedValue, &BufferSize);
	}
	return SpeedValue;
}
//void  CompatCheck::ReadProcessorIdentifier(string *IdentifierValue) {
//	DWORD BufferSize = BUFFER;
//	char IdentifierValue[255] = "Hello";
//
//	RegGetValue(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "Identifier", RRF_RT_ANY, NULL, (PVOID)&IdentifierValue, &BufferSize);
//	
//}

DWORD  CompatCheck::ReadProcessorArchitecture() {
	DWORD BufferSize = sizeof(DWORD);
	DWORD ArchitectureValue = 0;
	DWORD type = REG_SZ;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS) {
		RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)&ArchitectureValue, &BufferSize);
	}
	cout << ArchitectureValue << endl;
	return ArchitectureValue;
}