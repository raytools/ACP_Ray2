/****************************************************************************
 * TXM - texture list
 ****************************************************************************/

#pragma once

#include "GLI/GLI.h"
#include "LST.h"


#define TXM_C_AnyType		0
#define TXM_C_GFTexture		1
#define TXM_C_CntTexture	2


typedef struct TXM_tdstTextureEntry TXM_tdstTextureEntry;
LST_M_DynamicListDecl(TXM_tdstTextureEntry);

typedef struct TXM_tdstTextureEntry
{
	GLI_tdstTexture stTexture;
	unsigned char ucType;
	unsigned short uwRefCount;
	LST_M_DynamicElementDecl(TXM_tdstTextureEntry)
}
TXM_tdstTextureEntry;


extern LST_M_DynamicAnchorTo(TXM_tdstTextureEntry) g_stTextureList;
