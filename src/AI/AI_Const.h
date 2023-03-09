/****************************************************************************
 * Constant values for AI module
 ****************************************************************************/

#pragma once


enum AI_tdeTypeInterpret_
{
	AI_E_ti_KeyWord,
	AI_E_ti_Condition,
	AI_E_ti_Operator,
	AI_E_ti_Function,
	AI_E_ti_Procedure,
	AI_E_ti_MetaAction,
	AI_E_ti_BeginMacro,
	AI_E_ti_EndMacro,
	AI_E_ti_EndTree,
	AI_E_ti_Field,
	AI_E_ti_DsgVar,
	AI_E_ti_DsgVarRef,
	AI_E_ti_Constant,
	AI_E_ti_Real,
	AI_E_ti_Button,
	AI_E_ti_ConstantVector,
	AI_E_ti_Vector,
	AI_E_ti_Mask,
	AI_E_ti_Module,
	AI_E_ti_DsgVarId,
	AI_E_ti_String,
	AI_E_ti_LipsSynchroRef,
	AI_E_ti_FamilyRef,
	AI_E_ti_PersoRef,
	AI_E_ti_ActionRef,
	AI_E_ti_SuperObjectRef,
	AI_E_ti_WayPointRef,
	AI_E_ti_TextRef,
	AI_E_ti_ComportRef,
	AI_E_ti_ModuleRef,
	AI_E_ti_SoundEventRef,
	AI_E_ti_ObjectTableRef,
	AI_E_ti_GameMaterialRef,
	AI_E_ti_ParticleGenerator,
	AI_E_ti_Color,
	AI_E_ti_ModelRef,
	AI_E_ti_Light,
	AI_E_ti_Caps,
	AI_E_ti_Graph,
	AI_E_ti_MacroRef,
	AI_E_ti_Unknown,

	AI_E_Nb_ti
};
typedef unsigned char AI_tdeTypeInterpret;

typedef enum AI_tdeVariableType
{
	AI_E_vt_None,
	AI_E_vt_Boolean,
	AI_E_vt_Char,
	AI_E_vt_UChar,
	AI_E_vt_Short,
	AI_E_vt_UShort,
	AI_E_vt_Integer,
	AI_E_vt_PositiveInteger,
	AI_E_vt_Float,
	AI_E_vt_String,
	AI_E_vt_WayPoint,
	AI_E_vt_Perso,
	AI_E_vt_List,
	AI_E_vt_1bit,
	AI_E_vt_2bit,
	AI_E_vt_3bit,
	AI_E_vt_4bit,
	AI_E_vt_5bit,
	AI_E_vt_6bit,
	AI_E_vt_7bit,
	AI_E_vt_MetaActionReturn,
	AI_E_vt_Vector,
	AI_E_vt_Module,
	AI_E_vt_DsgVarId,
	AI_E_vt_Action,
	AI_E_vt_Button,
	AI_E_vt_Mask,
	AI_E_vt_Surface,
	AI_E_vt_LipsSynchro,
	AI_E_vt_ObjectTable,
	AI_E_vt_SuperObject,
	AI_E_vt_Environment,
	AI_E_vt_Family,
	AI_E_vt_SoundEvent,
	AI_E_vt_Comport,
	AI_E_vt_Font,
	AI_E_vt_Text,
	AI_E_vt_ParticleGenerator,
	AI_E_vt_GameMaterial,
	AI_E_vt_Color,
	AI_E_vt_Model,
	AI_E_vt_Array,
	AI_E_vt_Light,
	AI_E_vt_Caps,
	AI_E_vt_Graph,
	AI_E_Nb_vt
}
AI_tdeVariableType;

typedef enum AI_tdeObjectTreeInit
{
	AI_E_OTI_WhenGameStart = 0,
	AI_E_OTI_MapLoaded,
	AI_E_OTI_ReinitTheMap,
	AI_E_OTI_LoadSavedGame,
	AI_E_OTI_PlayerDead,
	AI_E_OTI_WhenGoOutOfZone = AI_E_OTI_PlayerDead,
	AI_E_OTI_Always = AI_E_OTI_WhenGoOutOfZone,
	AI_E_OTI_AlwaysCreated,
}
AI_tdeObjectTreeInit;
