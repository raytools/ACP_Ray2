#pragma once
#include "MTH.h"

////////////////
//
// AI Model
// 
////////////////

typedef struct AI_stComport AI_tdstComport;
typedef struct AI_stDsgMem AI_tdstDsgMem;
typedef struct AI_stAIModel AI_tdstAIModel;

typedef enum
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
} AI_NODE_TYPE;

typedef struct AI_stIntelligence
{
	AI_tdstAIModel *p_stAIModel;
	// TODO: replace void*, names
	void *p_actionTree;
	AI_tdstComport *p_stBehavior;
	AI_tdstComport *p_stLastBehavior;
} AI_tdstIntelligence;

typedef struct AI_stMind
{
	AI_tdstAIModel *p_stAIModel;
	AI_tdstIntelligence *p_stIntelligenceRule;
	AI_tdstIntelligence *p_stIntelligenceReflex;
	AI_tdstDsgMem *p_stDsgMem;
} AI_tdstMind;

typedef struct AI_stBrain
{
	AI_tdstMind *p_stMind;
	// TODO
	void *field_4;
	void *field_8;
} AI_tdstBrain;

typedef struct AI_stNodeInterpret
{
	// TODO
	void *Value;
	BYTE field_4;
	BYTE field_5;
	BYTE Depth;
	BYTE NodeType;
} AI_tdstNodeInterpret;

typedef struct AI_stScript
{
	AI_tdstNodeInterpret **ap_stNodes;
} AI_tdstScript;

typedef struct AI_stComport
{
	// TODO: what's this? fix names
	AI_tdstScript *scriptsPointer;
	AI_tdstScript *firstScript;
	BYTE numScript;
	BYTE field9;
	BYTE fieldA;
	BYTE fieldB;
} AI_tdstComport;

typedef struct A_stDsgVar
{
	// TODO: DsgVars
	void *dsgVar;
} AI_tdstDsgVar;

typedef struct AI_stAIModel
{
	AI_tdstComport **ap_stBehaviorsNormal;
	AI_tdstComport **ap_stehaviorsReflex;
	AI_tdstDsgVar *p_stDsgVar;
} AI_tdstAIModel;
