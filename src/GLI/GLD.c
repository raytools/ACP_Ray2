/****************************************************************************
*
* GLD - Graphics Library for Display
*
****************************************************************************/

#include "GLD.h"

/*
 * Variables
 */
char *const GLD_g_cEraseBackground = OFFSET(0x49F81C);

/*
 * Functions
 */
BOOL (*GLD_bFlipDeviceWithSynchro)(void) = OFFSET(0x420f50);
void (*fn_vChangeViewPortPercent)(unsigned long	_ulMode,
	unsigned long	_ulWhat,
	unsigned long	_ulWidth,
	unsigned long	_ulHeight,
	unsigned long	_ulClipTop,
	unsigned long	_ulClipLeft,
	unsigned long	_ulClipBottom,
	unsigned long	_ulClipRight,
	int				_iPosX,
	int				_iPosY
	) = OFFSET(0x404e70);

ACP_FUNC GLD_tdstViewport* (*GLD_pGetViewport)(GLD_tdhDevice hDev, GLD_tdhViewport hOldVP) = OFFSET(0x420430);
ACP_FUNC BOOL (*GLD_bSwapDeviceMode)(GLD_tdhDevice hDev, BOOL _bCanBeWindowed) = OFFSET(0x421300);
ACP_FUNC void (*GLD_vGetFrontBufferIn24BitsAA)(GLD_tdhDevice _hGLDDevice, GLD_tdhViewport _hGLDViewport, unsigned long _lWidth, unsigned long _lHeight, unsigned char* p_lBufferDst) = OFFSET(0x42bd20);
ACP_FUNC BOOL(*GLD_bRequestWriteToViewport2D)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP, GLD_tdstViewportAttributes* pstViewAttrib, BOOL* pbCanWrite) = OFFSET(0x420be0);
ACP_FUNC BOOL(*GLD_bWriteToViewportFinished2D)(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP) = OFFSET(0x420cc0);
ACP_FUNC BOOL(*GLD_bCreateDevice)(GLD_tdstDeviceAttributes pstDevAttrib, GLD_tdhDevice* phDev) = OFFSET(0x420520);