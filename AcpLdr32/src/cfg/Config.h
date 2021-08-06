#pragma once

#include "../private/framework.h"


#define MAX_STRING 128
#define C_ulMagicHeader 0xC0DE0005u

typedef enum LDR_tdeCfgSection
{
	E_Cfg_General = 1,
	E_Cfg_LoadOrder = 2,
	
} LDR_tdeCfgSection;


extern DWORD g_ulNbMods;
extern BYTE g_bReticulateSplines;
extern BYTE g_bEnableErm;
extern char **g_a_szLoadOrder;


BOOL CFG_fn_bReadCfgFile( void );
