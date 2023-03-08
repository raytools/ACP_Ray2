/****************************************************************************
 * SND - Event
 ****************************************************************************/

#pragma once

#include "SND_Def.h"
#include "LST.h"
#include "basedef.h"


#define SND_C_NbTypeEvent 12


typedef enum SND_tdeTypeEvent
{
	SND_EVT_Invalid,
	SND_EVT_Son_Play,
	SND_EVT_Son_Stop,
	SND_EVT_Son_StopAll,
	SND_EVT_Son_StopNGo,
	SND_EVT_Son_StopNGo_Crossfade,
	SND_EVT_Son_Pitch,
	SND_EVT_Son_Volume,
	SND_EVT_Son_Pan,
	SND_EVT_Son_Effect,
	SND_EVT_Son_Extra,
	SND_EVT_Son_ChangeVolume,
	SND_EVT_ForAlignment = SND_C_EnumAlignment
}
SND_tdeTypeEvent;


typedef struct SND_tdstDeTune
{
	SND_tdxSndReal rDelta;
}
SND_tdstDeTune;

typedef struct SND_tdstEvtPlay
{
	SND_tduRefRes uResource;
	SND_tdstDeTune stDeTune;
}
SND_tdstEvtPlay;

typedef struct SND_tdstEvtStop
{
	SND_tduRefEvt uEvt;
}
SND_tdstEvtStop;

typedef struct SND_tdstEvtStopNGo
{
	SND_tduRefEvt uEvtStop;
	SND_tduRefEvt uEvtGo;
}
SND_tdstEvtStopNGo;

typedef struct SND_tdstEvtStopNGoFade
{
	SND_tduRefEvt uEvtStop;
	SND_tduRefEvt uEvtGo;
	int lTime;
}
SND_tdstEvtStopNGoFade;

typedef struct SND_tdstEvtExtraParam
{
	SND_tduRefRes uResource;
	SND_tdxSndReal rCoefA;
	SND_tdxSndReal rCoefB;
	SND_tdstDeTune stDeTune;
}
SND_tdstEvtExtraParam;

typedef struct SND_tdstEvtExtraAll
{
	SND_tduRefRes uResource;
	SND_tdxSndRealTwin rtCoefPitch;
	SND_tdxSndRealTwin rtCoefVol;
	SND_tdxSndRealTwin rtCoefPan;
}
SND_tdstEvtExtraAll;

typedef struct SND_tdstEvtEffect
{
	int lIdEffect;
}
SND_tdstEvtEffect;

typedef struct SND_tdstEvtChangeVolume
{
	BOOL bConcernWithObjectType;
	long lNewVolume;
}
SND_tdstEvtChangeVolume;


typedef union SND_tduEvtParams
{
	SND_tdstEvtPlay stPlay;
	SND_tdstEvtStop stStop;
	SND_tdstEvtStopNGo stStopNGo;
	SND_tdstEvtStopNGoFade stStopNGoFade;
	SND_tdstEvtExtraParam stExtraParam;
	SND_tdstEvtExtraAll stExtraAll;
	SND_tdstEvtEffect stEffect;
	SND_tdstEvtChangeVolume stChangeVolume;
}
SND_tduEvtParams;

typedef struct SND_tdstBlockEvent
{
	SND_tdxId Id;
	SND_tdeTypeEvent eType;
	SND_tduEvtParams uParams;
	BOOL bStopable; /* TRUE if event stops when object is destroyed */
	BOOL bDynamic;  /* TRUE if params can be modified */
	LST_M_OptChildDecl(SND_tdstBlockEvent, SND_tdstSndBankPolyEvent)
}
SND_tdstBlockEvent;
