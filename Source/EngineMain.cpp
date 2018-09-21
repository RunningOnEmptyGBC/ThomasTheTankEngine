#include "stdio.h"
#include <iostream>
#include <windows.h>
#include <shlwapi.h>
#include "string.h"
#include <string>
#include "CompatCheck.h"
using namespace std;
#define DIV 1024
#define BUFFER 8192

const char* gameTitle = "Working Title";
int NeededMemory = 300;

string temp() {
	DWORD BufferSize = BUFFER;
	string IdentifierValue;

	RegGetValue(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "Identifier", RRF_RT_ANY, NULL, (PVOID)&IdentifierValue, &BufferSize);
	//cout << IdentifierValue << endl;

	return IdentifierValue;
};
int main() {

	//HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	//if (GetLastError() != ERROR_SUCCESS) {
	//	HWND hWnd = FindWindow(gameTitle, NULL);
	//	cout << "An instance of your game is already running." << endl;
	//	if (hWnd) {
	//		// An instance of your game is already running.
	//		ShowWindow(hWnd, SW_SHOWNORMAL);
	//		SetFocus(hWnd);
	//		SetForegroundWindow(hWnd);
	//		SetActiveWindow(hWnd);
	//		return false;
	//	}
	//}
	//else {
	//	cout << "There is no other instance of you game running." << endl;
	//}

	////Displays AVailable RAM
	//MEMORYSTATUSEX statex;
	//statex.dwLength = sizeof(statex);
	//GlobalMemoryStatusEx(&statex);
	//double displayRAM = (statex.ullAvailPhys /DIV)/DIV;
	//cout << "RAM: " << displayRAM << " Megabytes" << endl;

	////Display Available Virual Mem
	//double displayVir = (statex.ullAvailVirtual / DIV) / DIV;
	//cout <<"Virtual Memory: "<< displayVir << " Megabytes" << endl;
	////

	//Display available Storage Space
	//ULARGE_INTEGER Freebytes;
	//unsigned long long displayStorage = 0;
	//GetDiskFreeSpaceEx(TEXT("C:\\"), &Freebytes, 0, 0);
	//displayStorage = (Freebytes.QuadPart/DIV)/DIV;
	//cout <<"Available Storage: " <<displayStorage << "Megabytes" <<  endl;
	//if (displayStorage > 300) {
	//	cout << "There is enough space" << endl;
	//}
	//else {
	//	cout << "This is not enough space" << endl;
	//}
	//
	CompatCheck test = CompatCheck();
	bool CheckBool = test.MultipleInstanceCheck(gameTitle);
	cout << "Multiple instances running: "<< CheckBool << endl;
	if (CheckBool) 
	{
		cout << "Muliple instances are running, please exit this application." << endl;
		int q;
		cin >> q;
		return 0;
	}

	double CheckDouble = test.MemoryCheck();
	cout << "Available memory: " << CheckDouble << "mb" << endl;

	CheckDouble = test.VirtualMemoryCheck();
	cout << "Available virtual memory: " << CheckDouble << "mb" << endl;

	CheckBool = test.AvailableStorageCheck(NeededMemory);
	if (CheckBool) {
		cout << "There is more than " << NeededMemory << "mb available." << endl;
	}
	else {
		cout << "There is not more than " << NeededMemory << "mb available." << endl;
	}

	DWORD DWORDCheck = test.ReadCPUSpeed();
	cout << "The CPU speed is: " << DWORDCheck << "Hz" << endl;

	//*********************************************************
	DWORD BufferSize = BUFFER;
	char IdentifierValue[255] = "Hello";
	RegGetValue(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", "Identifier", RRF_RT_ANY, NULL, (PVOID)&IdentifierValue, &BufferSize);
	cout << IdentifierValue << endl;
	//************************************************************


	DWORD DWORDCheck2 = test.ReadProcessorArchitecture();
	cout << DWORDCheck2 << endl;

	
	int q;
	cin >> q;
	return 0;
};


/*
int WINAPI WinMain()
{
	const char szUniqueNamedMutex[] = "com_mycompany_apps_appname";
	HANDLE hHandle = CreateMutex(NULL, TRUE, szUniqueNamedMutex);
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Program already running somewhere
		return(1); // Exit program
	}

	// Program runs...

	// Upon app closing:
	ReleaseMutex(hHandle); // Explicitly release mutex
	CloseHandle(hHandle); // close handle before terminating
	return(1);
}
*/
/*
bool CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters;
	neededClusters = diskSpaceNeeded /(diskfree.sectors_per_cluster *diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don’t have enough disk space!
		GCC_ERROR("CheckStorage Failure: Not enough physical storage.");
		return false;
	}
	return true;
}
*/



//DWORD ReadCPUSpeed() {
//	DWORD BufferSize = sizeof(DWORD);
//	DWORD SpeedValue = 0;
//	DWORD type = REG_DWORD;
//	HKEY hKey;
//
//	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
//
//	if (lError == ERROR_SUCCESS) {
//		RegQueryValueEx(hKey, "MHz", NULL, &type, (LPBYTE)&SpeedValue, &BufferSize);
//	}
//	return SpeedValue;
//}
//
//DWORD ReadProcessorArchitecture() {
//	DWORD BufferSize = sizeof(DWORD);
//	DWORD ArchitectureValue = 0;
//	DWORD type = REG_DWORD;
//	HKEY hKey;
//
//	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
//
//	if (lError == ERROR_SUCCESS) {
//		RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)&ArchitectureValue, &BufferSize);
//	}
//	return ArchitectureValue;
//}
//
//DWORD ReadProcessorIdentifier() {
//	DWORD BufferSize = sizeof(DWORD);
//	DWORD IdentifierValue = 0;
//	DWORD type = REG_DWORD;
//	HKEY hKey;
//
//	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
//
//	if (lError == ERROR_SUCCESS) {
//		RegQueryValueEx(hKey, "Identifier", NULL, &type, (LPBYTE)&IdentifierValue, &BufferSize);
//	}
//	return IdentifierValue;
//}
