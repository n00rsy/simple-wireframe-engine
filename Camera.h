#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Camera
{
public:
	XMFLOAT3 position, target;
	
	Camera(XMFLOAT3 pos, XMFLOAT3 tar) {
		position = pos;
		target = tar;
	}
};

