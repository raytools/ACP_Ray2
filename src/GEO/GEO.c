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

void (*GEO_vCreateElementIndexedTriangles)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex *p_hElement,
	ACP_tdxIndex xNbFaces,
	ACP_tdxIndex xNbElementUV
	) = OFFSET(0x41DCA0);


void (*GEO_vGetPointOfObject)(
	GEO_tdstGeometricObject *hObject,
	MTH3D_tdstVector *p_stPoint,
	ACP_tdxIndex xIndexOfPoint
	) = OFFSET(0x41CDD0);

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


void (*GEO_vSetUVOfIndexedTriangles)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xIndexOfUV,
	GLI_tdst2DUVValues *p_stUV
	) = OFFSET(0x41E2E0);

void (*GEO_vSetGameMaterialOfIndexedTriangles)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	GMT_tdstGameMaterial *hMaterial
	) = OFFSET(0x41E340);

void (*GEO_vSetFaceOfIndexedTriangles)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xIndexOfFace,
	ACP_tdxIndex xPoint1,
	ACP_tdxIndex xPoint2,
	ACP_tdxIndex xPoint3
	) = OFFSET(0x41E240);

void (*GEO_vSetIndexedUVOfFaceOfIndexedTriangles)(
	GEO_tdstGeometricObject *hObject,
	ACP_tdxIndex hElement,
	ACP_tdxIndex xIndexOfFace,
	ACP_tdxIndex xUV1,
	ACP_tdxIndex xUV2,
	ACP_tdxIndex xUV3
	) = OFFSET(0x41E290);


void (*GEO_vEndModifyObject)( GEO_tdstGeometricObject *hObject ) = OFFSET(0x41D1A0);
