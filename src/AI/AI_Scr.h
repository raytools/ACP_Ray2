/****************************************************************************
 * Script interpreter structures for AI module
 ****************************************************************************/

#pragma once

#include "AI_Const.h"
#include "HIE/HIE_Def.h"
#include "GMT/GMT_Def.h"
#include "GLI/GLI_Def.h"
#include "SND/SND_Def.h"
#include "MTH.h"


typedef struct AI_tdstTreeInterpret
{
	AI_tdstNodeInterpret *p_stNodeInterpret;
}
AI_tdstTreeInterpret;

typedef struct AI_tdstComport
{
	AI_tdstTreeInterpret *a_stRules;
	AI_tdstTreeInterpret *p_stSchedule;
	unsigned char ucNbRules;
}
AI_tdstComport;

typedef struct AI_tdstScriptAI
{
	AI_tdstComport *a_stComport;
	unsigned long ulNbComport;
	unsigned long ulNoComportInitDefault;
	unsigned char ucActionTableNbEntry;
}
AI_tdstScriptAI;

typedef struct AI_tdstMacro
{
	AI_tdstTreeInterpret *p_stInitTree;
	AI_tdstTreeInterpret *p_stCurrentTree;
}
AI_tdstMacro;

typedef struct AI_tdstListOfMacro
{
	AI_tdstMacro *p_stMacro;
	unsigned char ucNbMacro;
}
AI_tdstListOfMacro;


/*
 * GetSetParam
 */

typedef union AI_tduGetSetParam
{
	MTH_tdxReal xValue;
	long lValue;
	unsigned long ulValue;
	short wValue;
	unsigned short uwValue;
	char cValue;
	unsigned char ucValue;
	char *szString;
	MTH3D_tdstVector stVector;
	HIE_tdstSuperObject *hSuperObject;
	HIE_tdstEngineObject *hActor;
	HIE_tdstState *hState;
	HIE_tdstObjectsTablesList *hObjectTable;
	HIE_tdstFamilyList *hFamily;
	AI_tdstComport *hComport;
	AI_tdstAIModel *hModel;
	AI_tdstMacro *hMacro;
	GMT_tdstGameMaterial *hGameMaterial;
	GMT_tdxMask xMask;
	GLI_tdstLight *hLight;
	SND_tduRefEvt hSoundEvent;
	//RGBAStruct ColorValue;
	//FON_tdxHandleOfText hText;
	//WP_tdhWayPoint m_hWayPoint;
	//WP_tdHandleOfGraph hGraph;
	//tdxHandleOfLipsSynchroTable hLipsSynchro;
	//tdxHandleToParticleGenerator hParticleGenerator;
}
AI_tduGetSetParam;

typedef union AI_tduGetSetParamForNode
{
	MTH_tdxReal xValue;
	long lValue;
	unsigned long ulValue;
	short wValue;
	unsigned short uwValue;
	char cValue;
	unsigned char ucValue;
	char *szString;
	MTH3D_tdstVector *p_stVector;
	HIE_tdstSuperObject *hSuperObject;
	HIE_tdstEngineObject *hActor;
	HIE_tdstState *hState;
	HIE_tdstObjectsTablesList *hObjectTable;
	HIE_tdstFamilyList *hFamily;
	AI_tdstComport *hComport;
	AI_tdstAIModel *hModel;
	AI_tdstMacro *hMacro;
	GMT_tdstGameMaterial *hGameMaterial;
	GMT_tdxMask xMask;
	GLI_tdstLight *hLight;
	SND_tduRefEvt hSoundEvent;
	//RGBAStruct ColorValue;
	//FON_tdxHandleOfText hText;
	//WP_tdhWayPoint m_hWayPoint;
	//WP_tdHandleOfGraph hGraph;
	//tdxHandleOfLipsSynchroTable hLipsSynchro;
	//tdxHandleToParticleGenerator hParticleGenerator;
}
AI_tduGetSetParamForNode;

typedef struct AI_tdstGetSetParam
{
	AI_tduGetSetParam uParam;
	AI_tdeVariableType ulType;
}
AI_tdstGetSetParam;

typedef struct AI_tdstNodeInterpret
{
	union
	{
		AI_tduGetSetParamForNode uParam;
		void *Value;
	};

	unsigned short uwNodeToSkip;
	unsigned char ucDepth;
	AI_tdeTypeInterpret eType;
}
AI_tdstNodeInterpret;
