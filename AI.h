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
typedef struct AI_tdstTreeInterpret AI_tdstTreeInterpret;
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
	AI_tdstNodeInterpret *p_stCurrentSchedule;
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

typedef enum AI_tdeTypeInterpret
{
	E_ti_KeyWord,
	E_ti_Condition,
	E_ti_Operator,
	E_ti_Function,
	E_ti_Procedure,
	E_ti_MetaAction,
	E_ti_BeginMacro,
	E_ti_EndMacro,
	E_ti_EndTree,
	E_ti_Field,
	E_ti_DsgVar,
	E_ti_DsgVarRef,
	E_ti_Constant,
	E_ti_Real,
	E_ti_Button,
	E_ti_ConstantVector,
	E_ti_Vector,
	E_ti_Mask,
	E_ti_Module,
	E_ti_DsgVarId,
	E_ti_String,
	E_ti_LipsSynchroRef,
	E_ti_FamilyRef,
	E_ti_PersoRef,
	E_ti_ActionRef,
	E_ti_SuperObjectRef,
	E_ti_WayPointRef,
	E_ti_TextRef,
	E_ti_ComportRef,
	E_ti_ModuleRef,
	E_ti_SoundEventRef,
	E_ti_ObjectTableRef,
	E_ti_GameMaterialRef,
	E_ti_ParticleGenerator,
	E_ti_VisualMaterial,
	E_ti_Color,
	E_ti_Light,
	E_ti_Caps,
	E_ti_Graph,
	E_ti_MacroRef,
	E_ti_Unknown,
	E_Nb_ti
} AI_tdeTypeInterpret;

typedef enum AI_tdeVariableType
{
	E_vt_None,
	E_vt_Boolean,
	E_vt_Char,
	E_vt_UChar,
	E_vt_Short,
	E_vt_UShort,
	E_vt_Integer,
	E_vt_PositiveInteger,
	E_vt_Float,
	E_vt_String,
	E_vt_WayPoint,
	E_vt_Perso,
	E_vt_List,
	E_vt_1bit,
	E_vt_2bit,
	E_vt_3bit,
	E_vt_4bit,
	E_vt_5bit,
	E_vt_6bit,
	E_vt_7bit,
	E_vt_MetaActionReturn,
	E_vt_Vector,
	E_vt_Module,
	E_vt_DsgVarId,
	E_vt_Action,
	E_vt_Button,
	E_vt_Mask,
	E_vt_Surface,
	E_vt_LipsSynchro,
	E_vt_ObjectTable,
	E_vt_SuperObject,
	E_vt_Environment,
	E_vt_Family,
	E_vt_SoundEvent,
	E_vt_Comport,
	E_vt_Font,
	E_vt_Text,
	E_vt_ParticleGenerator,
	E_vt_GameMaterial,
	E_vt_VisualMaterial,
	E_vt_Color,
	E_vt_Array,
	E_vt_Light,
	E_vt_Caps,
	E_vt_Graph,
	E_vt_Cine,
	E_Nb_vt
} AI_tdeVariableType;

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
	BYTE eType;
};

struct AI_tdstTreeInterpret
{
	AI_tdstNodeInterpret *p_stNodes;
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
	BYTE nDsgVar;
};

struct AI_tdstDsgVarInfo
{
	DWORD ulOffset;
	AI_tdeDsgVarType ulType;
	int eSaveType;
	int eInitType;
};
