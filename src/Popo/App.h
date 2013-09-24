#pragma once

#include "Singleton.h"
#include "Window.h"
#include "Game.h"

class App : public SingletonT<App>
{
public:
	virtual BOOL InitInstance(HINSTANCE hInstance);
	virtual int ExitInstance();
	virtual int Run();

public:
	App(void);
	~App(void);

protected:
	Window*		m_pMainWnd;
	HINSTANCE   m_hInstance;
	Game*		m_pGame;
};
