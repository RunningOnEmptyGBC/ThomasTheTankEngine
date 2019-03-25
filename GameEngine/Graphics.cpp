#include "Graphics.h"
#include <tchar.h>

Graphics::Graphics()
{
	m_D3D = 0;
	m_colourShader = 0;
	m_textureShader = 0;
	m_lightShader = 0;
	//m_camera = 0;
	//m_modelBase = 0;
	//m_bitmap = 0;
	m_sceneGraph = 0;
}

Graphics::Graphics(const Graphics& other)
{

}

Graphics::~Graphics()
{

}

bool Graphics::Init(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	//Create the Direct3D object
	m_D3D = new DXapp;
	if (!m_D3D)
	{
		return false;
	}

	//Initialize the Direct3D object
	result = m_D3D->Init(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Call to Direct3D failed!"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}

	//Create simple colour shader object
	m_colourShader = new ColourShader;
	if (!m_colourShader)
	{
		return false;
	}

	//Initialize the simple colour shader object
	result = m_colourShader->Init(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize simple colour shader"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}

	////Create camera object
	//m_camera = new Camera;
	//if (!m_camera)
	//{
	//	return false;
	//}

	////Set camera starting position
	//m_camera->SetPosition(0.0f, 0.0f, -5.0f);

	////Create model object
	//m_modelBase = new ModelBase;
	//if (!m_modelBase)
	//{
	//	return false;
	//}

	////Initialize model object
	//result = m_modelBase->Init(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), L"../Resources/Textures/bricks3.tga");
	//if (!result)
	//{
	//	MessageBox(hwnd,
	//		_T("Failed to initialize model object"),
	//		_T("Win32 Guided Tour"),
	//		MB_OK);
	//	return false;
	//}

	// Create the texture shader object.
	m_textureShader = new TextureShader;
	if (!m_textureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_textureShader->Init(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize the texture shader object"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}

	// Create the light shader object.
	m_lightShader = new LightingShader;
	if (!m_lightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_lightShader->Init(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize the light shader object"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}

	////Create the bitmap object.
	//m_bitmap = new BitmapBase;
	//if (!m_bitmap)
	//{
	//	return false;
	//}

	////Initialize the bitmap object.
	//result = m_bitmap->Init(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), screenWidth, screenHeight, L"../Resources/Textures/bricks3.tga", 800, 600);
	//if (!result)
	//{
	//	MessageBox(hwnd,
	//		_T("Failed to initialize the bitmap object"),
	//		_T("Win32 Guided Tour"),
	//		MB_OK);
	//	return false;
	//}


	m_sceneGraph = new SceneGraph;
	if (!m_sceneGraph)
	{
		return false;
	}

	result = m_sceneGraph->Init(screenWidth, screenHeight, hwnd, m_D3D);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize the SceneGraph"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}

	return true;
}

void Graphics::Shutdown()
{
	//// Release the bitmap object.
	//if (m_bitmap)
	//{
	//	m_bitmap->Shutdown();
	//	delete m_bitmap;
	//	m_bitmap = 0;
	//}

	//Release the simple colour shader object
	if (m_colourShader)
	{
		m_colourShader->Shutdown();
		delete m_colourShader;
		m_colourShader = 0;
	}

	// Release the texture shader object.
	if (m_textureShader)
	{
		m_textureShader->Shutdown();
		delete m_textureShader;
		m_textureShader = 0;
	}

	// Release the light shader object.
	if (m_lightShader)
	{
		m_lightShader->Shutdown();
		delete m_lightShader;
		m_lightShader = 0;
	}

	////Release the model object
	//if (m_modelBase)
	//{
	//	m_modelBase->Shutdown();
	//	delete m_modelBase;
	//	m_modelBase = 0;
	//}

	////Release the camera object
	//if (m_camera)
	//{
	//	delete m_camera;
	//	m_camera = 0;
	//}

	//Release the Direct3D object
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	return;
}

bool Graphics::Frame()
{
	bool result;
	static float rotation = 0.0f;

	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	return true;
}

bool Graphics::Render(float rotation)
{
	//XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	//bool result;

	////Clear the buffers to begin the scene
	//m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

	////Generate the view matrix based on the current camera position
	//m_camera->Render();

	////Get the world, view, and projection matrices from the camera and Direct3D objects
	//m_D3D->GetWorldMatrix(worldMatrix);
	//m_camera->GetViewMatrix(viewMatrix);
	//m_D3D->GetProjectionMatrix(projectionMatrix);
	//m_D3D->GetOrthoMatrix(orthoMatrix);

	////Add model vertex and index buffers to pipeline
	////m_modelBase->Render(m_D3D->GetDeviceContext());

	//// Turn off the Z buffer to begin all 2D rendering.
	//m_D3D->TurnZBufferOff();

	//// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//result = m_bitmap->Render(m_D3D->GetDeviceContext(), 0, 0);
	//if (!result)
	//{
	//	return false;
	//}

	//// Render the bitmap with the texture shader.
	//result = m_textureShader->Render(m_D3D->GetDeviceContext(), m_bitmap->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_bitmap->GetTexture());
	//if (!result)
	//{
	//	return false;
	//}

	////Render the model using the colour shader
	///*result = m_colourShader->Render(m_D3D->GetDeviceContext(), m_modelBase->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
	//if (!result)
	//{
	//	return false;
	//}*/

	//// Render the model using the texture shader.
	///*result = m_textureShader->Render(m_D3D->GetDeviceContext(), m_modelBase->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_modelBase->GetTexture());
	//if (!result)
	//{
	//	return false;
	//}*/

	//// Turn the Z buffer back on now that all 2D rendering has completed.
	////m_D3D->TurnZBufferOn();

	////Render scene to screen
	//m_D3D->EndScene();
	
	m_sceneGraph->Render(m_D3D, m_colourShader, m_textureShader, m_lightShader);

	return true;
}