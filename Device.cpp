#include "Device.h"

XMFLOAT2 Device::project(XMFLOAT3 coordinate, XMMATRIX transformation) {
	XMVECTOR point = XMVector3TransformCoord(XMLoadFloat3(&coordinate), transformation);
	XMFLOAT2 p;
	XMStoreFloat2(&p,point);
	float x = p.x * pixel_width + pixel_width / 2;
	float y = -p.y * pixel_height + pixel_height / 2;

	return XMFLOAT2(x, y);
}

void printXMFLOAT2(XMFLOAT2 xmf) {
	cout << "x: " << xmf.x << " y: " << xmf.y<<endl;
}

void Device::render(Camera camera, std::vector<Mesh> meshes) {

	//calculate view and projection matricies
	XMMATRIX view = XMMatrixLookAtLH(XMLoadFloat3(&camera.position), XMLoadFloat3(&camera.target), up);
	cout << pixel_width << "  " << pixel_height << endl;
	XMMATRIX projection = XMMatrixPerspectiveFovRH(0.7, pixel_width / pixel_height, 0.01, 1);

	for (auto mesh : meshes) {
		//calcuate world matrix	
		XMMATRIX world = XMMatrixRotationRollPitchYawFromVector(XMLoadFloat3(&mesh.rotation))*XMMatrixTranslationFromVector(XMLoadFloat3(&mesh.position));

		XMMATRIX transform = world * view * projection;

		for (auto vert : mesh.verts) {
			//project into 2d space of renderer
			XMFLOAT2 point = project(vert, transform);
			//draw vert on screen
			printXMFLOAT2(point);
		}
	}
}