#include "ERM.h"


////////////////////////
//
// ERM - Error Manager
//
////////////////////////


ACP_API BYTE (*ERM_fn_ucInitErrMsg)( void ) = 0x4025D0;
ACP_API ERM_tdstErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( DWORD ulThreadId ) = 0x4026B0;
ACP_API void (*ERM_fn_vUpdateLastError)( WORD uwMaxFatalErr, BYTE ucModule, DWORD ulThreadId, WORD uwError, int, BYTE, BYTE, char *szMsg ) = 0x402810;
ACP_API void (*ERM_fn_vClearLastError)( DWORD ulThreadId ) = 0x402710;
