/****************************************************************************
 *
 * Base type definitions for ACP
 *
 ****************************************************************************/

#pragma once


#ifndef NULL
	#define NULL	((void*)0)
#endif
#ifndef FALSE
	#define FALSE	0
#endif
#ifndef TRUE
	#define TRUE	1
#endif

typedef int BOOL;
typedef unsigned char ACP_tdxBool; /* size of ACP_tdxBool : 1 byte */

typedef signed short ACP_tdxIndex;
typedef unsigned long ACP_tdxAddress;

typedef void *HANDLE;
typedef HANDLE W32_HWND;

typedef struct W32_RECT
{
	long left;
	long top;
	long right;
	long bottom;
}
W32_RECT;

typedef struct W32_POINT
{
	long x;
	long y;
}
W32_POINT;
