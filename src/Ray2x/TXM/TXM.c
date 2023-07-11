/****************************************************************************
 *
 * TXM - Texture Manager module
 *
 ****************************************************************************/

#include "TXM.h"
#include "private/TXM_List.h"
#include "GLI/GLI_Ext.h"
#include "Ray2x/FHK/FHK.h"
#include "private/framework.h"


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define LOG_USE_MODULE
#include "Ray2x/LOG/LOG.h"

#define TXM_C_szModuleVersion	"TXM V1.0.0"
#define TXM_C_szModuleName		"Texture Manager"
#define TXM_C_szModuleDate		__DATE__

LOG_tdxModuleId TXM_g_xModuleId;

#ifdef _DEBUG
unsigned long g_ulTXMTotalMem = 0;
#endif
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


BOOL g_bTXMModuleInit = FALSE;
LST_M_DynamicAnchorTo(TXM_tdstTextureEntry) g_stTextureList;

void (*TXM_GLI_vComputeTextures)( void ) = NULL;


TXM_tdstTextureEntry * TXM_fn_pstNewTextureEntry( void )
{
	TXM_tdstTextureEntry *pstEntry = malloc(sizeof(TXM_tdstTextureEntry));
	if ( !pstEntry )
		return NULL;

#ifdef _DEBUG
	g_ulTXMTotalMem += sizeof(TXM_tdstTextureEntry);
#endif

	ZeroMemory(&pstEntry->stTexture, sizeof(GLI_tdstTexture));
	pstEntry->ucType = 0;
	pstEntry->uwRefCount = 0;
	LST_M_DynamicInitElement(pstEntry);

	LST_M_DynamicAddTail(&g_stTextureList, pstEntry);
	return pstEntry;
}

void TXM_fn_vDeleteTextureEntry( TXM_tdstTextureEntry *pstEntry )
{
	LST_M_DynamicIsolate(pstEntry);
	free(pstEntry);

#ifdef _DEBUG
	g_ulTXMTotalMem -= sizeof(TXM_tdstTextureEntry);
#endif
}

TXM_tdstTextureEntry * TXM_fn_pstFindTextureEntry( char const *szGFName, unsigned char ucType )
{
	TXM_tdstTextureEntry *pstEntry;
	LST_M_DynamicForEach(&g_stTextureList, pstEntry)
	{
		if ( (pstEntry->ucType == ucType || ucType == TXM_C_AnyType)
			 && !_stricmp(pstEntry->stTexture.szFileName, szGFName) )
			return pstEntry;
	}

	return NULL;
}

GLI_tdstTexture * TXM_fn_hLoadTextureGF( char const *szGFName )
{
	if ( !szGFName )
		return NULL;

	TXM_tdstTextureEntry *pstEntry = TXM_fn_pstFindTextureEntry(szGFName, TXM_C_GFTexture);
	if ( !pstEntry )  /* create new texture if not found */
	{
		pstEntry = TXM_fn_pstNewTextureEntry();
		pstEntry->ucType = TXM_C_GFTexture;

		if ( !GLI_fn_bReadTextureGF(&pstEntry->stTexture, szGFName) )  /* could not read GF file? */
		{
			LOG_M_vLogWarningEx(TXM_g_xModuleId, "Could not load GF texture", szGFName);
			TXM_fn_vDeleteTextureEntry(pstEntry);
			return NULL;
		}
	}
	/* all good, increase ref count and return */
	pstEntry->uwRefCount++;

#ifdef _DEBUG
	char szErr[256];
	char szErr2[64];
	sprintf(szErr, "Requested texture '%s'", szGFName);
	sprintf(szErr2, "\tType: %u\n\tRefCount: %u", pstEntry->ucType, pstEntry->uwRefCount);
	LOG_M_vLogInfoEx(TXM_g_xModuleId, szErr, szErr2);
#endif

	return &pstEntry->stTexture;
}

BOOL TXM_fn_bUnLoadTexture( GLI_tdstTexture const *hTexture )
{
	TXM_tdstTextureEntry *pstEntry;
	LST_M_DynamicForEach(&g_stTextureList, pstEntry)  /* find the texture in the list */
	{
		if ( &pstEntry->stTexture != hTexture )
			continue;

		pstEntry->uwRefCount--;
		if ( pstEntry->uwRefCount == 0 )  /* no refs, delete */
			TXM_fn_vDeleteTextureEntry(pstEntry);

		return TRUE;
	}
	/* not in list */
	return FALSE;
}


void TXM_fn_vComputeTextures( void )
{
	TXM_tdstTextureEntry *pstEntry;
	LST_M_DynamicForEach(&g_stTextureList, pstEntry)
	{
		GLI_fn_vLoadTextureInTableWithChannel(&pstEntry->stTexture, GLI_C_TXMMemoryChannel);
	}

	TXM_GLI_vComputeTextures();

#ifdef _DEBUG
	char szErr[256];
	sprintf(
		szErr,
		"\tTotal textures loaded:  %u\n"
		"\tTXM textures:           %d\n"
		"\tMemory used by TXM:     %u B",
		*GLI_g_ulNumberOfLoadedTexture,
		LST_M_DynamicGetNbOfElements(&g_stTextureList),
		g_ulTXMTotalMem
	);
	LOG_M_vLogInfoEx(TXM_g_xModuleId, "TXM memory debug:", szErr);
#endif
}

void TXM_fn_vInit( void )
{
	if ( g_bTXMModuleInit )
		return;

	LOG_fn_vInit();
	TXM_g_xModuleId = LOG_fn_xRegisterModule(TXM_C_szModuleVersion, TXM_C_szModuleName, TXM_C_szModuleDate);

	LST_M_DynamicInitAnchor(&g_stTextureList);

	TXM_GLI_vComputeTextures = GLI_vComputeTextures;
	FHK_M_lCreateHook(&TXM_GLI_vComputeTextures, TXM_fn_vComputeTextures);

#ifdef _DEBUG
	g_ulTXMTotalMem += sizeof(g_stTextureList);
#endif

	g_bTXMModuleInit = TRUE;
}
