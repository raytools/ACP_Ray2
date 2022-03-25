/****************************************************************************
 *
 * API/Library definitions for ACP
 *
 ****************************************************************************/

#pragma once


#define CALLBACK __stdcall

#ifdef ACPRAY2_EXPORTS
#define ACP_API __declspec(dllexport)
#else
#define ACP_API __declspec(dllimport)
#endif

#define ACP_PTR ACP_API extern

#define ACP_FUNC ACP_PTR
#define ACP_VAR ACP_PTR

#define OFFSET(x) ((void*)(x))
