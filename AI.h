#pragma once
#include "MTH.h"

////////////////
// AI Model
////////////////

typedef struct stComport tdstComport;
typedef struct stDsgMem tdstDsgMem;
typedef struct AI_stAIModel AI_tdstAIModel;

typedef struct stIntelligence {
	AI_tdstAIModel* p_stAIModel;
	int* p_actionTree;
	tdstComport* p_behavior;
	tdstComport* p_lastBehavior;
} tdstIntelligence;

typedef struct stMind {
	AI_tdstAIModel* p_stAIModel;
	tdstIntelligence* p_intelligenceRule;
	tdstIntelligence* p_intelligenceReflex;
	tdstDsgMem* p_dsgMem;
} tdstMind;

typedef struct stBrain {
	tdstMind* p_stMind;
	int field_4;
	int field_8;
} tdstBrain;

typedef struct stNodeInterpret
{
	int param;
	BYTE field_4;
	BYTE field_5;
	BYTE depth;
	BYTE typeID;

} tdstNodeInterpret;

typedef struct stScript
{
	tdstNodeInterpret** nodes;

} tdstScript;

typedef struct stComport
{
	tdstScript* scriptsPointer;
	tdstScript* firstScript;
	BYTE numScript;
	BYTE field9;
	BYTE fieldA;
	BYTE fieldB;
} tdstComport;

typedef struct stDsgVar
{
	// TODO: DsgVars
	int dsgVar;
} tdstDsgVar;

typedef struct AI_stAIModel
{
	tdstComport** behaviorListNormal;
	tdstComport** behaviorListReflex;
	tdstDsgVar* dsgVar;

} AI_tdstAIModel;