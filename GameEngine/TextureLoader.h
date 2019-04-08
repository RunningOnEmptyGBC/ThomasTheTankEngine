#pragma once
#include <d3d11.h>
#include <stdio.h>

#include <windows.h>
#include <wrl.h>
#include <string>
#include <stdlib.h>
//length = wcstombs(mbstring, wcstring, N);

using namespace std;

class TextureLoader
{
private:
	struct TargaHeader
	{
		unsigned char data1[12];
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char data2;
	};

public:
	TextureLoader();
	TextureLoader(const TextureLoader&);
	~TextureLoader();

	bool Init(ID3D11Device*, ID3D11DeviceContext*, const wchar_t*);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();

private:
	//Format Reading Function.  If supporting multiple formats, add additional format reading functions here

	//Targa format .tga
	bool LoadTarga(const wchar_t*, int&, int&);

	unsigned char*				m_targaData;
	ID3D11Texture2D*			m_texture;
	ID3D11ShaderResourceView*	m_textureView;

	//DirectDrawSurface format .dds
};