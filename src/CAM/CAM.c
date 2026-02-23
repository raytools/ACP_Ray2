/****************************************************************************
*
* CAM - Camera module (technically part of GAM)
*
****************************************************************************/

#include "CAM.h"

AI_tdstNodeInterpret* (*CAM_fn_p_stUpdatePosition)(HIE_tdstSuperObject* _hSuperObjPerso, AI_tdstNodeInterpret* p_stTree) = OFFSET(0x47da40);
void (*CAM_fn_vUpdateTargetPosition)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x413E30);

void (*CAM_fn_vInitCompleteCineinfo)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x413DB0);
void (*CAM_fn_vSetCineinfoWorkFromCurrent)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x4140A0);
void (*CAM_fn_vCameraManagement)() = OFFSET(0x40bad0);
long (*CAM_lHaveITakeSThgIntoTheMug)(DNM_tdstMecObstacle* _p_stResultObstacle, HIE_tdstSuperObject* _p_stSupObj, POS_tdstCompletePosition* _p_stStartPosition, POS_tdstCompletePosition* _p_stEndPosition) = OFFSET(0x434390);
DNM_tdstMecObstacle* (*DNM_p_stObstacleCameraObstacle)(DNM_tdstMecObstacle* _p_stObstacle, DNM_tdstDynamics* _p_stDynamics, DNM_tdstParsingDatas* _p_stExternData, HIE_tdstSuperObject* _hSupObj,
	MTH3D_tdstVector* _p_stWantedPosition, MTH3D_tdstVector* _p_stNewPosition, MTH_tdxReal _xDT) = OFFSET(0x434660);
DNM_tdstMecObstacle* (*DNM_p_stDynamicsCameraUpdate)(DNM_tdstDynamics* _p_stDynamics, DNM_tdstParsingDatas* _p_stExternData, HIE_tdstSuperObject* _hSupObj, DNM_tdstMecObstacle* _p_stObstacle,
	MTH3D_tdstVector* _p_stNewPosition, MTH3D_tdstVector* _p_stNewTarget) = OFFSET(0x435930);

DNM_tdstDynamics* (*DNM_p_stDynamicsCameraParsing) (DNM_tdstDynamics* _p_stDynamics, HIE_tdstSuperObject* _h_SupObj, DNM_tdstParsingDatas* _p_stExternData, void* _h_MecIdCard, MTH_tdxReal _xDT) = OFFSET(0x433d70);

void (*CAM_fn_vInitCameraStructure)(HIE_tdstSuperObject* _hSuperObjPerso, CAM_tdstUpdateCamera* _p_stStruct) = OFFSET(0x474270);
void (*MEC_fn_vUpdateSpeed)(HIE_tdstSuperObject* hSupObj) = OFFSET(0x433210);
void (*CAM_fn_vRemindSpeed)(CAM_tdstCineinfo * _hCineinfo, MTH_tdstMove * _p_Speed) = OFFSET(0x414370);
void (*CAM_fn_vRemindPos)(CAM_tdstCineinfo * _hCineinfo, MTH_tdstMove * _p_Pos) = OFFSET(0x4143b0);
void (*CAM_fn_vRemindTime)(CAM_tdstCineinfo * _hCineinfo, MTH_tdxReal _dt) = OFFSET(0x4143f0);
void (*CAM_fn_vUpdateGeneralCamera)(CAM_tdstUpdateCamera * _p_stStruct) = OFFSET(0x485810);
void (*CAM_fn_vSendParametersToParsing)(CAM_tdstUpdateCamera * _p_stStruct) = OFFSET(0x474420);


/*
 * Variables
 */

CAM_tdstInternalStructurCineinfo* const CAM_g_stIdeal = OFFSET(0x4e9280);

char* const CAM_g_cCanTestStatic = OFFSET(0x4a544c);
char* const CAM_g_cRefAxisIsAlreadyComputed = OFFSET(0x4e92fd);
char* const CAM_g_cNoDynChangeTheta = OFFSET(0x4e92fc);
char* const CAM_g_cJustBetterPos = OFFSET(0x04b9c2c);

CAM_tdstCameraConstants* const CAM_g_stCameraConstants = OFFSET(0x4ff660);
CAM_tdstCameraConstants* const CAM_g_stCameraCopyConstants = OFFSET(0x4ff6e0);

HIE_tdstSuperObject** const g_hOldTargetedPerso = OFFSET(0x4b9c14);