/****************************************************************************
 * Type definitions and constants for CLG module
 ****************************************************************************/

#pragma once


#define CLG_C_MaxErrorMsg (256)
#define CLG_C_MaxModules (64)
#define CLG_C_DefaultModule (CLG_C_MaxModules)


typedef unsigned char CLG_tdxModuleId;

typedef enum CLG_tdeErrorType
{
	CLG_E_Fatal,
	CLG_E_Warning,
	CLG_E_Information
}
CLG_tdeErrorType;

typedef struct CLG_tdstErrorInfo
{
	char szErrorMsg[CLG_C_MaxErrorMsg];
	CLG_tdeErrorType eType;
	unsigned short uwErrorId;
	CLG_tdxModuleId xModuleId;
	char const *szFileName;
	unsigned short uwLineNum;
}
CLG_tdstErrorInfo;
