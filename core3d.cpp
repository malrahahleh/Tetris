#include"core3d.h"

Core3D::Core3D(){
	//v_buffer = NULL;
}

Core3D::~Core3D(){
}

void Core3D::InitD3d(HWND hWnd){
	
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp,sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	

	d3d->CreateDevice(D3DADAPTER_DEFAULT,
						D3DDEVTYPE_HAL,
						hWnd,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING,
						&d3dpp,
						&d3ddev);

	d3ddev->SetRenderState(D3DRS_LIGHTING,FALSE);

	
}

void Core3D::CleandD3d(){
	//Core3D::v_buffer->Release();
	Core3D::d3ddev->Release();
	Core3D::d3d->Release();
}


void Core3D::RenderFramer(){

	GameBehavoir* gb;
	gb = GameBehavoir::getInstance();
	gb->Update();

	d3ddev->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,0);
	d3ddev->BeginScene();
	
	

	d3ddev->SetFVF(CUSTOMFVF);

	D3DXMATRIX matWorld;
	D3DXMatrixTranslation(&matWorld,0.0f,0.0f,0.0f);

	
	d3ddev->SetTransform(D3DTS_WORLD,&matWorld);
	d3ddev->SetTransform(D3DTS_VIEW,gb->GetView());
	d3ddev->SetTransform(D3DTS_PROJECTION,gb->GetProjection());


	d3ddev->EndScene();
	d3ddev->Present(NULL,NULL,NULL,NULL);
}