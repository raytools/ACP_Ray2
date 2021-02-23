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
	void *_field_4;
	void *_field_8;
} AI_tdstBrain;

typedef struct AI_stNodeInterpret
{
	// TODO
	void *Value;
	BYTE _field_4;
	BYTE _field_5;
	BYTE Depth;
	BYTE NodeType;
} AI_tdstNodeInterpret;

typedef struct AI_stScript
{
	AI_tdstNodeInterpret **ap_stNodes;
} AI_tdstScript;

typedef struct AI_stComport
{
	AI_tdstScript *a_stScripts;
	AI_tdstScript *p_stFirstScript;
	BYTE nScripts;
	BYTE _field_9;
	BYTE _field_A;
	BYTE _field_B;
} AI_tdstComport;

////////////
// DsgVar
////////////

typedef enum AI_eDsgVarTypeId
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
} AI_tdeDsgVarTypeId;

typedef struct AI_stDsgVarInfo
{
	int lOffset;
	AI_tdeDsgVarTypeId ulType;
	
	// TODO: what's this, names
	int saveType;
	int initType;
} AI_tdstDsgVarInfo;

typedef struct AI_stDsgVar
{
	BYTE *p_MemBufferDefault;
	AI_tdstDsgVarInfo *a_stInfos;
	int cbMemBuffer;
	BYTE nInfos;
	
	BYTE _field_D;
	BYTE _field_E;
	BYTE _field_F;
} AI_tdstDsgVar;

typedef struct AI_stDsgMem
{
	AI_tdstDsgVar **pp_stDsgVar; // Double pointer for some reason, maybe an array of dsgvars?
	BYTE *p_MemBufferInitial;
	BYTE *p_MemBuffer;
} AI_tdstDsgMem;

typedef struct AI_stAIModel
{
	AI_tdstComport **ap_stBehaviorsNormal;
	AI_tdstComport **ap_stBehaviorsReflex;
	AI_tdstDsgVar *p_stDsgVar;
} AI_tdstAIModel;
