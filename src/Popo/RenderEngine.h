#ifndef _RENDER_ENGINE_H_
#define _RENDER_ENGINE_H_

//#include "Singleton.h"

// class BaseDevice;
// 
// class RenderEngine : public SingletonT<RenderEngine>
// {
// public:
// 	BaseDevice* CreateDevice(HWND hWnd);
// };
// 
// class BaseDevice
// {
// public:
// 	BaseDevice() {}
// 	virtual ~BaseDevice() {}
// 
// 	virtual void BeginRender() = 0;
// 	virtual void EndRender() = 0;
// 	virtual void Clear() = 0;
// 
// };
// 
// class RenderDevice : public BaseDevice
// {
// public:
// 	RenderDevice(HWND hWnd);
// 	virtual ~RenderDevice();
// 
// 	Gdiplus::Graphics* operator ->() { return m_pGraph;}
// 
// 	virtual void BeginRender();
// 	virtual void EndRender();
// 	virtual void Clear();
// 
// protected:
// 	Gdiplus::Graphics* m_pGraph;
// };

#endif // _RENDER_ENGINE_H_