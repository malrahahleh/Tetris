#ifndef TETRIS_CORETYPES_H
#define TETRIS_CORETYPES_H

struct CUSTOMVERTEX{
	FLOAT x, y, z;
	DWORD color;
};

struct VECTOR3{
	FLOAT x,y,z;
};

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#define SCREEN_HIEGHT 600
#define SCREEN_WIDTH 800


#endif