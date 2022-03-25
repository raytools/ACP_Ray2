/****************************************************************************
 *
 * ERM - Error Management Module
 *
 ****************************************************************************/

#pragma once

#include "apidef.h"


/*
 * TODO: Update with correct names from CPA source
 */

typedef struct ERM_tdstErrorInfo
{
	unsigned short uwError;
	unsigned char ucModule;
	unsigned long ulThreadId;
}
ERM_tdstErrorInfo;


/*
 * Functions
 */

ACP_FUNC unsigned char (*ERM_fn_ucInitErrMsg)( void );
ACP_FUNC ERM_tdstErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( unsigned long ulThreadId );
ACP_FUNC void (*ERM_fn_vClearLastError)( unsigned long ulThreadId );
ACP_FUNC void (*ERM_fn_vUpdateLastError)( unsigned short uwMaxFatalErr, unsigned char ucModule,
												unsigned long ulThreadId, unsigned short uwError,
												int, unsigned char, unsigned char, char *szMsg );
