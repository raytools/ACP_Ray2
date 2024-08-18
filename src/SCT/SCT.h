/****************************************************************************
 *
 * SCT - Sector module
 *
 ****************************************************************************/

#pragma once

#include "SCT_Def.h"
#include "HIE/HIE_Def.h"
#include "GLI/GLI_Def.h"
#include "SND/SND_Def.h"
#include "LST.h"
#include "MTH.h"
#include "apidef.h"


LST_M_DynamicListDecl(SCT_tdstListOfSOCharacters);
LST_M_DynamicListDecl(SCT_tdstListOfDNMLights);
LST_M_StaticListDecl(SCT_tdstListOfStaticLights);
LST_M_StaticListDecl(SCT_tdstListOfSOSectorsInGraphicInteraction);
LST_M_StaticListDecl(SCT_tdstListOfSOSectorsInSoundInteraction);
LST_M_StaticListDecl(SCT_tdstListOfSOSectorsInInteraction);
LST_M_StaticListDecl(SCT_tdstListOfSoundEvent);

typedef struct SCT_tdstListOfSOCharacters
{
	HIE_tdstSuperObject *hPointerOfCharacter;
	LST_M_DynamicElementDecl(SCT_tdstListOfSOCharacters)
}
SCT_tdstListOfSOCharacters;

typedef struct SCT_tdstListOfDNMLights
{
	GLI_tdstLight *hDNMLights;
	LST_M_DynamicElementDecl(SCT_tdstListOfDNMLights)
}
SCT_tdstListOfDNMLights;

typedef struct SCT_tdstListOfStaticLights
{
	GLI_tdstLight *hStaticLights;
	LST_M_StaticElementDecl(SCT_tdstListOfStaticLights)
}
SCT_tdstListOfStaticLights;

typedef struct SCT_tdstListOfSOSectorsInGraphicInteraction
{
	short wLevelOfDetail;
	char cDisplayMode;
	HIE_tdstSuperObject *hPointerOfSectorSO;
	LST_M_StaticElementDecl(SCT_tdstListOfSOSectorsInGraphicInteraction)
}
SCT_tdstListOfSOSectorsInGraphicInteraction;

typedef struct SCT_tdstListOfSOSectorsInSoundInteraction
{
	HIE_tdstSuperObject *hPointerOfSectorSO;
	long lVolume;
	LST_M_StaticElementDecl(SCT_tdstListOfSOSectorsInSoundInteraction)
}
SCT_tdstListOfSOSectorsInSoundInteraction;

typedef struct SCT_tdstListOfSOSectorsInInteraction
{
	HIE_tdstSuperObject *hPointerOfSectorSO;
	LST_M_StaticElementDecl(SCT_tdstListOfSOSectorsInInteraction)
}
SCT_tdstListOfSOSectorsInInteraction;

typedef struct SCT_tdstListOfSoundEvent
{
	HIE_tdstSuperObject *hPointerOfSectorSO;
	SND_tduRefEvt *uSoundEvent;
	LST_M_StaticElementDecl(SCT_tdstListOfSoundEvent)
}
SCT_tdstListOfSoundEvent;


typedef struct SCT_tdstSector
{
	LST_M_DynamicAnchorTo(SCT_tdstListOfSOCharacters) stListOfCharacters;
	LST_M_StaticAnchorTo(SCT_tdstListOfStaticLights) stListOfStaticLights;
	LST_M_DynamicAnchorTo(SCT_tdstListOfDNMLights) stListOfDNMLights;

	LST_M_StaticAnchorTo(SCT_tdstListOfSOSectorsInGraphicInteraction) stListOfSectorsInGraphicInteraction;
	LST_M_StaticAnchorTo(SCT_tdstListOfSOSectorsInInteraction) stListOfSectorsInCollisionInteraction;
	LST_M_StaticAnchorTo(SCT_tdstListOfSOSectorsInInteraction) stListOfSectorsInActivityInteraction;
	LST_M_StaticAnchorTo(SCT_tdstListOfSOSectorsInSoundInteraction) stListOfSectorsInSoundInteraction;
	LST_M_StaticAnchorTo(SCT_tdstListOfSoundEvent) stListOfSoundEvent;

	MTH3D_tdstVector a_stMinMaxPoints[2];
	MTH_tdxReal xZFar; /* all objects that are further from camera than this value are clipped */

	ACP_tdxBool bVirtual;
	char cCameraType;
	char cCounter;
	char cPriority;

	void *pSkyVisualMaterial;
	unsigned char ucFogIntensity;
}
SCT_tdstSector;

typedef struct SCT_tdstSectInfo
{
	HIE_tdstSuperObject *hCurrentSector;
	SCT_tdstListOfSOCharacters *hNodeInSector;
	MTH3D_tdstVector stPreviousPosition;
}
SCT_tdstSectInfo;


/*
 * Functions
 */

ACP_FUNC void (*SCT_fn_vRemoveObjectInSectorList)( HIE_tdstSuperObject *hCharacter );
