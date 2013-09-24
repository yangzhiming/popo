#include "StdAfx.h"
#include "RenderEngine.h"


/*
只所以这么去抽象，是因为以后可能不用Gdiplus来渲染。
目前暂时考虑直接用Gdiplus来渲染吧
*/

// RenderDevice::RenderDevice(HWND hWnd)
// {
// 
// }
// 
// RenderDevice::~RenderDevice()
// {
// 
// }
// 
// BaseDevice* RenderEngine::CreateDevice(HWND hWnd)
// {
// 	return new RenderDevice(hWnd);
// }
// 
// void RenderDevice::BeginRender()
// {
// 
// }
// 
// void RenderDevice::EndRender()
// {
// 
// }
// 
// void RenderDevice::Clear()
// {
// 
// }