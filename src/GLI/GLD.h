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

typedef struct GLD_tdstViewport
{
	GLD_tdstViewportAttributes stViewAttrib;
	BOOL bIsLocked;
}
GLD_tdstViewport;

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

	HANDLE hFullScreenModeWnd; // 640
	HANDLE hNormalModeWnd; // 480

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



/*
 * Functions
 */

#define GLD_M_hGetSpecificTo3D(p_stVpt) ((GLI_tdstSpecificAttributesFor3D *)(p_stVpt)->p_vSpecificToXD)


ACP_FUNC BOOL (*GLD_bCreateDevice)(GLD_tdstDeviceAttributes pstDevAttrib, GLD_tdhDevice *phDev);
ACP_FUNC GLD_tdstViewport* (*GLD_pGetViewport)(GLD_tdhDevice hDev, GLD_tdhViewport hOldVP);
ACP_FUNC BOOL (*GLD_bSwapDeviceMode)(GLD_tdhDevice hDev, BOOL _bCanBeWindowed);
ACP_FUNC BOOL (*GLD_bFlipDeviceWithSynchro)(void);
ACP_FUNC void (*GLD_vGetFrontBufferIn24BitsAA)(GLD_tdhDevice _hGLDDevice, GLD_tdhViewport _hGLDViewport, unsigned long _lWidth, unsigned long _lHeight, unsigned char *p_lBufferDst);
ACP_FUNC BOOL (*GLD_bRequestWriteToViewport2D)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP, GLD_tdstViewportAttributes *pstViewAttrib, BOOL *pbCanWrite);
ACP_FUNC BOOL (*GLD_bWriteToViewportFinished2D)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP);
ACP_FUNC void (*GLD_fn_vChangeViewPortPercent)(
	unsigned long _ulMode,
	unsigned long _ulWhat,
	unsigned long _ulWidth,
	unsigned long _ulHeight,
	unsigned long _ulClipTop,
	unsigned long _ulClipLeft,
	unsigned long _ulClipBottom,
	unsigned long _ulClipRight,
	int _iPosX,
	int _iPosY
);

ACP_FUNC BOOL (*GLD_bRequestWriteToViewport)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP, GLD_tdstViewportAttributes* pstViewAttrib, BOOL* pbCanWrite);
ACP_FUNC BOOL (*GLD_bWriteToViewportFinished)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP);