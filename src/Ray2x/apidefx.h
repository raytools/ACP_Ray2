/****************************************************************************
 *
 * API/Library definitions for ACP helper DLL
 *
 ****************************************************************************/

#pragma once

#include "apidef.h"


#ifdef ACPRAY2X_EXPORTS
#define ACPX_API __declspec(dllexport)
#else
#define ACPX_API __declspec(dllimport)
#endif

#define ACPX_PTR ACPX_API extern

#define ACPX_FUNC ACPX_PTR
#define ACPX_VAR ACPX_PTR
