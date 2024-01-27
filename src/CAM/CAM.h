/****************************************************************************
 *
 * CAM - Camera module (technically part of GAM)
 *
 ****************************************************************************/

#pragma once

#include "CAM_Def.h"

#include "HIE/HIE_Def.h"
#include "MTH.h"
#include "apidef.h"


#define CAM_C_ucNbOfCheckedSpeeds	8

enum CAM_tde_uwIAFlags_
{
	CAM_C_IAFlags_NoDynamicTarget				= 0x0001,
	CAM_C_IAFlags_NoAverageMoveTgtPerso			= 0x0002,
	CAM_C_IAFlags_NoParseCutAngle				= 0x0004,
	CAM_C_IAFlags_NoVisibility					= 0x0008,
	CAM_C_IAFlags_NoVisibilityWithDynHie		= 0x0010,
	CAM_C_IAFlags_NoDynChangeTheta				= 0x0020,
	CAM_C_IAFlags_NoShiftUntilPosReached		= 0x0040,
	CAM_C_IAFlags_NoDynSpeed					= 0x0080,
	CAM_C_IAFlags_User							= 0x0FFF,

	CAM_C_IAFlags_TargetIsAlreadyComputed		= 0x1000,
	CAM_C_IAFlags_PositionIsAlreadyComputed		= 0x2000,
	CAM_C_IAFlags_RefAxisIsAlreadyComputed		= 0x4000
};
typedef unsigned short CAM_tde_uwIAFlags;

enum CAM_tde_ucVolIAFlags_
{
	CAM_C_VolIAFlags_CurrentAlreadyCopiedInWork	= 0x01,
	CAM_C_VolIAFlags_InitJustCopiedInCurrent	= 0x02,
	CAM_C_VolIAFlags_CameraNotMove				= 0x04
};
typedef unsigned char CAM_tde_ucVolIAFlags;

enum CAM_tde_ucPerIAFlags_
{
	CAM_C_PerIAFlags_ShowInfo					= 0x01,
	CAM_C_PerIAFlags_VisibilityCopied			= 0x02,
	CAM_C_PerIAFlags_NoShift					= 0x04,
	CAM_C_PerIAFlags_ConstraintMoveVisFailure	= 0x08,
	CAM_C_PerIAFlags_PosIsForced				= 0x10
};
typedef unsigned char CAM_tde_ucPerIAFlags;


typedef enum CAM_tdeListViewport
{
	CAM_e_NoViewport = 0,
	CAM_e_MainViewport,
	CAM_e_SecondaryViewport
}
CAM_tdeListViewport;

typedef enum CAM_tdeCameraStates
{
	CAM_e_State_GoToOptimal,
	CAM_e_State_GoToComputedOptimal,
	CAM_e_State_FailureVisibility,
	CAM_e_State_FailureVisibilityWithoutCut,
	CAM_e_TempState_GhostMode,
	CAM_e_TempState_ApexMode
}
CAM_tdeCameraStates;


typedef struct CAM_tdstAveragePosition
{
	MTH3D_tdstVector a_CheckedSpeed[CAM_C_ucNbOfCheckedSpeeds];
	MTH3D_tdstVector a_CheckedPos[CAM_C_ucNbOfCheckedSpeeds];
	MTH_tdxReal a_CheckedTime[CAM_C_ucNbOfCheckedSpeeds];
}
CAM_tdstAveragePosition;

typedef struct CAM_tdstSightAxisSystem
{
	MTH3D_tdstVector SightAxis;
	MTH3D_tdstVector FirstComplementaryAxis;
	MTH3D_tdstVector SecondComplementaryAxis;
}
CAM_tdstSightAxisSystem;

typedef struct CAM_tdstInternalStructurCineinfo
{
	/* offset to add to the position of the new position (point looked at by the camera) */
	MTH3D_tdstVector stShiftTarget;
	/* offset to add to the position of the target */
	MTH3D_tdstVector stShiftPos;

	MTH_tdxReal xDistMin;
	MTH_tdxReal xDistMax;
	MTH_tdxReal xBoundDistMin;
	MTH_tdxReal xBoundDistMax;

	/* rotation around the Z axis */
	MTH_tdxReal xAngleAlpha;
	MTH_tdxReal xAngleShiftAlpha;

	/* rotation around the X axis */
	MTH_tdxReal xAngleTheta;
	MTH_tdxReal xAngleShiftTheta;

	MTH_tdxReal xLinearSpeed;
	MTH_tdxReal xLinearIncreaseSpeed;
	MTH_tdxReal xLinearDecreaseSpeed;

	MTH_tdxReal xAngularSpeed;
	MTH_tdxReal xAngularIncreaseSpeed;
	MTH_tdxReal xAngularDecreaseSpeed;

	MTH_tdxReal xTargetSpeed;
	MTH_tdxReal xTargetIncreaseSpeed;
	MTH_tdxReal xTargetDecreaseSpeed;

	MTH_tdxReal xFocal;

	/* camera altitude */
	MTH_tdxReal xZMin;
	MTH_tdxReal xZMax;

	HIE_tdstSuperObject *hSuperObjectTargeted;
	HIE_tdstSuperObject *hSecondSuperObjectTargeted;

	/* camera flags */
	unsigned short uwDNMFlags;
	CAM_tde_uwIAFlags uwIAFlags;

	CAM_tdeListViewport eTypeOfViewport;

	char cChannel;
	ACP_tdxBool bIsActive;
}
CAM_tdstInternalStructurCineinfo;


typedef struct CAM_tdstCineinfo
{
	CAM_tdstInternalStructurCineinfo *hInit;
	CAM_tdstInternalStructurCineinfo *hCurrent;
	CAM_tdstInternalStructurCineinfo *hVisibility;
	CAM_tdstInternalStructurCineinfo *hWork;

	/* for visibility */
	MTH3D_tdstVector stLastFailedOrigin;
	MTH3D_tdstVector stLastFailedWanted;

	MTH3D_tdstVector stForceTarget;
	MTH3D_tdstVector stForcePosition;
	MTH3D_tdstVector stForceRefAxisY;
	MTH3D_tdstVector stForceRefAxisZ;

	MTH_tdxReal xApexRatio; /* used when a second superobject is defined */

	MTH_tdxReal xLastDeltaCut;

	CAM_tdeCameraStates eState;

	MTH_tdxReal xCounter1; /* test better pos counter */
	MTH_tdxReal xCounter2; /* test visibility counter */
	MTH_tdxReal xCounter3; /* time we can't see target */
	MTH_tdxReal xCounter4; /* time the camera is not moving */

	/* private camera flags */
	CAM_tde_ucVolIAFlags ucVolIAFlags; /* volatile (reset each frame) */
	CAM_tde_ucPerIAFlags ucPerIAFlags; /* persistent */

	char cLastCutAngleSens;

	CAM_tdstAveragePosition stAveragePosition;
	CAM_tdstSightAxisSystem stSightAxisSystem;

	ACP_tdxBool bCanDoBestPos;
}
CAM_tdstCineinfo;


/*
 * Functions
 */

ACP_FUNC void (*CAM_fn_vUpdateTargetPosition)( CAM_tdstCineinfo *hCineinfo );

ACP_FUNC void (*CAM_fn_vInitCompleteCineinfo)( CAM_tdstCineinfo *hCineinfo );
ACP_FUNC void (*CAM_fn_vSetCineinfoWorkFromCurrent)( CAM_tdstCineinfo *hCineinfo );
