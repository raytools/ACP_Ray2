/****************************************************************************
 * Script interpreter structures for AI module
 ****************************************************************************/

#pragma once

#include "AI_Const.h"
#include "MTH.h"


typedef struct AI_tdstGetSetParam
{
	union
	{
		void *pValue;
		MTH_tdxReal xValue;
		long lValue;
		unsigned long ulValue;
		short wValue;
		unsigned short uwValue;
		char cValue;
		unsigned char ucValue;
		char *szValue;
		MTH3D_tdstVector stVector;
	};

	AI_tdeVariableType ulType;
}
AI_tdstGetSetParam;

typedef struct AI_tdstNodeInterpret
{
	void *Value;
	unsigned short uwNodeToSkip;
	unsigned char ucDepth;
	AI_tdeTypeInterpret eType;
}
AI_tdstNodeInterpret;

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
