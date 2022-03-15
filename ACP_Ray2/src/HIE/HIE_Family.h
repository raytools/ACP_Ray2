﻿#pragma once

#include "HIE_Def.h"
#include "../GEO/GEO.h"
#include "../LST.h"
#include "../MTH.h"
#include "../apidef.h"


/****************************************************************************
 * FamilyList
 ****************************************************************************/

typedef struct HIE_tdstFamilyList HIE_tdstFamilyList;
typedef struct HIE_tdstObjectsTablesList HIE_tdstObjectsTablesList;

typedef struct HIE_tdstState HIE_tdstState;
typedef struct HIE_tdstTransition HIE_tdstTransition;
typedef struct HIE_tdstProhibit HIE_tdstProhibit;


LST_M_DynamicListDecl(HIE_tdstFamilyList);
LST_M_StaticListDecl(HIE_tdstObjectsTablesList);

LST_M_StaticListDecl(HIE_tdstState);
LST_M_StaticListDecl(HIE_tdstTransition);
LST_M_StaticListDecl(HIE_tdstProhibit);

typedef struct HIE_tdstFamilyList
{
	LST_M_DynamicElementDecl(HIE_tdstFamilyList)

	int lObjectFamilyType;

	LST_M_StaticAnchorTo(HIE_tdstState) stForStateArray;

	HIE_tdstObjectsTablesList *hDefaultObjectsTable;
	LST_M_StaticAnchorTo(HIE_tdstObjectsTablesList) stForObjectsTablesList; 

	GEO_tdstBoundingSphere *hBoundingSphere;
}
HIE_tdstFamilyList;

typedef struct HIE_tdstObjectsTableElement
{
	MTH3D_tdstVector * p_stCustomZoom;
	void *hTarget;

	DWORD ulChannelNumber;
	WORD uwTypeOfTarget;

	BYTE ucPhoneme;
	BYTE ucIntensity;
	BYTE ucExpression;
}
HIE_tdstObjectsTableElement;

typedef struct HIE_tdstObjectsTablesList
{
	LST_M_StaticElementDecl(HIE_tdstObjectsTablesList)

	HIE_tdstObjectsTableElement *d_stObjectsTable;
	HIE_tdstObjectsTableElement *d_stInitObjectsTable;
	WORD uwNumberOfElement;

	WORD wZDxUsed;
}
HIE_tdstObjectsTablesList;


/*
 * State
 */

typedef struct HIE_tdstState
{
	LST_M_StaticElementDecl(HIE_tdstState)

	/* tdstAnim3d * */ void *p_stAnim;

	LST_M_StaticAnchorTo(HIE_tdstTransition) hForTransitionArray;
	LST_M_StaticAnchorTo(HIE_tdstProhibit) hForProhibitArray;

	HIE_tdstState *hNextState;

	void * hLinkedMechanicsIdCard;

	BYTE ucRepeatAnimation;
	char cSpeedAnim;

	BYTE ucTransitionStatusFlag;

	BYTE ucCustomBits;
}
HIE_tdstState;

typedef struct HIE_tdstTransition
{
	LST_M_StaticElementDecl(HIE_tdstTransition)

	HIE_tdstState *hTargetState;
	HIE_tdstState *hStateToGo;
	BYTE ucLinkingType;
}
HIE_tdstTransition;

typedef struct HIE_tdstProhibit
{
	LST_M_StaticElementDecl(HIE_tdstProhibit)

	HIE_tdstState *hProhibitedState;
}
HIE_tdstProhibit;