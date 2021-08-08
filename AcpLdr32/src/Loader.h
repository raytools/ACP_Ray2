#pragma once

#include "ldrdef.h"
#include "mintypes.h"


typedef BOOL (CALLBACK * LDR_tdfnInitProc)( DWORD ulSubmoduleId );

typedef struct LDR_tdstSubmodule LDR_tdstSubmodule;
typedef struct LDR_tdstSubmoduleInfo LDR_tdstSubmoduleInfo;
typedef LDR_tdstSubmoduleInfo LDR_tdstModInfo;


struct LDR_tdstSubmoduleInfo
{
	char szName[64];
	char szAuthor[32];
	char szVersion[32];
	
	LDR_tdfnInitProc p_fnInitProc;
};

struct LDR_tdstSubmodule
{
	HANDLE hDLl;
	LDR_tdstSubmoduleInfo stInfo;
};


extern char const C_szAcpDir[];
extern char const C_szModDir[];
extern char const C_szModInfo[];


LDR_API void LDR_fn_vInit( void );
