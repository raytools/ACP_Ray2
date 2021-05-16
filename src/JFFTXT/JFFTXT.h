#pragma once

#include <MTH.h>
#include <apidef.h>


////////////////////////////
//
// JFFTXT - 2D Text Module
//
////////////////////////////


typedef struct JFFTXT_tdstString JFFTXT_tdstString;

struct JFFTXT_tdstString
{
	char *szText;
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	BYTE ucAlpha;

	BYTE _field_11;
	BYTE bHighlight;
	BYTE eOptions;
	DWORD ulHighlightedChar;
	BYTE ucHighlightColor;
};

typedef enum JFFTXT_tdeOptions
{
	JTO_FADE_IN = 1 << 0,
	JTO_FADE_OUT = 1 << 1,
	JTO_CHAR_HIGHLIGHT = 1 << 2,
	JTO_BG_FRAME = 1 << 3,
	JTO_HIGHLIGHT_COLOR = 1 << 4
} JFFTXT_tdeOptions;

typedef enum JFFTXT_tdeExtendParam
{
	JTE_ALPHA,
	JTE_HIGHLIGHT,
	JTE_FADE_IN,
	JTE_FADE_OUT,
	JTE_SIZE,
	JTE_CHAR_HIGHLIGHT,
	JTE_BG_FRAME,
	JTE_HIGHLIGHT_COLOR
} JFFTXT_tdeExtendParam;


ACP_API extern void (*JFFTXT_vAffiche)( void *pContext );
ACP_API extern void (*JFFTXT_vDrawString)( void *pContext, JFFTXT_tdstString *p_stString );

ACP_API extern void (*JFFTXT_vAddText)( DWORD ulTextId, MTH3D_tdstVector *p_stPos, char *szText, MTH_tdxReal xAlpha );
ACP_API extern void (*JFFTXT_vExtendText)( DWORD ulTextId, JFFTXT_tdeExtendParam ulParamToChange, MTH_tdxReal xNewValue );
