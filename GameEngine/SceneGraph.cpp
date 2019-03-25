#include "SceneGraph.h"

SceneGraph::SceneGraph()
{
	//m_D3D = 0;
	//m_colourShader = 0;
	//m_textureShader = 0;
	m_camera = 0;
	m_modelBase[0] = 0;
	m_bitmap[0] = 0;
}

SceneGraph::SceneGraph(const SceneGraph& other)
{

}

SceneGraph::~SceneGraph()
{

}

bool SceneGraph::Init(int screenWidth, int screenHeight, HWND hwnd, DXapp* m_D3D)
{
	bool result;

	//m_D3D = new DXapp;

	//Create camera object
	m_camera = new Camera;
	if (!m_camera)
	{
		return false;
	}

	//Set camera starting position
	m_camera->SetPosition(0.0f, 0.0f, -5.0f);

	// Create the light object.
	m_lights = new Lights;
	if (!m_lights)
	{
		return false;
	}

	// Initialize the light object.
	m_lights->SetAmbientColour(0.15f, 0.15f, 0.15f, 1.0f);
	m_lights->SetDiffuseColour(0.7f, 1.0f, 1.0f, 1.0f);
	m_lights->SetDirection(0.2f, 0.0f, 1.0f);
	m_lights->SetSpecularColour(1.0f, 1.0f, 1.0f, 1.0f);
	m_lights->SetSpecularPower(30.0f);

	//Create model object
	m_modelBase[0] = new ModelBase;
	if (!m_modelBase)
	{
		return false;
	}

	//Initialize model object
	result = m_modelBase[0]->Init(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), L"../Resources/Models/cube.txt", L"../Resources/Textures/bricks3.tga");
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize model object"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}
	m_modelBase[0];
	//Create the bitmap object.
	m_bitmap[0] = new BitmapBase;
	if (!m_bitmap)
	{
		return false;
	}

	//Initialize the bitmap object.
	result = m_bitmap[0]->Init(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), screenWidth, screenHeight, L"../Resources/Textures/bricks3.tga", 800, 600);
	if (!result)
	{
		MessageBox(hwnd,
			_T("Failed to initialize the bitmap object"),
			_T("Win32 Guided Tour"),
			MB_OK);
		return false;
	}
	
	return true;
}

void SceneGraph::Shutdown()
{
	// Release the bitmap object.
	if (m_bitmap)
	{
		m_bitmap[0]->Shutdown();
		delete m_bitmap;
		m_bitmap[0] = 0;
	}

	//Release the model object
	if (m_modelBase)
	{
		m_modelBase[0]->Shutdown();
		delete m_modelBase;
		m_modelBase[0] = 0;
	}

	// Release the light object.
	if (m_lights)
	{
		delete m_lights;
		m_lights = 0;
	}

	//Release the camera object
	if (m_camera)
	{
		delete m_camera;
		m_camera = 0;
	}
}

bool SceneGraph::Render(DXapp* m_D3D, ColourShader* m_colourShader, TextureShader* m_textureShader, LightingShader* m_lightShader)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	int level = 1;

	
	if (level == 0)
	{
		//Clear the buffers to begin the scene
		m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

		//Generate the view matrix based on the current camera position
		m_camera->Render();

		//Get the world, view, and projection matrices from the camera and Direct3D objects
		m_D3D->GetWorldMatrix(worldMatrix);
		m_camera->GetViewMatrix(viewMatrix);
		m_D3D->GetProjectionMatrix(projectionMatrix);
		m_D3D->GetOrthoMatrix(orthoMatrix);

		// Turn off the Z buffer to begin all 2D rendering.
		m_D3D->TurnZBufferOff();

		// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
		result = m_bitmap[0]->Render(m_D3D->GetDeviceContext(), 0, 0);
		if (!result)
		{
			return false;
		}

		// Render the bitmap with the texture shader.
		result = m_textureShader->Render(m_D3D->GetDeviceContext(), m_bitmap[0]->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_bitmap[0]->GetTexture());
		if (!result)
		{
			return false;
		}

		// Turn the Z buffer back on now that all 2D rendering has completed.
		m_D3D->TurnZBufferOn();

		//Render scene to screen
		m_D3D->EndScene();
	}
	else if (level == 1)
	{
		//Clear the buffers to begin the scene
		m_D3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);

		//Generate the view matrix based on the current camera position
		m_camera->Render();

		//Get the world, view, and projection matrices from the camera and Direct3D objects
		m_D3D->GetWorldMatrix(worldMatrix);
		m_camera->GetViewMatrix(viewMatrix);
		m_D3D->GetProjectionMatrix(projectionMatrix);
		m_D3D->GetOrthoMatrix(orthoMatrix);

		//Add model vertex and index buffers to pipeline
		
		m_modelBase[0]->Render(m_D3D->GetDeviceContext());

		//Render the model using the colour shader
		/*result = m_colourShader->Render(m_D3D->GetDeviceContext(), m_modelBase->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
		if (!result)
		{
			return false;
		}*/

		// Render the model using the texture shader.
		/*result = m_textureShader->Render(m_D3D->GetDeviceContext(), m_modelBase[0]->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_modelBase[0]->GetTexture());
		if (!result)
		{
			return false;
		}*/

		// Render the model using the light shader.
		result = m_lightShader->Render(m_D3D->GetDeviceContext(), m_modelBase[0]->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_modelBase[0]->GetTexture(), m_lights->GetDirection(), m_lights->GetAmbientColour(), m_lights->GetDiffuseColour(), m_camera->GetPosition(), m_lights->GetSpecularColour(), m_lights->GetSpecularPower());
		if (!result)
		{
			return false;
		}

		//Render scene to screen
		m_D3D->EndScene();
	}

	return true;
}
