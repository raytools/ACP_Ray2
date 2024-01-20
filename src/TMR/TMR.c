/****************************************************************************
*
* TMR - Timer Module
*
****************************************************************************/

#include "TMR.h"


TMR_tdstTimer *const TMR_a_stTimerTab = OFFSET(0x5161A0);

short (__stdcall *TMR_fn_wStartTimer)( short wTimerHandle ) = OFFSET(0x45DF90);
short (__stdcall *TMR_fn_wReadTimer)( short wTimerHandle, TMR_tdstTimerCount *p_stTimerCount ) = OFFSET(0x45E2E0);
short (__stdcall *TMR_fn_wSetTimerValue)( short wTimerHandle, TMR_tdstTimerCount *p_stValue ) = OFFSET(0x45E210);
