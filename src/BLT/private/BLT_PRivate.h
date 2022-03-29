/****************************************************************************
 *
 * Private header for BLT module
 *
 ****************************************************************************/

#pragma once

#include "BLT/BLT.h"
#include "private/framework.h"


#define BLT_C_MaxErrBuffer		(512)
#define BLT_C_MaxErrorMsg		(256)
#define BLT_C_MaxModules		(128)

#define BLT_C_szLogFileName		"CPALog.log"
#define BLT_C_DefaultModule		(0)


typedef struct BLT_tdstErrorInfo
{
	char szErrorMsg[BLT_C_MaxErrorMsg];
	BLT_tdeErrorType eType;
	unsigned short uwErrorId;
	BLT_tdxModuleId xModuleId;
	char *szFileName;
	unsigned short uwLineNum;
}
BLT_tdstErrorInfo;

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


/*
 * Macros
 */

#define BLT_M_bIsValidModuleId(xId) ((xId) > 0)
#define BLT_M_lModuleTabIdxFromModuleId(xId) ((int)((xId) - 1))
#define BLT_M_pstGetModuleById(xId) (BLT_g_a_pstModuleTab[BLT_M_lModuleTabIdxFromModuleId(xId)])

/*
 *
 * Functions
 */

FILE * BLT_fn_hOpenFileForWrite( char *szFilePath );
void BLT_fn_vCloseFile( FILE *hFile );

void BLT_fn_vPrintToFile( char *szText, FILE *hFile );
void BLT_fn_vPrintToInfoWindow( char *szText );
