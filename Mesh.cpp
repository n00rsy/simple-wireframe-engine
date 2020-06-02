#include "Mesh.h"

Mesh::Mesh(string name, int vert_count) {
	this->name = name;
	verts = vector<XMFLOAT3>(vert_count);
}

Mesh::Mesh(string name, vector<XMFLOAT3> verts) {
	this->name = name;
	this->verts = verts;
}

void Mesh::printMesh() {
	cout << name << endl;
	for (auto vert : verts){
		cout << "x: " << vert.x << " y: " << vert.y << " z: " << vert.z << endl; 
	}
}