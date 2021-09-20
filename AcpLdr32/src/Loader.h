#pragma once

#include "ldrdef.h"
#include "mintypes.h"


typedef BOOL (CALLBACK * LDR_tdfnInitProc)( DWORD ulSubmoduleId );

typedef struct LDR_tdstSubmodule LDR_tdstSubmodule;
typedef struct LDR_tdstSubmoduleInfo LDR_tdstSubmoduleInfo;

#ifndef ACPLDR32_EXPORTS
	// convenience typedef for use in mods
	typedef LDR_tdstSubmoduleInfo tdstModInfo;
#endif


struct LDR_tdstSubmoduleInfo
{
	char szName[64];
	char szAuthor[32];
	char szVersion[32];
};

struct LDR_tdstSubmodule
{
	HANDLE hDLl;
	LDR_tdstSubmoduleInfo stInfo;
	LDR_tdfnInitProc p_fnInitProc;
};


extern char const C_szAcpDir[];

LDR_API void LDR_fn_vInit( void );
