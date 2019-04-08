#pragma once
//#ifndef_ENGINESYSTEM_H_
//#define_ENGINESYSTEM_H_
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "EditorMenuHandler.h"
#include "DXutil.h"
#include "Graphics.h"
#include "Input.h"
#include "Audio.h"

//Matthews includes
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "BaseObjectClass.h"
#include <algorithm>
#include <functional>


class EngineSystem
{
public:
	EngineSystem();
	EngineSystem(const EngineSystem&);
	~EngineSystem();

	virtual bool Init();
	virtual void Shutdown();
	virtual void Run();

	LRESULT CALLBACK MsgProc(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCSTR m_appName;
	LPCSTR m_menuName;
	HINSTANCE m_hAppInstance;
	HWND m_hAppWnd;
	HMENU m_hMenu;

	Input* m_Input;
	Graphics* m_Graphics;
	Audio* m_audio;
};

static LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
static EngineSystem* ApplicationHandle = 0;

//#endif