/****************************************************************************
 *
 * JFFTXT - 2D Text Module
 *
 ****************************************************************************/

#pragma once

#include "MTH.h"
#include "apidef.h"


typedef struct JFFTXT_tdstString
{
	char *szText;
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	unsigned char ucTransparency;

	unsigned char bFrozenDisplay_unused;
	unsigned char bWaveEffect;
	unsigned char eOther;
	long lEffectParameter;
	unsigned char ucForcedColor;
}
JFFTXT_tdstString;


#define JFFTXT_C_FadeIn			0x01
#define JFFTXT_C_FadeOut		0x02
#define JFFTXT_C_SelectChar		0x04
#define JFFTXT_C_AutoFrame		0x08
#define JFFTXT_C_ForcedColor	0x10

typedef enum JFFTXT_tdeExtendParam
{
	JFFTXT_E_Transparency,
	JFFTXT_E_WaveEffect,
	JFFTXT_E_FadeIn,
	JFFTXT_E_FadeOut,
	JFFTXT_E_Size,
	JFFTXT_E_SelectChar,
	JFFTXT_E_AutoFrame,
	JFFTXT_E_ForcedColor
}
JFFTXT_tdeExtendParam;


ACP_FUNC void (*JFFTXT_vAffiche)( void *pContext );
ACP_FUNC void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstString *p_stString );

ACP_FUNC void (*JFFTXT_vAddText)( unsigned long ulTextId, MTH3D_tdstVector *p_stPos, char *szText, MTH_tdxReal xAlpha );
ACP_FUNC void (*JFFTXT_vExtendText)( unsigned long ulTextId, JFFTXT_tdeExtendParam ulParamToChange, MTH_tdxReal xNewValue );
ACP_FUNC void (*JFFTXT_vGetStringExtents)( JFFTXT_tdstString *p_stString, MTH2D_tdstVector *p_stTopLeft, MTH2D_tdstVector *p_stBottomRight );

ACP_FUNC void (*JFFTXT_vGetSizeValues)( float xSize, long *dx, long *dy, long *cx, long *cy );
ACP_FUNC long (*JFFTXT_lGetStringLength)( unsigned char *pText, long dx );