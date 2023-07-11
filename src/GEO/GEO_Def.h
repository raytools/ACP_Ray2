/****************************************************************************
 * Type definitions for GEO module
 ****************************************************************************/

#pragma once

#include "basedef.h"


/* Constant for no element parallel boxes */
#define GEO_C_xNoParallelBox ((ACP_tdxIndex)-1)

/* memory channels */
#define GEO_C_FixMemoryChannel 1
#define GEO_C_LevelMemoryChannel 2


typedef float GEO_tdxColorValue;
typedef void *GEO_tdxHandleToRadiosity;

typedef struct GEO_tdstGeometricObject GEO_tdstGeometricObject;
typedef struct GEO_tdstVisualSet GEO_tdstVisualSet;

typedef struct GEO_tdstParallelBox GEO_tdstParallelBox;
typedef struct GEO_tdstBoundingSphere GEO_tdstBoundingSphere;


typedef struct GEO_tdstColor
{
	GEO_tdxColorValue xR;
	GEO_tdxColorValue xG;
	GEO_tdxColorValue xB;
	GEO_tdxColorValue xA;
}
GEO_tdstColor;

typedef struct GEO_tdstDoubledIndex
{
	ACP_tdxIndex a2_xIndex[2];
}
GEO_tdstDoubledIndex;

typedef struct GEO_tdstTripledIndex
{
	ACP_tdxIndex a3_xIndex[3];
}
GEO_tdstTripledIndex;
