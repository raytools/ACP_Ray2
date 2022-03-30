/****************************************************************************
 * BLT - Modules
 ****************************************************************************/

#pragma once

#include "BLT/BLT_Def.h"


#define BLT_C_MaxModules (128)
#define BLT_C_DefaultModule (0)

#define BLT_M_bIsValidModuleId(xId) (((xId) > 0) && ((xId) <= BLT_C_MaxModules))
#define BLT_M_lModuleTabIdxFromModuleId(xId) ((int)((xId) - 1))
#define BLT_M_pstGetModuleById(xId) (BLT_g_a_pstModuleTab[BLT_M_lModuleTabIdxFromModuleId(xId)])
#define BLT_M_bModuleExists(xId) (BLT_M_bIsValidModuleId(xId) && (BLT_M_pstGetModuleById(xId) != NULL))


typedef struct BLT_tdstErrorTab
{
	char **d_szErrorMsg;
	unsigned long ulNbError;

	unsigned short uwIdStartOfWarning;
	unsigned short uwIdStartOfInformation;
}
BLT_tdstErrorTab;

typedef struct BLT_tdstModule
{
	char const *szCodeVersion; /* XXX Va.b.c */
	char const *szFullName;
	char const *szDate; /* MMM DD YYYY */

	BLT_tdstErrorInfo stLastErrorForModule;

	BLT_tdstErrorTab *p_stErrorTab;
}
BLT_tdstModule;
