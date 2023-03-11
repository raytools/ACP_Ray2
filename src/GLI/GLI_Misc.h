/****************************************************************************
 * GLI - Misc structs
 ****************************************************************************/

#pragma once

#include "GEO/GEO_Def.h"
#include "MTH.h"
#include "basedef.h"
#include "apidef.h"


typedef struct GLI_tdstAligned3DVector
{
	MTH_tdxReal xX;
	MTH_tdxReal xY;
	MTH_tdxReal xZ;
	MTH_tdxReal ALIGN;
}
GLI_tdstAligned3DVector;

typedef struct GLI_tdstAligned2DVector
{
	MTH_tdxReal xX;
	MTH_tdxReal xY;
	MTH_tdxReal xOoZ;
	unsigned long ulPackedColor;
}
GLI_tdstAligned2DVector;

typedef struct GLI_tdst2DUVValues
{
	MTH_tdxReal xU;
	MTH_tdxReal xV;
}
GLI_tdst2DUVValues;

typedef struct GLI_tdstFogParams
{
	MTH_tdxReal xDepthStart;
	MTH_tdxReal xDepthEnd;
	MTH_tdxReal xInfinite;
	MTH_tdxReal xBlendStart;
	MTH_tdxReal xBlendEnd;
	GEO_tdstColor stColor;
}
GLI_tdstFogParams;
