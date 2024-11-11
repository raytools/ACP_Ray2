/****************************************************************************
 *
 * GLD - Graphics Library for Display
 *
 ****************************************************************************/

#pragma once

#include "GLI_Def.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


typedef short GLD_tdhDevice;
typedef short GLD_tdhViewport;

typedef struct GLD_tdstViewportAttributes
{
	unsigned long dwInitialHeight;
	unsigned long dwInitialWidth;
	unsigned long dwHeight;
	unsigned long dwWidth;

	unsigned long dwTopInPix;
	unsigned long dwBottomInPix;
	unsigned long dwLeftInPix;
	unsigned long dwRightInPix;
	unsigned long dwTopInPixForClip;
	unsigned long dwBottomInPixForClip;
	unsigned long dwLeftInPixForClip;
	unsigned long dwRightInPixForClip;

	unsigned long dwWidthInPercent;
	unsigned long dwHeightInPercent;

	unsigned long dwClipTopInPix;
	unsigned long dwClipBottomInPix;
	unsigned long dwClipLeftInPix;
	unsigned long dwClipRightInPix;
	unsigned long dwClipTopInPerMille;
	unsigned long dwClipBottomInPerMille;
	unsigned long dwClipLeftInPerMille;
	unsigned long dwClipRightInPerMille;

	long lOffsetPosX;
	long lOffsetPosY;

	char *p_cVirtualScreen;
	long lPitch;

	void *p_vSpecificToXD;

	GLD_tdhDevice hDevice;
	GLD_tdhViewport hViewport;
}
GLD_tdstViewportAttributes;

typedef struct GLD_tdstDeviceAttributes
{
	unsigned long dwHeight;
	unsigned long dwWidth;

	MTH_tdxReal xPixelDimensionX;
	MTH_tdxReal xPixelDimensionY;

	char *p_cVirtualScreen;
	long lPitch;
	short *p_sZBuffer;

	unsigned long dwFullScreenModeX;
	unsigned long dwFullScreenModeY;
	unsigned long dwFullScreenModeBpp;

	HANDLE hFullScreenModeWnd;
	HANDLE hNormalModeWnd;

	BOOL bFullScreen;
	unsigned int uiTypeDriver;

	W32_POINT pClientOnPrimary;
	W32_RECT rtClientRect;
	W32_RECT rtWindowRect;
}
GLD_tdstDeviceAttributes;


/*
 * Variables
 */

ACP_VAR char *const GLD_g_cEraseBackground;


#define GLD_M_hGetSpecificTo3D(p_stVpt) ((GLI_tdstSpecificAttributesFor3D *)(p_stVpt)->p_vSpecificToXD)
