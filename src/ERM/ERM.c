/****************************************************************************
 *
 * ERM - Error Management Module
 *
 ****************************************************************************/

#include "ERM.h"


unsigned char (*ERM_fn_ucInitErrMsg)( void ) = OFFSET(0x4025D0);
ERM_tdstLastErrorInfo * (*ERM_fn_p_stFindstMyLastErrorInfo)( unsigned long ulChannelId ) = OFFSET(0x4026B0);
void (*ERM_fn_vClearLastError)( unsigned long ulChannelId ) = OFFSET(0x402710);

void (*ERM_fn_vUpdateLastError)(
	unsigned short uwStartOfWarningsId,
	unsigned char ucModuleId,
	unsigned long ulChannelId,
	unsigned short uwErrNum,
	long lDebugData,
	unsigned char ucOpenInfoWindow,
	unsigned char ucStopForDebug,
	char *szPersonalMsg
) = OFFSET(0x402810);
