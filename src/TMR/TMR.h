#pragma once

#include <MTH.h>
#include <apidef.h>


///////////////////////
//
// TMR - Timer Module
//
///////////////////////


typedef struct TMR_tdstTimerCount TMR_tdstTimerCount;
typedef struct TMR_tdstEngineTimerStructure TMR_tdstEngineTimerStructure;


struct TMR_tdstTimerCount
{
	DWORD ulLowPart;
	DWORD ulHighPart;
};

struct TMR_tdstEngineTimerStructure
{
	DWORD ulFrameNumber;
	WORD wTimerHandle;
	DWORD ulCurrentTimerCount;
	DWORD ulDeltaTimerCount;
	DWORD a_ulCounter[16];
	DWORD ulUsefulDeltaTime;
	DWORD ulPauseTime;
	MTH_tdxReal xFrameLength;
	TMR_tdstTimerCount stRealTimeCount;
	TMR_tdstTimerCount stPauseTime;
	DWORD ulTickPerMs;
};
