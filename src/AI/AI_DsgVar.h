/****************************************************************************
 * AI - DsgVars
 ****************************************************************************/

#pragma once

#include "AI_Const.h"


typedef enum AI_tdeDsgVarType
{
	AI_E_dvt_Boolean,
	AI_E_dvt_Char,
	AI_E_dvt_UChar,
	AI_E_dvt_Short,
	AI_E_dvt_UShort,
	AI_E_dvt_Integer,
	AI_E_dvt_PositiveInteger,
	AI_E_dvt_Float,
	AI_E_dvt_WayPoint,
	AI_E_dvt_Perso,
	AI_E_dvt_List,
	AI_E_dvt_Vector,
	AI_E_dvt_Comport,
	AI_E_dvt_Action,
	AI_E_dvt_Text,
	AI_E_dvt_GameMaterial,
	AI_E_dvt_Caps,
	AI_E_dvt_Graph,
	AI_E_dvt_PersoArray,
	AI_E_dvt_VectorArray,
	AI_E_dvt_FloatArray,
	AI_E_dvt_IntegerArray,
	AI_E_dvt_WayPointArray,
	AI_E_dvt_TextArray,
	AI_E_dvt_SuperObject,
	AI_E_Nb_dvt
}
AI_tdeDsgVarType;

typedef struct AI_tdstDsgVarInfo
{
	unsigned long ulOffsetInDsgMem;
	AI_tdeDsgVarType eTypeId;
	long eSaveType;
	AI_tdeObjectTreeInit eInitType;
}
AI_tdstDsgVarInfo;

typedef struct AI_tdstDsgVar
{
	char *p_cDsgMemDefaultInit;
	AI_tdstDsgVarInfo *a_stDsgVarInfo;
	unsigned long ulBufferSize;
	unsigned char ucNbDsgVar;
}
AI_tdstDsgVar;

typedef struct AI_tdstDsgMem
{
	AI_tdstDsgVar **pp_stDsgVar;
	char *p_cDsgMemBufferInit;
	char *p_cDsgMemBuffer;
}
AI_tdstDsgMem;
