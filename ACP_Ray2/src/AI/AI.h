#pragma once

#include "AI_Def.h"
#include "AI_Const.h"
#include "../HIE/HIE_Def.h"
#include "../MTH.h"
#include "../apidef.h"


////////////////
//
// AI Module
// 
////////////////


ACP_API extern AI_tdstNodeInterpret *(*AI_fn_p_stEvalTree)( HIE_tdstSuperObject *p_stSpo,
															AI_tdstNodeInterpret *p_stNode,
															AI_tdstGetSetParam *p_stParam );


/////////////////
// Intelligence
/////////////////

struct AI_tdstBrain
{
	AI_tdstMind *p_stMind;
	// GMT_tdstGameMaterial *
	void *p_stLastCollidedGoThroughMaterial;
	ACP_tdxBool bWarnMechanicsFlag;
	//BYTE bActiveDuringTransition;
};

struct AI_tdstMind
{
	AI_tdstAIModel *p_stAIModel;

	AI_tdstIntelligence *p_stIntelligence;
	AI_tdstIntelligence *p_stReflex;

	AI_tdstDsgMem *p_stDsgMem;

	ACP_tdxBool bDoingIntel; /* 1 = intelligence, 0 = reflex */
};

struct AI_tdstIntelligence
{
	AI_tdstScriptAI **pp_stScriptAI;
	AI_tdstNodeInterpret *p_stCurrentSchedule;

	AI_tdstComport *p_stCurrentComport;
	AI_tdstComport *p_stPrevComport;
	void *p_stActionTable;
	DWORD ulNoComportInit;
};

struct AI_tdstAIModel
{
	AI_tdstScriptAI *a_stScriptAIIntel;
	AI_tdstScriptAI *a_stScriptAIReflex;

	AI_tdstDsgVar *p_stDsgVar;
	AI_tdstListOfMacro *p_stListOfMacro;

	BYTE ucSecondPassDone;
};


//////////////
// Behaviors
//////////////

struct AI_tdstGetSetParam
{
	union
	{
		void *pValue;
		MTH_tdxReal xValue;
		int lValue;
		DWORD ulValue;
		short wValue;
		WORD uwValue;
		char cValue;
		BYTE ucValue;
		char *szValue;
		MTH3D_tdstVector stVector;
	};

	AI_tdeVariableType ulType;
};

struct AI_tdstNodeInterpret
{
	void *Value;
	WORD uwNodeToSkip;
	BYTE ucDepth;
	AI_tdeTypeInterpret eType;
};

struct AI_tdstTreeInterpret
{
	AI_tdstNodeInterpret *p_stNodeInterpret;
};

struct AI_tdstComport
{
	AI_tdstTreeInterpret *a_stRules;
	AI_tdstTreeInterpret *p_stSchedule;
	BYTE ucNbRules;
};

struct AI_tdstScriptAI
{
	AI_tdstComport *a_stComport;
	DWORD ulNbComport;
	DWORD ulNoComportInitDefault;
	BYTE ucActionTableNbEntry;
};

struct AI_tdstMacro
{
	AI_tdstTreeInterpret *p_stInitTree;
	AI_tdstTreeInterpret *p_stCurrentTree;
};

struct AI_tdstListOfMacro
{
	AI_tdstMacro *p_stMacro;
	BYTE ucNbMacro;
};


////////////
// DsgVars
////////////

typedef enum AI_tdeDsgVarType
{
	E_dvt_Boolean,
	E_dvt_Char,
	E_dvt_UChar,
	E_dvt_Short,
	E_dvt_UShort,
	E_dvt_Integer,
	E_dvt_PositiveInteger,
	E_dvt_Float,
	E_dvt_WayPoint,
	E_dvt_Perso,
	E_dvt_List,
	E_dvt_Vector,
	E_dvt_Comport,
	E_dvt_Action,
	E_dvt_Text,
	E_dvt_GameMaterial,
	E_dvt_Caps,
	E_dvt_Graph,
	E_dvt_PersoArray,
	E_dvt_VectorArray,
	E_dvt_FloatArray,
	E_dvt_IntegerArray,
	E_dvt_WayPointArray,
	E_dvt_TextArray,
	E_dvt_SuperObject
} AI_tdeDsgVarType;

struct AI_tdstDsgMem
{
	AI_tdstDsgVar **pp_stDsgVar;
	char *p_cDsgMemBufferInit;
	char *p_cDsgMemBuffer;
};

struct AI_tdstDsgVar
{
	char *p_cDsgMemDefaultInit;
	AI_tdstDsgVarInfo *a_stDsgVarInfo;
	DWORD ulBufferSize;
	BYTE ucNbDsgVar;
};

struct AI_tdstDsgVarInfo
{
	DWORD ulOffsetInDsgMem;
	AI_tdeDsgVarType eTypeId;
	int eSaveType;
	int eInitType;
};
