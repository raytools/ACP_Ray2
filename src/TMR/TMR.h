/****************************************************************************
 *
 * TMR - Timer Module
 *
 ****************************************************************************/

#pragma once

#include "MTH.h"
#include "apidef.h"


#define TMR_C_uwTimerMaxCount 16


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


typedef enum TMR_tdeTimerState
{
	TMR_E_TimerUnused = 0,
	TMR_E_TimerReady,
	TMR_E_TimerRunning,
	TMR_E_TimerStop,
	TMR_E_TimerPaused
}
TMR_tdeTimerState;

typedef void (*TMR_tdfn_vTimerEventCallback)( void );

typedef struct TMR_tdstTimer
{
	short wTimerType;
	short wTimerState;
	TMR_tdstTimerCount stInitValue;
	TMR_tdstTimerCount stLastValue;
	TMR_tdstTimerCount stTotalValue;
	unsigned long ulEventId;
	TMR_tdfn_vTimerEventCallback p_fn_vEventCallback;
}
TMR_tdstTimer;


/*
 * Variables
 */

ACP_VAR TMR_tdstTimer *const TMR_a_stTimerTab;


/*
 * Functions
 */

ACP_FUNC short (__stdcall *TMR_fn_wStartTimer)( short wTimerHandle );
ACP_FUNC short (__stdcall *TMR_fn_wReadTimer)( short wTimerHandle, TMR_tdstTimerCount *p_stTimerCount );
ACP_FUNC short (__stdcall *TMR_fn_wSetTimerValue)( short wTimerHandle, TMR_tdstTimerCount *p_stValue );
