#include "SPTXT.h"
#include "private/SPTXT_Private.h"
#include "../JFFTXT/JFFTXT.h"
#include "../GLI/GLI.h"
#include "../LST.h"
#include "../private/framework.h"
#include <detours.h>


//////////////////////////////////////////
//
// SPTXT - Spitfire's Text Helper Module
//
//////////////////////////////////////////


#define TEXT_MARGIN 2
#define FRAME_MARGIN (TEXT_MARGIN*0.1f)


BYTE g_bIsModuleInit = FALSE;
void *g_pContext = NULL;

SPTXT_tdstTextInfo g_stTextInfo = { 0 };
SPTXT_tdstTextInfo g_stDefaultTextInfo = { 0, 0, 8, 0xFF, FALSE, FALSE };


int SPTXT_fn_lGetCharHeight( MTH_tdxReal xSize )
{
	MTH_tdxReal size = 15.0f - xSize;
	MTH_tdxReal height = 38.0f - size * 2.5f;
	return (int)height + TEXT_MARGIN + TEXT_MARGIN;
}

int SPTXT_fn_lGetCharWidth( MTH_tdxReal xSize )
{
	MTH_tdxReal size = 15.0f - xSize;
	MTH_tdxReal width = 46.0f - size * 4.0f;
	return (int)width;
}

int SPTXT_fn_lGetFmtStringLength( char const *szFmt, va_list args )
{
	int lSize = vsnprintf(NULL, 0, szFmt, args);
	return lSize + 1;
}

void SPTXT_vDrawString( char *szText, SPTXT_tdstTextInfo *p_stInfo )
{
	JFFTXT_tdstString stDummy = {
		szText,
		p_stInfo->X,
		p_stInfo->Y,
		p_stInfo->xSize,
		p_stInfo->ucAlpha,
		.bHighlight = p_stInfo->bSelected
	};
	MTH2D_tdstVector stTL = { 0 };
	MTH2D_tdstVector stBR = { 0 };

	if ( p_stInfo->bRightAlign )
	{
		JFFTXT_vGetStringExtents(&stDummy, &stTL, &stBR);
		MTH_tdxReal xLength = stBR.x - stTL.x - 2 + FRAME_MARGIN + FRAME_MARGIN;
		stDummy.X -= xLength * 10;
	}

	if ( p_stInfo->bFrame )
	{
		JFFTXT_vGetStringExtents(&stDummy, &stTL, &stBR);

		stTL.x += 1 - FRAME_MARGIN;
		stBR.x -= 1 - FRAME_MARGIN;

		MTH_tdxReal xHeight = SPTXT_fn_lGetCharHeight(stDummy.xSize) * 0.1f;
		stTL.y += 1 - FRAME_MARGIN;
		stBR.y = stTL.y + xHeight;

		MTH_tdxReal xSaveZValue = *GLI_p_fZValueForSprite;
		*GLI_p_fZValueForSprite = 0.998f;
		*GLI_p_bForceAAAColor = 0;

		GLI_vDisplayFrame(&stTL, &stBR, stDummy.ucAlpha * 0.5f, g_pContext);

		*GLI_p_fZValueForSprite = xSaveZValue;
	}

	JFFTXT_vDrawString(g_pContext, &stDummy);
}

void SPTXT_vDrawText( void *pContext )
{
	g_pContext = pContext;

	SPTXT_tdstNodeText *pNode;
	LST_M_DynamicForEach(&g_stTextNodeList, pNode)
	{
		g_stTextInfo = g_stDefaultTextInfo;
		pNode->p_fnCallback(&g_stTextInfo);
	}
}

void SPTXT_vAffiche( void *pContext )
{
	SPTXT_vDrawText(pContext);
	JFFTXT_vAffiche(pContext);
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


ACP_API void SPTXT_vAddTextCallback( SPTXT_tdfnTextCallback p_fnCallback )
{
	SPTXT_tdstNodeText *p_stNode = SPTXT_fn_p_stCreateNode();
	p_stNode->p_fnCallback = p_fnCallback;
}

ACP_API void SPTXT_vRemoveTextCallback( SPTXT_tdfnTextCallback p_fnCallback )
{
	SPTXT_tdstNodeText *pNode;
	LST_M_DynamicForEach(&g_stTextNodeList, pNode)
	{
		if ( pNode->p_fnCallback == p_fnCallback )
		{
			SPTXT_fn_vDeleteNode(pNode);
			break;
		}
	}
}

ACP_API void SPTXT_vPrint( char *szText )
{
	if ( !szText )
		return;
	
	SPTXT_vDrawString(szText, &g_stTextInfo);
}

ACP_API void SPTXT_vNewLine( void )
{
	MTH_tdxReal xHeight = SPTXT_fn_lGetCharHeight(g_stTextInfo.xSize);
	g_stTextInfo.Y += xHeight;
}

ACP_API void SPTXT_vPrintLine( char *szText )
{
	SPTXT_vPrint(szText);
	SPTXT_vNewLine();
}

ACP_API void SPTXT_vPrintFmtLine( char const *szFmt, ... )
{
	va_list args;
	va_start(args, szFmt);

	int lSize = SPTXT_fn_lGetFmtStringLength(szFmt, args);
	char *szBuffer = _alloca(lSize);

	if ( szBuffer )
	{
		vsprintf(szBuffer, szFmt, args);
		SPTXT_vPrintLine(szBuffer);
	}

	va_end(args);
}

ACP_API void SPTXT_vResetTextInfo( SPTXT_tdstTextInfo *p_stInfo )
{
	*p_stInfo = g_stDefaultTextInfo;
}