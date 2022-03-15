#pragma once

#include "../GEO/GEO.h"
#include "../basedef.h"
#include "../apidef.h"


/*****************************************************************************
 *
 * PO - Physical objects module
 *
 *****************************************************************************/


typedef struct PO_tdstPhysicalCollSet
{
	GEO_tdstGeometricObject *hZdm;
	GEO_tdstGeometricObject *hZdd;
	GEO_tdstGeometricObject *hZde;
	GEO_tdstGeometricObject *hZdr;
}
PO_tdstPhysicalCollSet;

typedef struct PO_tdstPhysicalObject
{
	GEO_tdstVisualSet *hVisualSet;
	PO_tdstPhysicalCollSet *hCollideSet;
	GEO_tdstBoundingSphere *hBoundingVolume;
}
PO_tdstPhysicalObject;

typedef struct PO_tdstInstantiatedPhysicalObject
{
	PO_tdstPhysicalObject *hPhysicalObject;
	GEO_tdxHandleToRadiosity hRadiosity;
}
PO_tdstInstantiatedPhysicalObject;