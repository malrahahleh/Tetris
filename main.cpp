#include<Windows.h>
#include<WindowsX.h>
#include<d3d9.h>

#pragma comment (lib,"d3d9.lib")

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define SCREEN_HIEGHT 600
#define SCREEN_WIDTH 800

LRESULT __stdcall WindowProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

void InitD3d(HWND);
void RenderFramer();
void CleandD3d();
void Init_Triangle();

LPDIRECT3D9 d3d;
LPDIRECT3DDEVICE9 d3ddev;
LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;


struct CUSTOMVERTEX{
	FLOAT x, y, z, rhw;
	DWORD color;
};


int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;
	ZeroMemory(&wc,sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);



	// create the window and use the result as the handle
    hWnd = CreateWindowEx(NULL,
                          L"WindowClass",    // name of the window class
                          L"Our First Windowed Program",   // title of the window
                          WS_OVERLAPPEDWINDOW,    // window style
                          0,    // x-position of the window
                          0,    // y-position of the window
                          SCREEN_WIDTH,    // width of the window
                          SCREEN_HIEGHT,    // height of the window
                          NULL,    // we have no parent window, NULL
                          NULL,    // we aren't using menus, NULL
                          hInstance,    // application handle
                          NULL);    // used with multiple windows, NULL

    // display the window on the screen
    ShowWindow(hWnd, nCmdShow);

	MSG msg;
	InitD3d(hWnd);
	while(TRUE){

		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
			break;
		RenderFramer();
	}
	CleandD3d();
}

LRESULT __stdcall WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message){
		 

		case WM_DESTROY : {
			PostQuitMessage(0);
			return 0;
		}break;
	}

    return DefWindowProc(hWnd,message,wParam,lParam);
}

void InitD3d(HWND hWnd){
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
	Init_Triangle();
}

void RenderFramer(){
	d3ddev->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,0);

	d3ddev->BeginScene();

	d3ddev->SetFVF(CUSTOMFVF);

	d3ddev->SetStreamSource(0,v_buffer,0,sizeof(CUSTOMVERTEX));
	
	d3ddev->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

	d3ddev->EndScene();

	d3ddev->Present(NULL,NULL,NULL,NULL);
}

void CleandD3d(){
	v_buffer->Release();
	d3ddev->Release();
	d3d->Release();
}

void Init_Triangle(){

	CUSTOMVERTEX vertices[]=
	{
		{300.0f,124.0f,0.5f,1.0,D3DCOLOR_XRGB(0,0,255),},
		{450.0f,124.0f,0.5f,1.0,D3DCOLOR_XRGB(0,0,255),},
		{300.0f,250.0f,0.5f,1.0f,D3DCOLOR_XRGB(0,0,255),},
		{450.0f,250.0f,0.5f,1.0f,D3DCOLOR_XRGB(0,0,200),},
		
	};


	d3ddev->CreateVertexBuffer(sizeof(vertices)*sizeof(CUSTOMVERTEX),
								0,
								CUSTOMFVF,
								D3DPOOL_MANAGED,
								&v_buffer,
								NULL);

	VOID* pVoid;

	v_buffer->Lock(0,0,&pVoid,0);

	memcpy(pVoid,vertices,sizeof(vertices));
	
	v_buffer->Unlock();

}