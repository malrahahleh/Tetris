#ifndef TETRIS_CORE3D_H
#define TETRIS_CORE3D_H

#include<d3d9.h>
#include<d3dx9.h>
#include"coretypes.h"

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")

class Core3D{

public:
	Core3D();
	~Core3D();
	void InitD3d(HWND);
	void RenderFramer();
	void CleandD3d();

private:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;
	LPDIRECT3DVERTEXBUFFER9 v_buffer;

};

#endif