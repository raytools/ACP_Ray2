/****************************************************************************
*
* GEO - Common Geometry module
*
****************************************************************************/

#include "GEO.h"


void (*GEO_vCreateGeometricObject)(
	GEO_tdstGeometricObject **p_hObject,
	ACP_tdxIndex xNbPoints,
	ACP_tdxIndex xNbElements
	) = OFFSET(0x41CD30);

void (*GEO_vCreateElementSpheres)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex *p_hElement,
	ACP_tdxIndex xNbSpheres
	) = OFFSET(0x41E610);

void (*GEO_vSetPointOfObject)(
	GEO_tdstGeometricObject *hObject,
	MTH3D_tdstVector *p_stPoint,
	ACP_tdxIndex xIndexOfPoint
	) = OFFSET(0x41CDA0);

void (*GEO_vSetCenterPointOfIndexedSphere)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xNumberOfSphere,
	ACP_tdxIndex xIndexOfPoint
	) = OFFSET(0x41E670);

void (*GEO_vSetRadiusOfIndexedSphere)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xNumberOfSphere,
	MTH_tdxReal xRadius
	) = OFFSET(0x41E6C0);

void (*GEO_vSetGameMaterialOfIndexedSphere)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xNumberOfSphere,
	GMT_tdstGameMaterial *hMaterial
	) = OFFSET(0x41E740);

void (*GEO_vSetMaterialOfIndexedSphere)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xNumberOfSphere,
	GLI_tdstMaterial *hMaterial
	) = OFFSET(0x41E710);
