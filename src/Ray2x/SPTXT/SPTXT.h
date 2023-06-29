/****************************************************************************
 *
 * SPTXT - Spitfire's Text Helper Module
 *
 ****************************************************************************/

#pragma once

#include "SPTXT_Const.h"
#include "MTH.h"
#include "Ray2x/apidefx.h"


typedef struct SPTXT_tdstTextInfo
{
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	unsigned char ucAlpha;
	ACP_tdxBool bFrame;
	ACP_tdxBool bRightAlign;
	ACP_tdxBool bSelected;

	BOOL bWantExtents;
	MTH_tdxReal xExtentX;
	MTH_tdxReal xExtentY;
}
SPTXT_tdstTextInfo;

typedef void (CALLBACK *SPTXT_tdfnTextCallback)( SPTXT_tdstTextInfo *p_stString );


/*
 * Functions
 */

ACPX_API void SPTXT_vInit( void );
ACPX_API void SPTXT_vDeInit( void );

ACPX_API void SPTXT_vAddTextCallback( SPTXT_tdfnTextCallback p_fnCallback );
ACPX_API void SPTXT_vRemoveTextCallback( SPTXT_tdfnTextCallback p_fnCallback );

ACPX_API void SPTXT_vPrint( char *szText );
ACPX_API void SPTXT_vNewLine( void );
ACPX_API void SPTXT_vPrintLine( char *szText );
ACPX_API void SPTXT_vPrintFmtLine( char const *szFmt, ... );
ACPX_API void SPTXT_vResetTextInfo( SPTXT_tdstTextInfo *p_stInfo );

ACPX_API long SPTXT_fn_lGetCharHeight( MTH_tdxReal xSize );
ACPX_API long SPTXT_fn_lGetCharWidth( MTH_tdxReal xSize );
