// Popo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Popo.h"
#include "App.h"

#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "winmm.lib")

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if(App::GetInstance()->InitInstance(hInstance))
	{
		App::GetInstance()->Run();

		return App::GetInstance()->ExitInstance();
	}

	return 0;
}