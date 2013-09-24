#ifndef _WINDOW_H_
#define _WINDOW_H_

class Window
{
public:
	Window(void);
	~Window(void);

	void SetInstance(HINSTANCE hInstance);

	void ShowWindow(BOOL bShow);
	void UpdateWindow();

	operator HWND() const;
	HWND GetHWnd() const { return m_hWnd; }

	virtual BOOL PreCreateWindow();
	virtual BOOL Create(wchar_t* szTitle, int x, int y, int width,int height);
	virtual void Destroy();

	static LRESULT CALLBACK WndProc_s(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual wchar_t* GetWndClassName();

protected:
	BOOL RegisterWndClass();

protected:
	HWND			m_hWnd;
	HINSTANCE		m_hInstance;
};

#endif