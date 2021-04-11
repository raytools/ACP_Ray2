#pragma once
#include "MTH.h"


////////////////
//
// AI Module
// 
////////////////


typedef struct AI_tdstBrain AI_tdstBrain;
typedef struct AI_tdstMind AI_tdstMind;
typedef struct AI_tdstIntelligence AI_tdstIntelligence;
typedef struct AI_tdstAIModel AI_tdstAIModel;

typedef struct AI_tdstGetSetParam AI_tdstGetSetParam;
typedef struct AI_tdstNodeInterpret AI_tdstNodeInterpret;
typedef struct AI_tdstScriptRule AI_tdstScriptRule;
typedef struct AI_tdstComport AI_tdstComport;
typedef struct AI_tdstScriptAI AI_tdstScriptAI;

typedef struct AI_tdstDsgMem AI_tdstDsgMem;
typedef struct AI_tdstDsgVar AI_tdstDsgVar;
typedef struct AI_tdstDsgVarInfo AI_tdstDsgVarInfo;


/////////////////
// Intelligence
/////////////////

struct AI_tdstBrain
{
	AI_tdstMind *p_stMind;
	// GMT_tdstGameMaterial *
	void *p_stLastCollidedGoThroughMaterial;
	BYTE bWarnMechanicsFlag;
	BYTE bActiveDuringTransition;
};

struct AI_tdstMind
{
	AI_tdstAIModel *p_stAIModel;
	AI_tdstIntelligence *p_stIntelligence;
	AI_tdstIntelligence *p_stReflex;
	AI_tdstDsgMem *p_stDsgMem;
};

struct AI_tdstIntelligence
{
	AI_tdstAIModel *p_stScriptAI;
	void *p_stCurrentSchedule;
	AI_tdstComport *p_stCurrentComport;
	AI_tdstComport *p_stPrevComport;
	void *p_stActionTable;
};

struct AI_tdstAIModel
{
	AI_tdstScriptAI *a_stScriptAIIntel;
	AI_tdstScriptAI *a_stScriptAIReflex;
	AI_tdstDsgVar *p_stDsgVar;
	// tdstListOfMacro *
	void *p_stListOfMacro;
	BYTE ucSecondPassDone;
};


//////////////
// Behaviors
//////////////

typedef enum AI_tdeNodeType
{
	NDT_KeyWord,
	NDT_Condition,
	NDT_Operator,
	NDT_Function,
	NDT_Procedure,
	NDT_MetaAction,
	NDT_BeginMacro,
	NDT_BeginMacro_,
	NDT_EndMacro,
	NDT_Field,
	NDT_DsgVarRef,
	NDT_DsgVarRef_,
	NDT_Constant,
	NDT_Real,
	NDT_Button,
	NDT_ConstantVector,
	NDT_Vector,
	NDT_Mask,
	NDT_ModuleRef,
	NDT_DsgVarId,
	NDT_String,
	NDT_LipsSynchroRef,
	NDT_FamilyRef,
	NDT_PersoRef,
	NDT_ActionRef,
	NDT_SuperObjectRef,
	NDT_WayPointRef,
	NDT_TextRef,
	NDT_ComportRef,
	NDT_ModuleRef_,
	NDT_SoundEventRef,
	NDT_ObjectTableRef,
	NDT_GameMaterialRef,
	NDT_ParticleGenerator,
	NDT_VisualMaterial,
	NDT_Color,
	NDT_MaybeCineRef,
	NDT_Light,
	NDT_Caps,
	NDT_SubRoutine,
	NDT_Null
} AI_tdeNodeType;

typedef enum AI_tdeGetSetParamType
{
	GSP_Constant = 0x6,
	GSP_Real = 0x8,
	GSP_String = 0x9,
	GSP_WayPointRef = 0xA,
	GSP_PersoRef = 0xB,
	GSP_MetaAction = 0x14,
	GSP_Macro = 0x14,
	GSP_SubRoutine = 0x14,
	GSP_Vector = 0x15,
	GSP_ModuleRef = 0x16,
	GSP_DsgVarId = 0x17,
	GSP_ActionRef = 0x18,
	GSP_Button = 0x19,
	GSP_Mask = 0x1A,
	GSP_LipsSynchroRef = 0x1C,
	GSP_ObjectTableRef = 0x1D,
	GSP_SuperObjectRef = 0x1E,
	GSP_FamilyRef = 0x20,
	GSP_SoundEventRef = 0x21,
	GSP_ComportRef = 0x22,
	GSP_TextRef = 0x24,
	GSP_ParticleGenerator = 0x25,
	GSP_GameMaterialRef = 0x26,
	GSP_VisualMaterial = 0x27,
	GSP_Color = 0x28,
	GSP_CineRef_Maybe = 0x2A,
	GSP_Graph_Maybe = 0x2A,
	GSP_Light = 0x2B,
	GSP_Caps = 0x2C,
} AI_tdeGetSetParamType;

struct AI_tdstGetSetParam
{
	union
	{
		void *pValue;
		float xValue;
		int lValue;
		DWORD ulValue;
		short wValue;
		WORD uwValue;
		char cValue;
		BYTE ucValue;
		char *szValue;
		MTH_tdstVector stVector;
	};

	AI_tdeGetSetParamType ulType;
};

struct AI_tdstNodeInterpret
{
	void *Value;
	WORD uwNodeToSkip;
	BYTE ucDepth;
	BYTE ucNodeType;
};

struct AI_tdstScriptRule
{
	AI_tdstNodeInterpret *p_stNodes;
};

struct AI_tdstComport
{
	AI_tdstScriptRule *a_stRules;
	AI_tdstScriptRule *p_stSchedule;
	BYTE ucNbRules;
};

struct AI_tdstScriptAI
{
	AI_tdstComport *a_stComport;
	DWORD ulNbComport;
};


////////////
// DsgVars
////////////

typedef enum AI_tdeDsgVarType
{
	DVT_Boolean,
	DVT_Byte,
	DVT_UByte,
	DVT_Short,
	DVT_UShort,
	DVT_Int,
	DVT_UInt,
	DVT_Float,
	DVT_WayPoint,
	DVT_Perso,
	DVT_List,
	DVT_Vector,
	DVT_Comport,
	DVT_Action,
	DVT_Text,
	DVT_GameMaterial,
	DVT_Caps,
	DVT_Graph,
	DVT_PersoArray,
	DVT_VectorArray,
	DVT_FloatArray,
	DVT_IntegerArray,
	DVT_WayPointArray,
	DVT_TextArray,
	DVT_SuperObject
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
	BYTE nDsgVar;
};

struct AI_tdstDsgVarInfo
{
	DWORD ulOffset;
	AI_tdeDsgVarType ulType;
	int eSaveType;
	int eInitType;
};
