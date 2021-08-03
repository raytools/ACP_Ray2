#pragma once

#include "../MTH.h"
#include "../apidef.h"


///////////////////////////////////////
//
// GLD - Graphics Library for Display
//
///////////////////////////////////////


typedef struct GLD_tdstViewportAttributes GLD_tdstViewportAttributes;


struct GLD_tdstViewportAttributes
{
	DWORD dwInitialHeight;
	DWORD dwInitialWidth;
	DWORD dwHeight;
	DWORD dwWidth;
	DWORD dwTopInPix;
	DWORD dwBottomInPix;
	DWORD dwLeftInPix;
	DWORD dwRightInPix;
	DWORD dwTopInPixForClip;
	DWORD dwBottomInPixForClip;
	DWORD dwLeftInPixForClip;
	DWORD dwRightInPixForClip;
	DWORD dwWidthInPercent;
	DWORD dwHeightInPercent;
	DWORD dwClipTopInPix;
	DWORD dwClipBottomInPix;
	DWORD dwClipLeftInPix;
	DWORD dwClipRightInPix;
	DWORD dwClipTopInPerMille;
	DWORD dwClipBottomInPerMille;
	DWORD dwClipLeftInPerMille;
	DWORD dwClipRightInPerMille;
	int iOffsetPosX;
	int iOffsetPosY;
	char *p_cVirtualScreen;
	int lPitch;
	void *p_vSpecificToXD;
	WORD hDevice;
	WORD hViewport;
};
