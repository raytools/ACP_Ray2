/****************************************************************************
 *
 * HIE - Object Hierarchy
 *
 ****************************************************************************/

#pragma once

#include "HIE_Def.h"
#include "HIE_Const.h"
#include "HIE_StdGame.h"
#include "HIE_Family.h"

#include "AI/AI_Def.h"
#include "DNM/DNM_Def.h"
#include "GEO/GEO_Def.h"
#include "GLI/GLI_Def.h"
#include "PO/PO.h"
#include "SCT/SCT.h"
#include "POS/POS.h"
#include "LST.h"
#include "MTH.h"
#include "apidef.h"


typedef union HIE_tduLinkedObject
{
	HIE_tdstSuperObject *p_stSuperObject;
	HIE_tdstEngineObject *p_stCharacter;
	HIE_tdstEngineObject *p_stActor; /* for convenience */
	SCT_tdstSector *p_stSector;
	GEO_tdstGeometricObject *p_stGeometricObject;
	PO_tdstPhysicalObject *p_stPhysicalObject;
	PO_tdstInstantiatedPhysicalObject *p_stInstantiatedPhysicalObject;
	GLI_tdstLight *p_stLight;
	void* p_Void;
}
HIE_tduLinkedObject;

typedef struct HIE_tdstSuperObject
{
	HIE_tdeTypeOfObject ulType;
	HIE_tduLinkedObject hLinkedObject;

	LST_M_DynamicParentDecl(HIE_tdstSuperObject)
	LST_M_DynamicChildDecl(HIE_tdstSuperObject, HIE_tdstSuperObject)

	POS_tdstCompletePosition *p_stLocalMatrix;
	POS_tdstCompletePosition *p_stGlobalMatrix;

	long lLastComputeFrame;
	long lDrawModeMask;
	HIE_tdeSpoFlags ulFlags;

	void *pBoundingVolume;
	MTH_tdxReal fTransparenceLevel;
}
HIE_tdstSuperObject;

typedef struct HIE_tdstEngineObject /* aka: Perso, Actor, Character */
{
	// TODO: replace void pointers
	void *h3dData;
	HIE_tdstStandardGame *hStandardGame;
	DNM_tdstDynam *hDynam;
	AI_tdstBrain *hBrain;
	void *hCineInfo;
	void *hCollSet;
	void *hMSWay;
	void *hMSLight;
	SCT_tdstSectInfo *hSectInfo;
	void *hMicro;
	void *hMSPrtSrc;
	void *hMSSound;
	void *hAnimEffect;
	void *hMSMagnet;
}
HIE_tdstEngineObject;

typedef struct HIE_tdstAlwaysActiveCharacter
{
	HIE_tdstSuperObject *hAlwActSuperObject;
	LST_M_DynamicElementDecl(HIE_tdstAlwaysActiveCharacter)
	//unsigned char bDynamicAlwaysActive;
}
HIE_tdstAlwaysActiveCharacter;

LST_M_DynamicListDecl(HIE_tdstAlwaysActiveCharacter);


/*
 * Functions
 */

ACP_FUNC void (*HIE_fn_vChangeFather)( HIE_tdstSuperObject *p_stSpo, HIE_tdstSuperObject *p_stNewFather, unsigned char bFirstChild );
