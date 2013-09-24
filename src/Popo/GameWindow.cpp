#include "StdAfx.h"
#include "GameWindow.h"

GameWindow::GameWindow(void)
{
}

GameWindow::~GameWindow(void)
{
}

BOOL GameWindow::PreCreateWindow()
{
	return FALSE;
}

wchar_t* GameWindow::GetWndClassName()
{
	return L"GameWindowClass";
}

LRESULT GameWindow::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(m_hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(m_hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		Destroy();
		break;
	default:
		return DefWindowProc(m_hWnd, uMsg, wParam, lParam);
	}
	return 0;
}