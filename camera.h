#ifndef TETRIS_CORE3D_CAMERA_H
#define TETRIS_CORE3D_CAMERA_H

#include"core3d.h"

class Camera {
public:
	Camera();
	~Camera();
	void Position(VECTOR3);
	void LookAt(VECTOR3);
	void Enabled();
	D3DXMATRIX * GetCameraLens();
	D3DXMATRIX * GetCameraPosition();
private:
	D3DXMATRIX matView;
	D3DXMATRIX matProjection;

};
#endif

