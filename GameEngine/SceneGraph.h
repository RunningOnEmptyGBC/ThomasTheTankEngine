#pragma once
#include "DXapp.h"
#include "ColourShader.h"
#include "TextureShader.h"
#include "LightingShader.h"
#include "ModelBase.h"
#include "Camera.h"
#include "Lights.h"
#include "BitmapBase.h"

class SceneGraph
{
public:
	SceneGraph();
	SceneGraph(const SceneGraph&);
	~SceneGraph();

	bool Init(int, int, HWND, DXapp*);
	void Shutdown();
	//bool Frame();
	bool Render(DXapp*, ColourShader*, TextureShader*, LightingShader*);

private:
	

	//DXapp* m_D3D;
	//ColourShader* m_colourShader;
	//TextureShader* m_textureShader;
	ModelBase* m_modelBase[4];
	Camera* m_camera;
	Lights* m_lights;
	BitmapBase*	m_bitmap[4];
};