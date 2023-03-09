/****************************************************************************
 * AI - Arrays
 ****************************************************************************/

#pragma once

#include "AI_Const.h"
#include "AI_DsgVar.h"
#include "AI_Scr.h"


#define AI_C_SizeOfMinimalArray 2
#define AI_C_SizeOfMaximalArray 255

#define AI_C_ArrayFactor 3
#define AI_C_SizeOfArrayElement (sizeof(AI_tduGetSetParamForNode))
#define AI_M_pArrayElement( hArray, n ) (&((hArray)->d_ArrayElement[((hArray)->eType == AI_E_dvt_Vector) ? AI_C_ArrayFactor*(n) : (n)]))


typedef struct AI_tdstArray
{
	AI_tdeDsgVarType eType;
	unsigned char ucMaxSize;
	AI_tduGetSetParamForNode d_ArrayElement[AI_C_SizeOfMaximalArray];
}
AI_tdstArray;

typedef struct AI_tdstArray_1
{
	AI_tdeDsgVarType eType;
	unsigned char ucMaxSize;
	AI_tduGetSetParamForNode d_ArrayElement[1];
}
AI_tdstArray_1;
