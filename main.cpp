

#include<Windows.h>
#include<WindowsX.h>

#include"core3d.h"

LRESULT __stdcall WindowProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);







int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;
	ZeroMemory(&wc,sizeof(WNDCLASSEX));

	Core3D* cr3D = new Core3D();



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
	cr3D->InitD3d(hWnd);
	while(TRUE){

		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
			break;
		cr3D->RenderFramer();
	}

	cr3D->CleandD3d();
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
