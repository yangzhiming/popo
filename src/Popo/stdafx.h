// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <GdiPlus.h>

//stl
#include <xstring>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#ifdef _DEBUG
	#define ASSERT(exp)   assert(exp)
#else
	#define ASSERT(exp)   ((VOID)0);
#endif

using namespace Gdiplus;


// TODO: reference additional headers your program requires here
