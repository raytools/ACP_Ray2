/****************************************************************************
 *
 * BLT - Spitfire's Better Log Tool
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"


typedef unsigned char BLT_tdxModuleId;

typedef enum BLT_tdeErrorType
{
	BLT_E_Fatal,
	BLT_E_Warning,
	BLT_E_Information,

	BLT_NbErrorType
}
BLT_tdeErrorType;


/*
 * Functions
 */

ACP_API void BLT_fn_vInit( void );
ACP_API BLT_tdxModuleId BLT_fn_xRegisterModule( char const *szCodeVersion, char const *szFullName, char const *szDate );
ACP_API void BLT_fn_vModuleUseErrorTab( BLT_tdxModuleId xModuleId, char **d_szErrorMsg, unsigned long ulNbError,
										unsigned short uwIdStartOfWarning, unsigned short uwIdStartOfInformation );
