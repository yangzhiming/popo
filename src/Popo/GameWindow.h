#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_

#include "window.h"

class GameWindow : public Window
{
public:
	GameWindow(void);
	~GameWindow(void);

	virtual BOOL PreCreateWindow();
	virtual wchar_t* GetWndClassName();
	virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:

};

#endif //_GAME_WINDOW_H_