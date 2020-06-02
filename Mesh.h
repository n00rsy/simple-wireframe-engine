#pragma once

#include <vector>
#include <string>
#include <DirectXMath.h>
#include <iostream>

using namespace DirectX;
using namespace std;

class Mesh
{
public:
	string name;
	XMFLOAT3 position, rotation;
	vector <XMFLOAT3> verts;

	Mesh(string name, int vert_count);
	Mesh(string name, vector<XMFLOAT3> verts);

	void printMesh();
};

