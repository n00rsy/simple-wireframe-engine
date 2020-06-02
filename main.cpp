
#include <iostream>

#include "Mesh.h"
#include "Camera.h"
#include "Device.h"
#include <DirectXMath.h>

using namespace DirectX;

int main()
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

    Device device(640,480);

    device.render(camera, meshes);
}

