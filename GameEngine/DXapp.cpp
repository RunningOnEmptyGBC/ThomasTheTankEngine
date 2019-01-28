#include "DXapp.h"
#include <WindowsX.h>

//using Microsoft::WRL::ComPtr;
//using namespace std;
using namespace DirectX;
namespace
{
	//used to forward messages to user defined
	DXapp* g_pApp = nullptr;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (g_pApp) {
		return g_pApp->MsgProc(hWnd, msg, wParam, lParam);
	}
	else {
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

DXapp::DXapp(HINSTANCE hInstance)
{
	m_hAppInstance = hInstance;
	m_hAppWnd = nullptr;
	m_ClientWidth = 640;
	m_ClientHeight = 480;
	m_AppTitle = "DirectX11 Application Window";
	m_WndStyle = WS_OVERLAPPEDWINDOW | WS_TABSTOP;
	g_pApp = this;

	m_pDevice = nullptr;
	m_pImmediateContext = nullptr;
	m_pSwapChain = nullptr;
	m_pRenderTargetView = nullptr;
}

DXapp::~DXapp(void)
{
	//Cleanup Direct3D
	if (m_pImmediateContext) {
		m_pImmediateContext->ClearState();
	}

	Memory::SafeRelease(m_pRenderTargetView);
	Memory::SafeRelease(m_pSwapChain);
	Memory::SafeRelease(m_pImmediateContext);
	Memory::SafeRelease(m_pDevice);
}

int DXapp::Run()
{
	//main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			

		}
		else
		{
			//Update
			Update(0.0f);
			//Render
			Render(0.0f);
		}
	}

	return static_cast<int>(msg.wParam);
}

bool DXapp::Init()
{
	if (!InitWindow()) {
		return false;
	}

	if (!InitDirect3D()) {
		return false;
	}

	return true;
}

bool DXapp::InitWindow()
{
	//WNDCLASSEX
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWndProc;	
	wcex.hInstance = m_hAppInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "DXWin32app";

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return false;
	} 

	RECT r = { 0, 0, m_ClientWidth, m_ClientHeight };
	AdjustWindowRect(&r, m_WndStyle, FALSE);
	UINT width = r.right - r.left;
	UINT height = r.bottom - r.top;
	UINT x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
	UINT y = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;
	
	m_hAppWnd = CreateWindowEx(
			0,					//DWORD dwExStyle
			"DXWin32app",		//LPCSTR lpClassName
			m_AppTitle.c_str(),	//LPCSTR lpWindowName
			m_WndStyle,			//DWORD dwStyle
			x, y,				//int X & int Y
			width, height,		//int nWidth & int nHeight
			nullptr,			//HWND hWndParent
			nullptr,			//HMENU hMenu
			m_hAppInstance,		//HINSTANCE hInstance
			nullptr				//LPVOID lpParam

			/*
			The parameters to CreateWindow explained:
			Extended Window Style: not used in this application
			szWindowClass: the name of the application
			szTitle: the text that appears in the title bar
			Window Style: the type(s) of window to create
			CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
			Wx, Wy: initial size (width, length)
			NULL: the parent of this window
			NULL: this application does not have a menu bar
			hInstance: the first parameter from WinMain
			NULL: not used in this application
			*/
		);

	if (!m_hAppWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindowEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return false;
	}

	ShowWindow(m_hAppWnd, SW_SHOW);

	return true;
}

bool DXapp::InitDirect3D()
{
	UINT createDeviceFlags = 0;

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif //Debug

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	DXGI_SWAP_CHAIN_DESC swapDesc;
	ZeroMemory(&swapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapDesc.BufferCount = 1; // 0 single buffered | 1 double buffered
	swapDesc.BufferDesc.Width = m_ClientWidth;
	swapDesc.BufferDesc.Height = m_ClientHeight;
	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.OutputWindow = m_hAppWnd;
	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapDesc.Windowed = true;
	swapDesc.SampleDesc.Count = 1;
	swapDesc.SampleDesc.Quality = 0;
	swapDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; //alt+enter fullscreen

	HRESULT result;
	for (int i = 0; i < numDriverTypes; i++)
	{
		result = D3D11CreateDeviceAndSwapChain(NULL,
			driverTypes[i],
			NULL,
			createDeviceFlags,
			featureLevels,
			numFeatureLevels,
			D3D11_SDK_VERSION,
			&swapDesc,
			&m_pSwapChain,
			&m_pDevice,
			&m_FeatureLevel,
			&m_pImmediateContext);

		if (SUCCEEDED(result))
		{
			m_DriverType = driverTypes[i];
			break;
		}
	}

	if (FAILED(result))
	{
		MessageBox(NULL,
			_T("Call to Create Device and Swap Chain failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return false;
	}

	//Create render target view
	ID3D11Texture2D* m_pBackBufferTex = 0;
	HR(m_pSwapChain->GetBuffer(NULL, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_pBackBufferTex)));
	HR(m_pDevice->CreateRenderTargetView(m_pBackBufferTex, nullptr, &m_pRenderTargetView));
	Memory::SafeRelease(m_pBackBufferTex);

	//Bind render target view
	m_pImmediateContext->OMSetRenderTargets(1, &m_pRenderTargetView, nullptr);

	//Create viewport
	m_Viewport.Width = static_cast<float>(m_ClientWidth);
	m_Viewport.Height = static_cast<float>(m_ClientHeight);
	m_Viewport.TopLeftX = 0;
	m_Viewport.TopLeftY = 0;
	m_Viewport.MinDepth = 0.0f;
	m_Viewport.MaxDepth = 1.0f;

	//Bind viewport
	m_pImmediateContext->RSSetViewports(1, &m_Viewport);

	return true;
}

LRESULT DXapp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}