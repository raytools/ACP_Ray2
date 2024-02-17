/****************************************************************************
 * CLG - Modules
 ****************************************************************************/

#pragma once

#include "../CLG_Def.h"


#define CLG_M_bIsValidModuleId(xId) ((xId) < CLG_C_MaxModules)
#define CLG_M_pstGetModuleById(xId) (CLG_g_a_pstModuleTab[(xId)])
#define CLG_M_bModuleExists(xId) (CLG_M_bIsValidModuleId(xId) && (CLG_M_pstGetModuleById(xId) != NULL))


typedef struct CLG_tdstErrorTab
{
	char **d_szErrorMsg;
	unsigned long ulNbError;

	unsigned short uwIdStartOfWarning;
	unsigned short uwIdStartOfInformation;
}
CLG_tdstErrorTab;

typedef struct CLG_tdstModule
{
	char const *szCodeVersion; /* XXX Va.b.c */
	char const *szFullName;
	char const *szDate; /* MMM DD YYYY */

	CLG_tdstErrorInfo stLastErrorForModule;

	CLG_tdstErrorTab *p_stErrorTab;
}
CLG_tdstModule;
