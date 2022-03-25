/****************************************************************************
 *
 * GEO - Common Geometry module
 *
 ****************************************************************************/

#pragma once

#include "GEO_Def.h"
#include "GMT/GMT.h"
#include "MTH.h"
#include "apidef.h"


/* Constant for no element parallel boxes */
#define GEO_C_xNoParallelBox ((ACP_tdxIndex)-1)


typedef struct GEO_tdstColor
{
	GEO_tdxColorValue xR;
	GEO_tdxColorValue xG;
	GEO_tdxColorValue xB;
	GEO_tdxColorValue xA;
} GEO_tdstColor;

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


/*
 * Bounding volume: parallel box and sphere
 */

typedef struct GEO_tdstParallelBox
{
	MTH3D_tdstVector stMinPoint;
	MTH3D_tdstVector stMaxPoint;
}
GEO_tdstParallelBox;

typedef struct GEO_tdstBoundingSphere
{
	MTH3D_tdstVector stCenterPoint;
	MTH_tdxReal xRadius;
}
GEO_tdstBoundingSphere;


/*
 * Geometric object
 */

typedef struct GEO_tdstGeometricObject
{
	MTH3D_tdstVector *d_stListOfPoints;
	MTH3D_tdstVector *d_stListOfPointsNormals;
	GMT_tdstGameMaterial **d_p_stListOfPointsMaterial;

	GEO_tdstColor *d_stListOfPointsReceivedLightIntensity;

	/* Elements */
	ACP_tdxIndex *d_xListOfElementsTypes;
	void **d_hListOfElements;

	/* COL_tdstOctree * */ void *p_stOctree;

	/* Edges */
	GEO_tdstDoubledIndex *d_stListOfEdges;
	GMT_tdstGameMaterial **d_p_stListOfEdgesMaterial;

	/* Bounding volume (for element) */
	GEO_tdstParallelBox *d_stListOfParallelBoxes;

	unsigned long ulType;

	ACP_tdxIndex xNbPoints;
	ACP_tdxIndex xNbElements;
	ACP_tdxIndex xNbEdges;
	ACP_tdxIndex xNbParallelBoxes;

	/* Object bounding sphere */
	MTH_tdxReal xBoundingSphereRadius;
	MTH3D_tdstVector xBoundingSphereCenter;
}
GEO_tdstGeometricObject;

typedef struct GEO_tdstVisualSet
{
	MTH_tdxReal xLastDistance;
	ACP_tdxIndex xNbLodDefinitions;
	MTH_tdxReal *d_xThresholdsTable;
	GEO_tdstGeometricObject **d_p_stLodDefinitions;

	GEO_tdxHandleToRadiosity *d_hRLI;
	long lNbOfRLI;
}
GEO_tdstVisualSet;
