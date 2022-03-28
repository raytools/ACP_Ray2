/****************************************************************************
 *
 * SPTXT - Spitfire's Text Helper Module
 *
 ****************************************************************************/

#pragma once

#include "SPTXT_Const.h"
#include "MTH.h"
#include "apidef.h"


typedef struct SPTXT_tdstTextInfo
{
	MTH_tdxReal X;
	MTH_tdxReal Y;
	MTH_tdxReal xSize;
	unsigned char ucAlpha;
	unsigned char bFrame;
	unsigned char bRightAlign;
	unsigned char bSelected;
}
SPTXT_tdstTextInfo;

typedef void (CALLBACK *SPTXT_tdfnTextCallback)( SPTXT_tdstTextInfo *p_stString );


/*
 * Functions
 */

ACP_API void SPTXT_vInit( void );
ACP_API void SPTXT_vDeInit( void );

ACP_API void SPTXT_vAddTextCallback( SPTXT_tdfnTextCallback p_fnCallback );
ACP_API void SPTXT_vRemoveTextCallback( SPTXT_tdfnTextCallback p_fnCallback );

ACP_API void SPTXT_vPrint( char *szText );
ACP_API void SPTXT_vNewLine( void );
ACP_API void SPTXT_vPrintLine( char *szText );
ACP_API void SPTXT_vPrintFmtLine( char const *szFmt, ... );
ACP_API void SPTXT_vResetTextInfo( SPTXT_tdstTextInfo *p_stInfo );
