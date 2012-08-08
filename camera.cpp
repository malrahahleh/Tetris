#include"camera.h"

Camera::Camera(){

	//fill the view matrix
	D3DXMatrixLookAtLH(&matView,
						&D3DXVECTOR3(0.0f,0.0f,10.0f),
						&D3DXVECTOR3(0.0f,0.0f,0.0f),
						&D3DXVECTOR3(0.0f,1.0f,0.0f));

	//fill the projection matrix
	D3DXMatrixPerspectiveFovLH(&matProjection,
								D3DXToRadian(45.0f),
								(FLOAT)SCREEN_WIDTH / (FLOAT)SCREEN_HIEGHT,
								1.0f,
								100.0f);

}

Camera::~Camera(){

}


D3DXMATRIX * Camera::GetCameraLens(){

	return &matProjection;
}

D3DXMATRIX * Camera::GetCameraPosition(){

	return &matView;
}