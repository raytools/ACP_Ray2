#pragma once

#include "../mintypes.h"


#define C_ulMaxString 128u
#define C_ulMagicHeader 0xC0DE0005u


typedef enum LDR_tdeCfgSection
{
	E_Cfg_End,
	E_Cfg_General,
	E_Cfg_LoadOrder,
	
} LDR_tdeCfgSection;


extern BYTE g_bEnableErm;
extern BYTE g_bReticulateSplines;
extern DWORD g_ulNbLoadOrder;
extern char **g_a_szLoadOrder;


BOOL CFG_fn_bReadCfgFile( void );
