
#include <iostream>
#include <DirectXMath.h>

#include "Mesh.h"
#include "Camera.h"
#include "Device.h"
#include "Window.h"

using namespace DirectX;

int main(int argc, char* argv[])
{
	vector<Mesh> meshes;
	vector<XMFLOAT3> boxVerts;

	boxVerts.push_back(XMFLOAT3(-1, 1, 1));
	boxVerts.push_back(XMFLOAT3(1, 1, 1));
	boxVerts.push_back(XMFLOAT3(-1, -1, 1));
	boxVerts.push_back(XMFLOAT3(-1, -1, -1));
	boxVerts.push_back(XMFLOAT3(-1, 1, -1));
	boxVerts.push_back(XMFLOAT3(1, 1, -1));
	boxVerts.push_back(XMFLOAT3(1, -1, 1));
	boxVerts.push_back(XMFLOAT3(1, -1, -1));

	Mesh box("box", boxVerts);
	meshes.push_back(box);

	Camera camera(XMFLOAT3(0, 0, 10), XMFLOAT3(0, 0, 0));

	Device device(640, 480);
	Window window(640, 480);


	while (true) {
		box.rotation.x += 0.01;
		box.rotation.y += 0.01;
		cout << box.rotation.x << endl;
		device.render(camera, meshes);
		window.show(device.frame);
		std::cout << "TEEEE" << endl;

		SDL_Delay(1000);
	}






	return 0;
}
