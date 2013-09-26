#include "StdAfx.h"
#include "App.h"
#include "GameWindow.h"

static const UINT FPS = 30;

GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;

App::App(void)
: m_pMainWnd(NULL),
  m_hInstance(NULL),
  m_pGame(NULL)
{
}

App::~App(void)
{
}

BOOL App::InitInstance(HINSTANCE hInstance)
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wchar_t szFileName[MAX_PATH];
	::GetModuleFileName(NULL, szFileName, MAX_PATH);
	
	std::wstring strFileName(szFileName);
	size_t pos = strFileName.rfind('\\');
	std::wstring strDirectory = strFileName.substr(0, pos);
	::SetCurrentDirectory(strDirectory.c_str());

	m_hInstance = hInstance;
	m_pMainWnd = new GameWindow();
	m_pMainWnd->Create(L"GameWindow", 200, 200, 806, 628);
	m_pMainWnd->ShowWindow(TRUE);
	m_pMainWnd->UpdateWindow();

	m_pGame = new Game();
	m_pGame->Init();

	return TRUE;
}

int App::ExitInstance()
{
	delete m_pGame;
	m_pGame = NULL;

	delete m_pMainWnd;

	GdiplusShutdown(gdiplusToken);


	return 0;
}

int App::Run()
{
	MSG msg;
	while (TRUE)
	{	
		if(PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if(!GetMessage(&msg, NULL, 0, 0))
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// do render
			static float timeLast = (float)::timeGetTime();
			float timeNow = (float)::timeGetTime();
			float timePast = timeNow - timeLast;

			if( timePast > 3600/ FPS ) 
			{
				Graphics* pGraph = Graphics::FromHWND(m_pMainWnd->GetHWnd());

				m_pGame->Update(timePast);
				m_pGame->Draw(pGraph);
				
				timeLast = timeNow;
			}
			else
			{
				WaitMessage();
			}
		}
	}

	return (int) msg.wParam;
}