/****************************************************************************
 *
 * API/Library definitions for ACP
 *
 ****************************************************************************/

#pragma once


#define CALLBACK __stdcall

#ifndef ACP_USE_STATIC

#ifdef ACPRAY2_EXPORTS
#define ACP_API __declspec(dllexport)
#else
#define ACP_API __declspec(dllimport)
#endif

#else
#define ACP_API
#endif


#define ACP_PTR ACP_API extern

#define ACP_FUNC ACP_PTR
#define ACP_VAR ACP_PTR

#define OFFSET(x) ((void*)(x))
