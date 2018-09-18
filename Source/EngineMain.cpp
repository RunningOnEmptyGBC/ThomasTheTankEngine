#include "stdio.h"
#include <iostream>
#include <windows.h>
#include <shlwapi.h>
#include "string.h"
using namespace std;
#define DIV 1024
#define WIDTH 7

int main() {
	// Seems to display available RAM not HDD
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	double display = (statex.ullAvailPhys /DIV)/DIV;
	cout << display << " Megabytes" << endl;
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