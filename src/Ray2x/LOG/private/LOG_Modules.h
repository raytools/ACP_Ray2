/****************************************************************************
 * LOG - Modules
 ****************************************************************************/

#pragma once

#include "../LOG_Def.h"


#define LOG_M_bIsValidModuleId(xId) ((xId) < LOG_C_MaxModules)
#define LOG_M_pstGetModuleById(xId) (LOG_g_a_pstModuleTab[(xId)])
#define LOG_M_bModuleExists(xId) (LOG_M_bIsValidModuleId(xId) && (LOG_M_pstGetModuleById(xId) != NULL))


typedef struct LOG_tdstErrorTab
{
	char **d_szErrorMsg;
	unsigned long ulNbError;

	unsigned short uwIdStartOfWarning;
	unsigned short uwIdStartOfInformation;
}
LOG_tdstErrorTab;

typedef struct LOG_tdstModule
{
	char const *szCodeVersion; /* XXX Va.b.c */
	char const *szFullName;
	char const *szDate; /* MMM DD YYYY */

	LOG_tdstErrorInfo stLastErrorForModule;

	LOG_tdstErrorTab *p_stErrorTab;
}
LOG_tdstModule;
