/****************************************************************************
 * Type definitions and constants for LOG module
 ****************************************************************************/

#pragma once


#define LOG_C_MaxErrorMsg (256)
#define LOG_C_MaxModules (64)
#define LOG_C_DefaultModule (LOG_C_MaxModules)


typedef unsigned char LOG_tdxModuleId;

typedef enum LOG_tdeErrorType
{
	LOG_E_Fatal,
	LOG_E_Warning,
	LOG_E_Information
}
LOG_tdeErrorType;

typedef struct LOG_tdstErrorInfo
{
	char szErrorMsg[LOG_C_MaxErrorMsg];
	LOG_tdeErrorType eType;
	unsigned short uwErrorId;
	LOG_tdxModuleId xModuleId;
	char *szFileName;
	unsigned short uwLineNum;
}
LOG_tdstErrorInfo;
