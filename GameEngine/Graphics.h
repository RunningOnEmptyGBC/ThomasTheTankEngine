#pragma once
//#ifndef_GRAPHICS_H_
//#define_GRAPHICS_H_
#include "DXapp.h"
#include "ColourShader.h"
#include "TextureShader.h"
#include "LightingShader.h"
#include "ModelBase.h"
#include "Camera.h"
#include "Lights.h"
#include "BitmapBase.h"
#include "SceneGraph.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&);
	~Graphics();

	bool Init(int, int, HWND);
	void Shutdown();
	bool Frame();


	bool Render(float);

	DXapp* m_D3D;
	ColourShader* m_colourShader;
	TextureShader* m_textureShader;
	LightingShader* m_lightShader;
	ModelBase* m_modelBase;
	Camera* m_camera;
	Lights* m_lights;
	BitmapBase*	m_bitmap;
	SceneGraph* m_sceneGraph;
};

//#endif