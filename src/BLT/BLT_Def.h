/****************************************************************************
 * Type definitions for BLT module
 ****************************************************************************/

#pragma once


#define BLT_C_MaxErrorMsg (256)


typedef unsigned char BLT_tdxModuleId;

typedef enum BLT_tdeErrorType
{
	BLT_E_Fatal,
	BLT_E_Warning,
	BLT_E_Information
}
BLT_tdeErrorType;

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
