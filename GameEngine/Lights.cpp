#include "Lights.h"

Lights::Lights()
{

}

Lights::Lights(const Lights &)
{

}

Lights::~Lights()
{

}

void Lights::SetAmbientColour(float r, float g, float b, float a)
{
	m_ambientColour = XMFLOAT4(r, g, b, a);
	return;
}

void Lights::SetDiffuseColour(float r, float g, float b, float a)
{
	m_diffuseColour = XMFLOAT4(r, g, b, a);
	return;
}

void Lights::SetDirection(float x, float y, float z)
{
	m_direction = XMFLOAT3(x, y, z);
	return;
}

void Lights::SetSpecularColour(float r, float g, float b, float a)
{
	m_specularColour = XMFLOAT4(r, g, b, a);
	return;
}

void Lights::SetSpecularPower(float power)
{
	m_specularPower = power;
	return;
}

XMFLOAT4 Lights::GetAmbientColour()
{
	return m_ambientColour;
}

XMFLOAT4 Lights::GetDiffuseColour()
{
	return m_diffuseColour;
}

XMFLOAT3 Lights::GetDirection()
{
	return m_direction;
}

XMFLOAT4 Lights::GetSpecularColour()
{
	return m_specularColour;
}

float Lights::GetSpecularPower()
{
	return m_specularPower;
}
