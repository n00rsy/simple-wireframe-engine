#pragma once

#include "Camera.h"
#include "Mesh.h"
#include <vector>
#include <DirectXMath.h>


class Device
{
private:
	XMVECTOR up;
	XMFLOAT2 project(XMFLOAT3 coordinate, XMMATRIX transformation);
public:
	XMFLOAT3* frame;
	unsigned frame_size, pixel_width, pixel_height;
	Device(unsigned width, unsigned height) {
		pixel_width = width;
		pixel_height = height;
		frame_size = pixel_width * pixel_height;
		frame = new XMFLOAT3[frame_size];
		XMFLOAT3 up_float(0, 1, 0);
		up = XMLoadFloat3(&up_float);
	}

	void render(Camera camera, std::vector<Mesh> meshes);
};

