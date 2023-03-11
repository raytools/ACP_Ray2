/****************************************************************************
 * GEO - Elements
 ****************************************************************************/

#pragma once

#include "GEO_Def.h"
#include "GMT/GMT_Def.h"
#include "GLI/GLI_Misc.h"
#include "MTH.h"
#include "basedef.h"


enum GEO_tdeElementType_
{
	GEO_C_xElementNULL = 0,
	GEO_C_xElementIndexedTriangles = 1,
	GEO_C_xElementFaceMapDescriptors = 2,
	GEO_C_xElementSprites = 3,
	GEO_C_xElementTMeshes = 4,
	GEO_C_xElementPoints = 5,
	GEO_C_xElementLines = 6,
	GEO_C_xElementSpheres = 7,
	GEO_C_xElementAlignedBoxes = 8,
	GEO_C_xElementCones = 9
};
typedef ACP_tdxIndex GEO_tdeElementType;

typedef struct GEO_tdstElementIndexedTriangles
{
	GMT_tdstGameMaterial *hMaterial;

	ACP_tdxIndex xNbFaces;
	ACP_tdxIndex xNbElementUV;
	GEO_tdstTripledIndex *d_stListOfFacesTripled;
	GEO_tdstTripledIndex *d_stListOfFacesTripledIndexUV;
	MTH3D_tdstVector *d_stListOfFacesNormals;
	GLI_tdst2DUVValues *d_stListOfElementUV;

	ACP_tdxIndex *d_stListOfIndexUsedByThisElement;
	ACP_tdxIndex xNbOfIndexUsed;

	ACP_tdxIndex xIndexOfParallelBox;
}
GEO_tdstElementIndexedTriangles;
