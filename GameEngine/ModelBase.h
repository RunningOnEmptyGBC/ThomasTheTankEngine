#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
#include "TextureLoader.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>


using namespace std;
using namespace DirectX;

class ModelBase
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

public:
	ModelBase();
	ModelBase(const ModelBase&);
	~ModelBase();

	bool Init(ID3D11Device*, ID3D11DeviceContext*, const wchar_t*, const wchar_t*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

	


	bool InitBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, const wchar_t*);
	void ReleaseTexture();
	bool LoadModel(const wchar_t*);
	void ReleaseModel();

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureLoader* m_texture;
	ModelType* m_model;


	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
};