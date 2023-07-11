/****************************************************************************
 *
 * GLI Extensions
 *
 ****************************************************************************/

#include "GLI_Ext.h"
#include "GEO/GEO_Def.h"
#include "FIL/FIL.h"
#include "GAM/GAM.h"
#include "private/framework.h"


void GLI_fn_vSetForcedColor( unsigned char const *a3_Color )
{
	if ( a3_Color )
	{
		*GLI_g_bForceAAAColor = 1;
		GLI_a3_ForcedAAAColor[0] = a3_Color[0];
		GLI_a3_ForcedAAAColor[1] = a3_Color[1];
		GLI_a3_ForcedAAAColor[2] = a3_Color[2];
	}
	else
		*GLI_g_bForceAAAColor = 0;
}


GLI_tdstTexture * GLI_fn_pstFindTexture( char const *szName )
{
	for ( int i = 0; i < GLI_C_lNBMaxOfTextures; ++i )
	{
		unsigned long ulChannel = GLI_gs_aDEFTableOfTextureMemoryChannels[i];
		GLI_tdstTexture *pTexture = GLI_gs_aDEFTableOfTextureAlreadyRead[i];

		if ( ulChannel != GLI_C_TEXIsUnallocated && !_stricmp(pTexture->szFileName, szName) )
			return pTexture;
	}

	return NULL;
}

GLI_tdstTexture * GLI_fn_pstFindTextureWithChannel( char const *szName, unsigned long ulMemChannel )
{
	for ( int i = 0; i < GLI_C_lNBMaxOfTextures; ++i )
	{
		unsigned long ulChannel = GLI_gs_aDEFTableOfTextureMemoryChannels[i];
		GLI_tdstTexture *pTexture = GLI_gs_aDEFTableOfTextureAlreadyRead[i];

		if ( ulChannel == ulMemChannel && !_stricmp(pTexture->szFileName, szName) )
			return pTexture;
	}

	return NULL;
}

BOOL GLI_fn_bReadTextureGF( GLI_tdstTexture *p_stTexture, char const *szGFName )
{
	/* set textures folder name */
	strcpy(GLI_fn_szGetPathOfTexture(), "Textures");

	char szFilePath[MAX_PATH];
	sprintf(szFilePath, "%s\\%s", GLI_fn_szGetPathOfTexture(), szGFName);
	strcpy(strrchr(szFilePath, '.'), ".gf");

	FILE *pFile = fopen(szFilePath, "rb");
	if ( !pFile )
		return FALSE;

	strcpy(p_stTexture->szFileName, szGFName);

	/* read texture format */
	FIL_tdstRealGFFileHeader stHeader = { 0 };
	fread(&stHeader, sizeof(FIL_tdstRealGFFileHeader), 1, pFile);
	fclose(pFile);

	char *pExt = strrchr(szGFName, '.');

	if ( !_stricmp(pExt, ".tga") )
		p_stTexture->ulTextureCaps = GLI_C_Tex_lTGATexture;
	else if ( !_stricmp(pExt, ".bmp") )
		p_stTexture->ulTextureCaps = GLI_C_Tex_lBMPTexture;

	if ( stHeader.ucBpp == 1 )
		p_stTexture->ulTextureCaps |= GLI_C_Tex_lPaletteTexture;
	if ( stHeader.ucBpp == 4 )
		p_stTexture->ulTextureCaps |= GLI_C_Tex_lAlphaTexture;

	p_stTexture->lTextureQuality = GLI_C_TEX_QNORMAL;

	p_stTexture->uwWidth = p_stTexture->uwRealWidth = (WORD)stHeader.ulWidth;
	p_stTexture->uwHeight = p_stTexture->uwRealHeight = (WORD)stHeader.ulHeight;

	/* cycling mode (tile/mirror) */
	if ( strstr(szGFName, "_txy") )
		p_stTexture->ucCyclingMode = GLI_C_lCyclingUV;
	else if ( strstr(szGFName, "_tx") )
		p_stTexture->ucCyclingMode = GLI_C_lCyclingU;
	else if ( strstr(szGFName, "_ty") )
		p_stTexture->ucCyclingMode = GLI_C_lCyclingV;
	else if ( strstr(szGFName, "_mxy") )
		p_stTexture->ucCyclingMode = GLI_C_lMirrorUV;
	else if ( strstr(szGFName, "_mx") )
		p_stTexture->ucCyclingMode = GLI_C_lMirrorU;
	else if ( strstr(szGFName, "_my") )
		p_stTexture->ucCyclingMode = GLI_C_lMirrorV;

	if ( p_stTexture->ucCyclingMode & GLI_C_lMirrorU )
	{
		p_stTexture->uwWidth *= 2;
		p_stTexture->uwRealWidth *= 2;
	}

	if ( p_stTexture->ucCyclingMode & GLI_C_lMirrorV )
	{
		p_stTexture->uwHeight *= 2;
		p_stTexture->uwRealHeight *= 2;
	}

	/* other flags */
	if ( strstr(szGFName, "_ad") )
		p_stTexture->ulTextureCaps |= GLI_C_Tex_lAddTransparencyTexture;

	if ( strstr(szGFName, "_aaa") )
		p_stTexture->ulTextureCaps |= GLI_C_Tex_lAAATexture;

	if ( strstr(szGFName, "_nz") )
		p_stTexture->ulTextureCaps |= GLI_C_Tex_lNZTexture | GLI_C_Tex_lNZFilteredTexture;

	return TRUE;
}

void GLI_fn_vLoadTextureInTableWithChannel( GLI_tdstTexture *p_stTexture, unsigned long ulChannel )
{
	/* TODO: may be necessary to use GLI_gs_lNumberOfTextureToCreate */
	for ( int i = 0; i < GLI_C_lNBMaxOfTextures; ++i )
	{
		if ( GLI_gs_aDEFTableOfTextureMemoryChannels[i] == GLI_C_TEXIsUnallocated )
		{
			GLI_gs_aDEFTableOfTextureAlreadyRead[i] = p_stTexture;
			GLI_gs_aDEFTableOfTextureMemoryChannels[i] = ulChannel;
			break;
		}
	}
}

void GLI_fn_vLoadTextureInTable( GLI_tdstTexture *p_stTexture )
{
	GLI_fn_vLoadTextureInTableWithChannel(p_stTexture, GLI_C_CustomMemoryChannel);
}


void GLI_fn_vInitMaterialDefaults( GLI_tdstMaterial *p_stMaterial )
{
	p_stMaterial->stAmbient.xR = 0.1f;
	p_stMaterial->stAmbient.xG = 0.1f;
	p_stMaterial->stAmbient.xB = 0.1f;

	p_stMaterial->stDiffuse.xR = 0.8f;
	p_stMaterial->stDiffuse.xG = 0.8f;
	p_stMaterial->stDiffuse.xB = 0.8f;

	p_stMaterial->stColor.xR = 1.0f;
	p_stMaterial->stColor.xG = 1.0f;
	p_stMaterial->stColor.xB = 1.0f;

	p_stMaterial->p_stTexture = NULL;
	p_stMaterial->ulMaterialType = 0xFFFFFFFF;
}


void GLI_fn_vDraw2DSpriteWithUV(
	MTH_tdxReal xXMin,
	MTH_tdxReal xXMax,
	MTH_tdxReal xYMin,
	MTH_tdxReal xYMax,
	MTH_tdxReal xUMin,
	MTH_tdxReal xUMax,
	MTH_tdxReal xVMin,
	MTH_tdxReal xVMax,
	GLI_tdstMaterial *hMaterial
	)
{
	GLI_tdstAligned2DVector a4_st2DVertex[5];
	GLI_tdst2DUVValues a4_stUVVertex[5];
	GEO_tdstColor stLocalColor = { 0 };

	if ( xXMin < (*GLI_BIG_GLOBALS)->fXMinClipping || xXMax > (*GLI_BIG_GLOBALS)->fXMaxClipping )
		return;

	stLocalColor.xG = stLocalColor.xB = stLocalColor.xR = 0.0f;
	hMaterial->stAmbient = stLocalColor;
	stLocalColor.xG = stLocalColor.xB = stLocalColor.xR = 1.0f;
	hMaterial->stDiffuse = stLocalColor;
	stLocalColor.xG = stLocalColor.xB = stLocalColor.xR = 0.0f;
	hMaterial->stSpecular = stLocalColor;
	hMaterial->lSpecularExponent = 0;

	a4_st2DVertex[0].xX = (float)(long)xXMin;
	a4_st2DVertex[0].xY = (float)(long)xYMin;
	a4_st2DVertex[0].xOoZ = 1.0f;
	a4_st2DVertex[1].xX = (float)(long)xXMax;
	a4_st2DVertex[1].xY = (float)(long)xYMin;
	a4_st2DVertex[1].xOoZ = 1.0f;
	a4_st2DVertex[2].xX = (float)(long)xXMax;
	a4_st2DVertex[2].xY = (float)(long)xYMax;
	a4_st2DVertex[2].xOoZ = 1.0f;
	a4_st2DVertex[3].xX = (float)(long)xXMin;
	a4_st2DVertex[3].xY = (float)(long)xYMax;
	a4_st2DVertex[3].xOoZ = 1.0f;

	a4_stUVVertex[0].xU = xUMin;
	a4_stUVVertex[0].xV = xVMin;
	a4_stUVVertex[1].xU = xUMax;
	a4_stUVVertex[1].xV = xVMin;
	a4_stUVVertex[2].xU = xUMax;
	a4_stUVVertex[2].xV = xVMax;
	a4_stUVVertex[3].xU = xUMin;
	a4_stUVVertex[3].xV = xVMax;

	(*GLI_BIG_GLOBALS)->hCurrentMaterial = hMaterial;
	(*GLI_BIG_GLOBALS)->hCurrentMaterial->ulMaterialType = 0xFFFFFFFF - GLI_C_Mat_lIsTestingBackface;
	(*GLI_BIG_GLOBALS)->lCurrentDrawMask = 0xFFFFFFFF - GLI_C_Mat_lIsTestingBackface;
	(*GLI_BIG_GLOBALS)->lHierachDrawMask = 0xFFFFFFFF - GLI_C_Mat_lIsTestingBackface;

	GLI_vDoMaterialSelection(*GLI_BIG_GLOBALS);

	if ( GLI_g_bForceAAAColor )
	{
		/* Keep computed alpha */
		(*GLI_BIG_GLOBALS)->ulColorInitForSprite &= 0xff000000;
		/* Force color */
		(*GLI_BIG_GLOBALS)->ulColorInitForSprite |=
			GLI_a3_ForcedAAAColor[0] << 16 | GLI_a3_ForcedAAAColor[1] << 8 | GLI_a3_ForcedAAAColor[2];
	}

	//GLI_DRV_vSendSpriteToClipWithUV(a4_st2DVertex, a4_stUVVertex, 1.0f / GLI_C_xZClippingNear, GLI_BIG_GLOBALS);
	(*GLI_DRV_vSendSpriteToClipWithUV)(a4_st2DVertex, (MTH_tdxReal*)a4_stUVVertex, *GLI_g_fZValueForSprite, *GLI_BIG_GLOBALS);
}

void GLI_fn_vDraw2DSpriteWithZValueAndAlpha(
	MTH2D_tdstVector *p_stTopLeft,
	MTH2D_tdstVector *p_stBottomRight,
	MTH_tdxReal xAlpha,
	MTH_tdxReal xZValue,
	GLI_tdstMaterial *hMaterial
	)
{
	MTH_tdxReal xSaveZValue = *GLI_g_fZValueForSprite;
	MTH_tdxReal xSaveAlpha = GLI_fn_xGetGlobalAlpha();

	*GLI_g_fZValueForSprite = xZValue;
	GLI_vSetGlobalAlpha(xAlpha);

	GLI_vDraw2DSpriteWithPercent(
		&GAM_g_stEngineStructure->stFixViewportAttr,
		p_stTopLeft->x, p_stTopLeft->y, p_stBottomRight->x, p_stBottomRight->y, hMaterial
	);

	*GLI_g_fZValueForSprite = xSaveZValue;
	GLI_vSetGlobalAlpha(xSaveAlpha);
}
