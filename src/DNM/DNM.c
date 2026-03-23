/****************************************************************************
*
* DNM - Dynamics Module
*
****************************************************************************/

#include "DNM.h"


DNM_tdstDynamics* (*DNM_p_stDynamicsCameraMechanics)(
	DNM_tdstDynamics* _p_stDynamics,
	HIE_tdstSuperObject* _hSupObj,
	DNM_tdstParsingDatas* _p_stParsingDatas,
	void* _h_MecIdCard,
	MTH_tdxReal						_xDT) = OFFSET(0x4359d0);

DNM_tdstDynamics* (*MEC_p_stDynamicsBaseMechanics)(
	DNM_tdstDynamics* _p_stDynamics,
	HIE_tdstSuperObject* _hSupObj,
	DNM_tdstParsingDatas* _p_stParsingDatas,
	void* _h_MecIdCard,
	MTH_tdxReal						_xDT) = OFFSET(0x431ad0);

MTH_tdxReal (*DNM_fn_xComputeAngleOfPerso)( HIE_tdstSuperObject *pSuperObjPerso ) = OFFSET(0x416370);

void (*DNM_fn_vDynamAlloc)(HIE_tdstEngineObject* p_stObject) = OFFSET(0x412be0);
void (*DNM_fn_vDynamCopyClone)(HIE_tdstEngineObject* p_stObjectDest, HIE_tdstEngineObject* p_stObjectSrc) = OFFSET(0x412ff0);