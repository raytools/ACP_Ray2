#pragma once

#include "../MTH.h"
#include "../apidef.h"


////////////////////////
//
// ERM - Error Manager
//
////////////////////////


typedef struct ERM_tdstErrorInfo ERM_tdstErrorInfo;


ACP_API extern BYTE (*ERM_fn_ucInitErrMsg)( void );
ACP_API extern ERM_tdstErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( DWORD ulThreadId );
ACP_API extern void (*ERM_fn_vUpdateLastError)( WORD uwMaxFatalErr, BYTE ucModule, DWORD ulThreadId, WORD uwError, int, BYTE, BYTE, char *szMsg );
ACP_API extern void (*ERM_fn_vClearLastError)( DWORD ulThreadId );


struct ERM_tdstErrorInfo
{
	WORD uwError;
	BYTE ucModule;
	DWORD ulThreadId;
};
