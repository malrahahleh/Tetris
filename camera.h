#ifndef TETRIS_CORE3D_CAMERA_H
#define TETRIS_CORE3D_CAMERA_H

#include"core3d.h"

class Camera {
public:
	Camera();
	~Camera();
	static void Position(VECTOR3);
	static void LookAt(VECTOR3);
private:
	D3DXMatrix matView;
	D3DXMATRIX matProjection;

};
#endif

