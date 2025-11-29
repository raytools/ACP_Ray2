/****************************************************************************
 * GAM - 3d Data MiniStructure
 ****************************************************************************/

#pragma once

#include "GLI/GLI.h"
#include "GMT/GMT.h"
#include "HIE/HIE_Family.h"
#include "POS/POS.h"


typedef struct GAM_tdstCouple
{
	unsigned short wChild;
	unsigned short wFather;
}
GAM_tdstCouple;

typedef struct GAM_tdstPLA_Hierarchy
{
	unsigned long ulNbOfCouples;
	GAM_tdstCouple *d_stCouples;
}
GAM_tdstPLA_Hierarchy;

typedef struct GAM_tdstFrame3d
{
	/* tdstElement3d */ void *p_stArrayOfElts3d;
	MTH3D_tdstMatrix *p_stAngularSpeedMatrix;
	MTH3D_tdstVector *p_stLinearSpeedVector;

	GAM_tdstPLA_Hierarchy stHierarchy;

	/* tdstAnim3d */ void *p_stAnim;
	unsigned short uwFrameNumber;
	unsigned char ucMatrixUpdated;
	unsigned char ucCacheEntry;
}
GAM_tdstFrame3d;

typedef struct GAM_tdstAnim3d
{
	unsigned short		uwNumberOfFrames;
	unsigned char		ucFrameRate;
	unsigned char		ucMaxNumberOfElements;

	struct tdstEvent_ *d_stAnimEvent;

	MTH3D_tdstVector stOffsetMatrix;

	/*tdstMorphData*/ void *d_stMorphDataArray;
	unsigned short		uwNumOfA3dGENERAL;
	unsigned char		ucNumberOfEvents;
	unsigned char		ucUnused;		/* alignment*/
} GAM_tdstAnim3d;

typedef struct GAM_tdst3dData
{
	HIE_tdstState *h_InitialState;
	HIE_tdstState *h_CurrentState;
	HIE_tdstState *h_FirstStateOfAction;

	HIE_tdstObjectsTablesList *h_InitialObjectsTable;
	HIE_tdstObjectsTablesList *h_CurrentObjectsTable;

	HIE_tdstFamilyList *h_Family;

	POS_tdstCompletePosition stGLIObjectMatrix;
	POS_tdstCompletePosition *p_stGLIObjectAbsoluteMatrix;

	/* Information about the current animation */
	unsigned short uwCurrentFrame;
	unsigned char  ucRepeatAnimation;
	unsigned char  ucNextEvent;
	unsigned char *d_ucEventActivation; // Cpt used to launch events

	GAM_tdstCouple *p_stCurrentHieCouples;
	unsigned short wCurrentHieNbCouples;
	unsigned short wSizeOfArrayOfElts3d;

	HIE_tdstState *h_StateInLastFrame; // For AI
	HIE_tdstState *h_WantedState;
	unsigned short uwForcedFrame;
	unsigned char ucFlagEndState;
	unsigned char ucFlagEndOfAnim;

	/* CHN_tdxHandleToChannelArray */ void *hArrayOfChannels;
	unsigned long ulNumberOfChannels;
	/* CHN_tdxHandleToChannel */ void *hFirstActiveChannel;
	GAM_tdstFrame3d stFrame3d;

	/* CHN_tdxHandleToMorphList */ void *hMorphChannelList;
	unsigned long ulStartTime; // Start time for this animation (used to compute next frame number)

	unsigned long ulTimeDelay; // Extra time beyond the current animation == time delay between (end of animation time) and (next computed frame time)
	unsigned long ulTimePreviousFrame;
	short sLastFrame; // Number of the last played frame for this animation (used to compute speeds)

	unsigned char bStateJustModified;
	unsigned char bSkipCurrentFrame;

	GMT_tdstGameMaterial *p_stShadowMaterial;
	GLI_tdstTexture *p_stShadowTexture;

	MTH_tdxReal xShadowScaleX;
	MTH_tdxReal xShadowScaleY;
	short xShadowQuality;

	unsigned short uwNbEngineFrameSinceLastMechEvent;

	unsigned char ucFrameRate;
	unsigned char ucFlagModifState;

	long lDrawMaskInit;
	long lDrawMask;

	long lLastComputeFrame;
	MTH3D_tdstVector stLastEventGlobalPosition;

	unsigned char bAnimMatrixChanged;
	unsigned char ucUserEventFlags;
	unsigned char ucBrainComputationFrequency;
	char cBrainCounter;
	unsigned short uwBrainMainCounter;

	unsigned char ucTransparency;

	unsigned char ucLightComputationFrequency;
	char cLightCounter;
	MTH3D_tdstVector stSHWDeformationVector;
	MTH_tdxReal xSHWHeight;
}
GAM_tdst3dData;


/*
 * Functions
 */

ACP_FUNC void (*GAM_fn_v3dDataAlloc)( HIE_tdstEngineObject *p_stObject );
ACP_FUNC ACP_tdxBool(*PLA_fn_bSetNewState)(HIE_tdstSuperObject *p_stSuperObject, HIE_tdstState *h_WantedState, ACP_tdxBool _bForce, ACP_tdxBool _bHandleSkippedEventsIfRelevant);