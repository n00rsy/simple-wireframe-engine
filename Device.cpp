#include "Device.h"
#include <fstream>
#include <algorithm>

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
void printXMFLOAT3(XMFLOAT3 xmf) {
	cout << "x: " << xmf.x << " y: " << xmf.y << " z: "<< xmf.z<< endl;
}

void Device::putPixel(float x, float y, XMFLOAT3 color) {
	int index = x + y * pixel_width;
	frame[index] = color;
}

void Device::saveToFile() {
	ofstream ofs("./render.ppm", ios::out | ios::binary);
	ofs << "P6\n" << pixel_width << " " << pixel_height << "\n255\n";
	for (unsigned i = 0; i < pixel_width * pixel_height; ++i) {
		ofs << (unsigned char)(min(float(1), frame[i].x) * 255) <<
			(unsigned char)(min(float(1), frame[i].y) * 255) <<
			(unsigned char)(min(float(1), frame[i].z) * 255);
	}
	ofs.close();
}

void Device::clear_frame() {
	for (int i = 0; i < frame_size; i++) {
		frame[i].x = 0;
		frame[i].y = 0;
		frame[i].z = 0;
	}
}

void Device::render(Camera camera, std::vector<Mesh> meshes) {

	//calculate view and projection matricies
	XMMATRIX view = XMMatrixLookAtLH(XMLoadFloat3(&camera.position), XMLoadFloat3(&camera.target), up);
	XMMATRIX projection = XMMatrixPerspectiveFovRH(0.7, pixel_width / pixel_height, 0.01, 1);

	clear_frame();

	for (auto mesh : meshes) {
		//calcuate world matrix	
		XMMATRIX world = XMMatrixRotationRollPitchYawFromVector(XMLoadFloat3(&mesh.rotation))*XMMatrixTranslationFromVector(XMLoadFloat3(&mesh.position));

		XMMATRIX transform = world * view * projection;
		
		for (auto vert : mesh.verts) {
			printXMFLOAT3(vert);
			//project into 2d space of renderer
			XMFLOAT2 point = project(vert, transform);

			//draw vert on screen
			putPixel(point.x, point.y, XMFLOAT3(1, 1, 0));
			//printXMFLOAT2(point);
		}
	}
	saveToFile();
}