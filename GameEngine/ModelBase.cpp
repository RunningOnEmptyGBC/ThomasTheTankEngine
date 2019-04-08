#include "ModelBase.h"

ModelBase::ModelBase()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_texture = 0;
	m_model = 0;
}

ModelBase::ModelBase(const ModelBase& other)
{
	
}

ModelBase::~ModelBase()
{

}

bool ModelBase::Init(ID3D11Device* device, ID3D11DeviceContext* deviceContext, const wchar_t* modelFilename, const wchar_t* textureFilename)
{
	bool result;

	//Load in the model data
	result = LoadModel(modelFilename);
	if (!result)
	{
		return false;
	}

	// Initialize the vertex and index buffers.
	result = InitBuffers(device);
	if (!result)
	{
		return false;
	}

	// Load the texture for this model.
	result = LoadTexture(device, deviceContext, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}

void ModelBase::Shutdown()
{
	// Release the model texture.
	ReleaseTexture();

	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	//Release the model data
	ReleaseModel();

	return;
}

void ModelBase::Render(ID3D11DeviceContext* deviceContext)
{
	
	
	
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//vertices[0].position = XMFLOAT3(4, 5, 7);
	RenderBuffers(deviceContext);

	return;
}

int ModelBase::GetIndexCount()
{
	return m_indexCount;
}

ID3D11ShaderResourceView* ModelBase::GetTexture()
{
	return m_texture->GetTexture();
}

bool ModelBase::InitBuffers(ID3D11Device* device)
{
	//In this function you will find the hardcoded triangle.
	//It is for demonstration purposes only and will be removed later

	
	
	HRESULT result;
	int i;

	//// Set the number of vertices in the vertex array.
	//m_vertexCount = 4;

	//// Set the number of indices in the index array.
	//m_indexCount = 6;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if (!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if (!indices)
	{
		return false;
	}

	//// Load the vertex array with data.
	//vertices[0].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);  // Bottom left.
	//vertices[0].texture = XMFLOAT2(0.0f, 1.0f);
	//vertices[0].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	//vertices[1].position = XMFLOAT3(-1.0f, 1.0f, 0.0f);  // Top left.
	//vertices[1].texture = XMFLOAT2(0.0f, 0.0f);
	//vertices[1].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	//vertices[2].position = XMFLOAT3(1.0f, -1.0f, 0.0f);  // Bottom right.
	//vertices[2].texture = XMFLOAT2(1.0f, 1.0f);
	//vertices[2].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	//vertices[3].position = XMFLOAT3(1.0f, 1.0f, 0.0f);	// Top right.
	//vertices[3].texture = XMFLOAT2(1.0f, 0.0f);
	//vertices[3].normal = XMFLOAT3(0.0f, 0.0f, -1.0f);

	//// Load the index array with data.
	//indices[0] = 0;  // Bottom left.
	//indices[1] = 1;  // Top left.
	//indices[2] = 2;  // Bottom right.

	//indices[3] = 1;
	//indices[4] = 3;
	//indices[5] = 2;

	//Load the vertex arrray and index array with data
	for (i = 0; i < m_vertexCount; i++)
	{
		vertices[i].position = XMFLOAT3(m_model[i].x, m_model[i].y, m_model[i].z);
		vertices[i].texture = XMFLOAT2(m_model[i].tu, m_model[i].tv);
		vertices[i].normal = XMFLOAT3(m_model[i].nx, m_model[i].ny, m_model[i].nz);

		indices[i] = i;
	}
	//Rotates the shape 45 Deg
	
	
	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	//delete[] vertices;
	//vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}

void ModelBase::ShutdownBuffers()
{
	// Release the index buffer.
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

void ModelBase::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Sets the vertex buffer to active in the input assembler so it can be rendered
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Sets the index buffer to active in the input assembler so it can be rendered
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Sets the type of primitive that should be rendered from this vertex buffer
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}

bool ModelBase::LoadTexture(ID3D11Device* device, ID3D11DeviceContext* deviceContext, const wchar_t* filename)
{
	bool result;


	// Create the texture object.
	m_texture = new TextureLoader;
	if (!m_texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_texture->Init(device, deviceContext, filename);
	if (!result)
	{
		return false;
	}

	return true;
}

void ModelBase::ReleaseTexture()
{
	// Release the texture object.
	if (m_texture)
	{
		m_texture->Shutdown();
		delete m_texture;
		m_texture = 0;
	}

	return;
}

bool ModelBase::LoadModel(const wchar_t* filename)
{
	ifstream fin;
	char input;
	int i;

	//Open the model file
	fin.open(filename);

	//If it could not open the file then exit
	if (fin.fail())
	{
		return false;
	}

	//Read up the value of the vertex count
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}

	//Read in the vertex count
	fin >> m_vertexCount;

	//Set the number of indices to be same as the vertex count
	m_indexCount = m_vertexCount;

	//Create the model using the vertex count that was read in
	m_model = new ModelType[m_vertexCount];
	if (!m_model)
	{
		return false;
	}

	//Read up to the beginning of the data
	fin.get(input);
	while (input != ':')
	{
		fin.get(input);
	}
	fin.get(input);
	fin.get(input);

	//Read the vertex data
	for (i = 0; i < m_vertexCount; i++)
	{
		fin >> m_model[i].x >> m_model[i].y >> m_model[i].z;
		fin >> m_model[i].tu >> m_model[i].tv;
		fin >> m_model[i].nx >> m_model[i].ny >> m_model[i].nz;
	}

	//Close the model file
	fin.close();

	return true;
}

void ModelBase::ReleaseModel()
{
	if (m_model)
	{
		delete[] m_model;
		m_model = 0;
	}

	return;
}
