#include "SPTXT.h"
#include <JFFTXT/JFFTXT.h>
#include <GLI/GLI.h>
#include <framework.h>
#include <detours.h>


//////////////////////////////////////////
//
// SPTXT - Spitfire's Text Helper Module
//
//////////////////////////////////////////


typedef struct SPTXT_tdstNodeStaticString SPTXT_tdstNodeStaticString;
typedef struct SPTXT_tdstNodeDynamicString SPTXT_tdstNodeDynamicString;


struct SPTXT_tdstNodeStaticString
{
	SPTXT_tdstNodeStaticString *p_stNext;
	SPTXT_tdstNodeStaticString *p_stPrevious;
	SPTXT_tdstString *p_stData;
};

struct SPTXT_tdstNodeDynamicString
{
	SPTXT_tdstNodeDynamicString *p_stNext;
	SPTXT_tdstNodeDynamicString *p_stPrevious;
	SPTXT_tdstDynamicString *p_stData;
};


#define TEXT_MARGIN 2
#define FRAME_MARGIN (TEXT_MARGIN*0.1f)

BYTE g_bIsModuleInit = FALSE;

SPTXT_tdstNodeStaticString *g_llStaticStrings = NULL;
SPTXT_tdstNodeDynamicString *g_llDynamicStrings = NULL;


void SPTXT_vDrawStaticStrings( void *pContext )
{
	for ( SPTXT_tdstNodeStaticString *pItem = g_llStaticStrings; pItem; pItem = pItem->p_stNext )
	{
		// TODO
	}
}

void SPTXT_vDrawDynamicStrings( void *pContext )
{
	for ( SPTXT_tdstNodeDynamicString *pItem = g_llDynamicStrings; pItem; pItem = pItem->p_stNext )
	{
		// TODO
	}
}

void SPTXT_vAffiche( void *lpContext )
{
	SPTXT_vDrawStaticStrings(lpContext);
	SPTXT_vDrawDynamicStrings(lpContext);

	JFFTXT_vAffiche(lpContext);
}

ACP_API void SPTXT_vInit( void )
{
	if ( g_bIsModuleInit )
		return;

	DetourTransactionBegin();
	DetourAttach((PVOID *)&JFFTXT_vAffiche, (PVOID)SPTXT_vAffiche);
	DetourTransactionCommit();

	g_bIsModuleInit = TRUE;
}

ACP_API void SPTXT_vDeInit( void )
{
	if ( !g_bIsModuleInit )
		return;

	DetourTransactionBegin();
	DetourDetach((PVOID *)&JFFTXT_vAffiche, (PVOID)SPTXT_vAffiche);
	DetourTransactionCommit();

	g_bIsModuleInit = FALSE;
}

ACP_API void SPTXT_vAddStaticString()
{
	// TODO
}

ACP_API void SPTXT_vAddDynamicString()
{
	// TODO
}

void SPTXT_vDrawString( SPTXT_tdstString *p_stString, void *pContext )
{
	JFFTXT_tdstString stDummy = {
		p_stString->szText,
		p_stString->X,
		p_stString->Y,
		p_stString->xSize,
		p_stString->ucAlpha,
		0
	};
	MTH2D_tdstVector stTL = { 0 };
	MTH2D_tdstVector stBR = { 0 };

	if ( p_stString->bRightAlign )
	{
		JFFTXT_vGetStringExtents(&stDummy, &stTL, &stBR);
		float xLength = stBR.x - stTL.x - 2 + FRAME_MARGIN + FRAME_MARGIN;

		stDummy.X -= xLength * 10;
	}

	if ( p_stString->bFrame )
	{
		JFFTXT_vGetStringExtents(&stDummy, &stTL, &stBR);

		stTL.x += 1 - FRAME_MARGIN;
		stBR.x -= 1 - FRAME_MARGIN;

		float xHeight = DBGTXT_fn_lGetCharHeight() * 0.1f;
		stTL.y += 1 - FRAME_MARGIN;
		stBR.y = stTL.y + xHeight;

		float xSaveZValue = *GLI_p_fZValueForSprite;
		*GLI_p_fZValueForSprite = 0.998f;
		*GLI_p_bForceAAAColor = 0;

		GLI_vDisplayFrame(&stTL, &stBR, stDummy.ucAlpha * 0.5f, pContext);

		*GLI_p_fZValueForSprite = xSaveZValue;
	}

	JFFTXT_vDrawString(pContext, &stDummy);
}

void SPTXT_vPrint( SPTXT_tdstString *p_stString )
{
	SPTXT_vDrawString(p_stString, pContext);
}

void DBGTXT_vPrintLine( char *szText )
{
	if ( szText )
	{
		SPTXT_vPrint(szText);
	}
	g_stDummy.Y += DBGTXT_fn_lGetCharHeight();
}

void DBGTXT_vPrintFmtLine( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);

	int lSize = DBGTXT_fn_lGetFmtStringLength(szFmt, args);
	char *szBuffer = _malloca(lSize);

	if ( szBuffer )
	{
		vsprintf(szBuffer, szFmt, args);
		DBGTXT_vPrintLine(szBuffer);

		_freea(szBuffer);
	}

	va_end(args);
}
