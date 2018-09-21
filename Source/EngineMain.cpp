#include "stdio.h"
#include <iostream>
#include <windows.h>
#include <shlwapi.h>
#include "string.h"
using namespace std;
#define DIV 1024
#define WIDTH 7
const char* gameTitle = "Working Title";

int main() {

	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			cout << "An instance of your game is already running." << endl;
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	else {
		cout << "There is no other instance of you game running." << endl;
	}

	//Displays AVailable RAM
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	double displayRAM = (statex.ullAvailPhys /DIV)/DIV;
	cout << "RAM: " << displayRAM << " Megabytes" << endl;
	//Display Available Virual Mem
	double displayVir = (statex.ullAvailVirtual / DIV) / DIV;
	cout <<"Virtual Memory: "<< displayVir << " Megabytes" << endl;
	//

	//Display available Storage Space
	ULARGE_INTEGER Freebytes;
	unsigned long long displayStorage = 0;
	GetDiskFreeSpaceEx(TEXT("C:\\"), &Freebytes, 0, 0);
	displayStorage = (Freebytes.QuadPart/DIV)/DIV;
	cout <<"Available Storage: " <<displayStorage << endl;
	if (displayStorage > 300) {
		cout << "There is enough space" << endl;
	}
	else {
		cout << "This is not enough space" << endl;
	}
	//
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