#include "gamebehavoir.h"


GameBehavoir::GameBehavoir(void)
{
	
	mainCamera  = 0;
	GameBehavoir::thisGB;
}

bool GameBehavoir::instanceFlag = false;

GameBehavoir* GameBehavoir::thisGB = NULL;


GameBehavoir::~GameBehavoir(void)
{
}

GameBehavoir* GameBehavoir::getInstance(){
	if(!instanceFlag){
		thisGB = new GameBehavoir();
		instanceFlag = true;
		return thisGB;
	}else{
	return thisGB;
	}
}

void GameBehavoir::Update(){
	Camera *cmr;
    cmr = new Camera();

	mainCamera = cmr;

	
}




D3DXMATRIX * GameBehavoir::GetProjection(){
	
	return mainCamera->GetCameraLens();
}


D3DXMATRIX  * GameBehavoir::GetView(){

	return mainCamera->GetCameraPosition();
}