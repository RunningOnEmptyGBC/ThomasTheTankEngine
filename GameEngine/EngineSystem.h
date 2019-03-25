#pragma once
//#ifndef_ENGINESYSTEM_H_
//#define_ENGINESYSTEM_H_
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "DXutil.h"
#include "Graphics.h"
#include "Input.h"
#include "Audio.h"

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
	HINSTANCE m_hAppInstance;
	HWND m_hAppWnd;

	Input* m_Input;
	Graphics* m_Graphics;
	Audio* m_audio;
};

static LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);
static EngineSystem* ApplicationHandle = 0;

//#endif