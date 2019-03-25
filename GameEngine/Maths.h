#pragma once
#include <Windows.h>
#include <DirectXMath.h>
#include <cstdint>


class Maths
{
public:
	static DirectX::XMFLOAT4X4 Identity4x4()
	{
		static DirectX::XMFLOAT4X4 view(
			1.0f, 1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f);

		return view;
	}
};

