#pragma once
#include "DXapp.h"
#include "ColourShader.h"
#include "TextureShader.h"
#include "LightingShader.h"
#include "ModelBase.h"
#include "Camera.h"
#include "Lights.h"
#include "BitmapBase.h"

//Matthews includes
#include <stdio.h>
#include "BaseObjectClass.h"
#include "iostream"
#include <map>
#include <list>
#include <iterator>


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
	// Matthews Publics 
	void PrintAllObjectData();
	void AddtoSceneGraph(BaseObjectClass* object);
	void RemoveFromSceneGraph(BaseObjectClass* object);
	void Update();
	void Start();
	void EmptyBuffer();
	BaseObjectClass* MakeCube(DXapp* D3d);
private:
	// Matthews Privates
	std::map<int, BaseObjectClass*> m_ObjectsBuffer;
	std::map<int, BaseObjectClass*> m_Objects;
	static int nextObjectID;
	static int bufferNextObjectID;


	//DXapp* m_D3D;
	//ColourShader* m_colourShader;
	//TextureShader* m_textureShader;
	ModelBase* m_modelBase[4];
	Camera* m_camera;
	Lights* m_lights;
	BitmapBase*	m_bitmap[4];


	DXapp* Scene_D3D;
	LightingShader* Scene_lightShader;
};