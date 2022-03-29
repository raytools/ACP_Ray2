/****************************************************************************
 *
 * ERM - Error Management Module
 *
 ****************************************************************************/

#pragma once

#include "apidef.h"


typedef struct ERM_tdstLastErrorInfo
{
	unsigned short uwLastErr;
	unsigned char ucLastModuleId;
	unsigned long ulChannelId;
}
ERM_tdstLastErrorInfo;


/*
 * Functions
 */

ACP_FUNC unsigned char (*ERM_fn_ucInitErrMsg)( void );
ACP_FUNC ERM_tdstLastErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( unsigned long ulThreadId );
ACP_FUNC void (*ERM_fn_vClearLastError)( unsigned long ulThreadId );

ACP_FUNC void (*ERM_fn_vUpdateLastError)(
	unsigned short uwStartOfWarningsId,
	unsigned char ucModuleId,
	unsigned long ulChannelId,
	unsigned short uwErrNum,
	long lDebugData,
	unsigned char ucOpenInfoWindow,
	unsigned char ucStopForDebug,
	char *szPersonalMsg
);
