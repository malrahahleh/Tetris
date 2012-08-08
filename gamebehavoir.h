#ifndef TETRIS_CORE3D_GAMEBEHAVIOR_H
#define TETRIS_CORE3D_GAMEBEHAVIOR_H
#include "camera.h"
class GameBehavoir
{
public:
	
	
	Camera *mainCamera;

	
	static GameBehavoir* getInstance();
	~GameBehavoir(void);
	void Update();
	void Start();
	D3DXMATRIX * GetProjection();
	D3DXMATRIX * GetView();

private:
	static bool instanceFlag;
	static GameBehavoir *thisGB;
	GameBehavoir(void);
	
};


#endif

