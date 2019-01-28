#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>
#include <string>
#include "DXutil.h"

class DXapp
{
public:
	DXapp(HINSTANCE hInstance);
	virtual ~DXapp(void);

	//main application loop
	int Run();

	//Framework methods
	virtual bool Init();
	virtual void Update(float dt) = 0;
	virtual void Render(float dt) = 0;
	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
	//WIN32 attributes
	HWND			m_hAppWnd;
	HINSTANCE		m_hAppInstance;
	UINT			m_ClientWidth;
	UINT			m_ClientHeight;
	std::string		m_AppTitle;
	DWORD			m_WndStyle;

	//DirectX Attributes
	ID3D11Device*				m_pDevice;
	ID3D11DeviceContext*		m_pImmediateContext;
	IDXGISwapChain*				m_pSwapChain;
	ID3D11RenderTargetView*		m_pRenderTargetView;
	D3D_DRIVER_TYPE				m_DriverType;
	D3D_FEATURE_LEVEL			m_FeatureLevel;
	D3D11_VIEWPORT				m_Viewport;

protected:
	//Initialize WIN32 window
	bool InitWindow();

	//Initialize Direct3D
	bool InitDirect3D();
};