/****************************************************************************
 *
 * GEO - Common Geometry module
 *
 ****************************************************************************/

#pragma once

#include "GEO_Def.h"
#include "GEO_Elem.h"
#include "GMT/GMT_Def.h"
#include "GLI/GLI_Def.h"
#include "MTH.h"
#include "apidef.h"


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
	GEO_tdeElementType *d_xListOfElementsTypes;
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


/*
 * Functions
 */

ACP_FUNC void (*GEO_vCreateGeometricObject)( GEO_tdstGeometricObject **p_hObject, ACP_tdxIndex xNbPoints, ACP_tdxIndex xNbElements );
ACP_FUNC void (*GEO_vCreateElementSpheres)( GEO_tdstGeometricObject *hObject, ACP_tdxIndex *p_hElement, ACP_tdxIndex xNbSpheres );

ACP_FUNC void (*GEO_vSetPointOfObject)( GEO_tdstGeometricObject *hObject, MTH3D_tdstVector *p_stPoint, ACP_tdxIndex xIndexOfPoint );

ACP_FUNC void (*GEO_vSetCenterPointOfIndexedSphere)( GEO_tdstGeometricObject *hObject, ACP_tdxIndex hElement, ACP_tdxIndex xNumberOfSphere, ACP_tdxIndex xIndexOfPoint );
ACP_FUNC void (*GEO_vSetRadiusOfIndexedSphere)( GEO_tdstGeometricObject *hObject, ACP_tdxIndex hElement, ACP_tdxIndex xNumberOfSphere, MTH_tdxReal xRadius );
ACP_FUNC void (*GEO_vSetGameMaterialOfIndexedSphere)( GEO_tdstGeometricObject *hObject, ACP_tdxIndex hElement, ACP_tdxIndex xNumberOfSphere, GMT_tdstGameMaterial *hMaterial );
ACP_FUNC void (*GEO_vSetMaterialOfIndexedSphere)( GEO_tdstGeometricObject *hObject, ACP_tdxIndex hElement, ACP_tdxIndex xNumberOfSphere, GLI_tdstMaterial *hMaterial );
