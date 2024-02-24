/****************************************************************************
 *
 * ACP_Ray2x - Helper DLL main include file
 *
 ****************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "apidefx.h"


/* Spitfire's Text Helper Module */
#include "SPTXT/SPTXT.h"

/* Spitfire's Log Module */
#include "LOG/LOG.h"

#if defined(ACP_USE_COMPATLOG)
/* Compatible Log & Error Module */
#include "CLG/CLG.h"
#endif

/* Function Hook module */
#include "FHK/FHK.h"

/* Texture Manager module*/
#include "TXM/TXM.h"


#ifdef __cplusplus
} /* extern "C" */
#endif
