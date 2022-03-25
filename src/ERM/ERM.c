/****************************************************************************
 *
 * ERM - Error Management Module
 *
 ****************************************************************************/

#include "ERM.h"


unsigned char (*ERM_fn_ucInitErrMsg)( void ) = OFFSET(0x4025D0);
ERM_tdstErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( unsigned long ulThreadId ) = OFFSET(0x4026B0);
void (*ERM_fn_vClearLastError)( unsigned long ulThreadId ) = OFFSET(0x402710);
void (*ERM_fn_vUpdateLastError)( unsigned short uwMaxFatalErr, unsigned char ucModule,
								 unsigned long ulThreadId, unsigned short uwError,
								 int, unsigned char, unsigned char, char *szMsg ) = OFFSET(0x402810);
