/****************************************************************************
 *
 * TMR - Timer Module
 *
 ****************************************************************************/

#pragma once

#include "MTH.h"
#include "apidef.h"


typedef struct TMR_tdstTimerCount
{
	unsigned long ulLowPart;
	unsigned long ulHighPart;
}
TMR_tdstTimerCount;

typedef struct TMR_tdstEngineTimerStructure
{
	unsigned long ulFrameNumber;
	unsigned short wTimerHandle;
	unsigned long ulCurrentTimerCount;
	unsigned long ulDeltaTimerCount;
	unsigned long a_ulCounter[16];
	unsigned long ulUsefulDeltaTime;
	unsigned long ulPauseTime;
	MTH_tdxReal xFrameLength;
	TMR_tdstTimerCount stRealTimeCount;
	TMR_tdstTimerCount stPauseTime;
	unsigned long ulTickPerMs;
}
TMR_tdstEngineTimerStructure;
