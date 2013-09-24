#include "StdAfx.h"
#include "Window.h"

Window::Window(void)
: m_hWnd (NULL),
  m_hInstance(NULL)
{
}

Window::~Window(void)
{
}

void Window::SetInstance(HINSTANCE hInstance)
{
	m_hInstance = hInstance;
}

BOOL Window::PreCreateWindow()
{
	return FALSE;
}

BOOL Window::Create(wchar_t* szTitle, int x, int y, int  width, int height)
{
	RegisterWndClass();
	PreCreateWindow();

	m_hWnd = CreateWindow(GetWndClassName(), szTitle, WS_OVERLAPPEDWINDOW & ~ WS_THICKFRAME,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, m_hInstance, this);

	if (!m_hWnd)
	{
		return FALSE;
	}

	::MoveWindow(m_hWnd, x, y, width, height, FALSE);

	return TRUE;
}

void Window::Destroy()
{
	::DestroyWindow(m_hWnd);
}

void Window::ShowWindow(BOOL bShow)
{
	if(bShow)
	{
		::ShowWindow(m_hWnd, SW_SHOW);
	}
	else
	{
		::ShowWindow(m_hWnd, SW_HIDE);
	}
}

void Window::UpdateWindow()
{
	::UpdateWindow(m_hWnd);
}

BOOL Window::RegisterWndClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc_s;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= GetWndClassName();
	wcex.hIconSm		= NULL;

	return RegisterClassEx(&wcex);
}

wchar_t* Window::GetWndClassName()
{
	return L"DefaultWindowClass";
}

LRESULT CALLBACK Window::WndProc_s(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Window* pThis = NULL;
	if( uMsg == WM_NCCREATE ) 
	{
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		pThis = static_cast<Window*>(lpcs->lpCreateParams);
		pThis->m_hWnd = hWnd;
		::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LPARAM>(pThis));
	} 
	else 
	{
		pThis = reinterpret_cast<Window*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
// 		if( uMsg == WM_NCDESTROY && pThis != NULL ) 
// 		{
// 			LRESULT lRes = ::CallWindowProc(pThis->m_OldWndProc, hWnd, uMsg, wParam, lParam);
// 			::SetWindowLongPtr(pThis->m_hWnd, GWLP_USERDATA, 0L);
// 			if( pThis->m_bSubclassed ) pThis->Unsubclass();
// 			pThis->m_hWnd = NULL;
// 			pThis->OnFinalMessage(hWnd);
// 			return lRes;
// 		}
		if (pThis)
			return pThis->WndProc(uMsg, wParam, lParam);
	}
// 	if( pThis != NULL ) {
// 		return pThis->HandleMessage(uMsg, wParam, lParam);
//	} 
//	else {
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
//	}
}

LRESULT Window::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return ::DefWindowProc(m_hWnd, uMsg, wParam, lParam);
}

Window::operator HWND() const
{
	return m_hWnd;
}