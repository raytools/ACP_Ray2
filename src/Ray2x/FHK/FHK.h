/****************************************************************************
 *
 * FHK - Function Hook module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "Ray2x/apidefx.h"


ACPX_API long FHK_fn_lCreateHook( void **ppfnFunc, void *pfnHook );
ACPX_API long FHK_fn_lDestroyHook( void **ppfnFunc, void *pfnHook );
