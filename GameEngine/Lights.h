#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class Lights
{
public:
	Lights();
	Lights(const Lights&);
	~Lights();

	void SetAmbientColour(float, float, float, float);
	void SetDiffuseColour(float, float, float, float);
	void SetDirection(float, float, float);
	void SetSpecularColour(float, float, float, float);
	void SetSpecularPower(float);

	XMFLOAT4 GetAmbientColour();
	XMFLOAT4 GetDiffuseColour();
	XMFLOAT3 GetDirection();
	XMFLOAT4 GetSpecularColour();
	float GetSpecularPower();

private:
	XMFLOAT4 m_ambientColour;
	XMFLOAT4 m_diffuseColour;
	XMFLOAT3 m_direction;
	XMFLOAT4 m_specularColour;
	float m_specularPower;
};