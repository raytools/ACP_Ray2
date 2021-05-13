#pragma once
#include "apidef.h"


////////////////////////////////////
//
// ACP_Ray2 - library include file
//
////////////////////////////////////


////////////
// Modules
////////////

#include "MTH.h"
#include "MMG.h"
#include "GAM.h"
#include "HIE.h"
#include "AI.h"
#include "POS.h"
#include "DNM.h"
#include "JFFTXT.h"


///////////////
// Extensions
///////////////

// These headers contain extra types and functions not present in the original engine.
// To disable extensions, define ACP_NO_EXT.

#ifndef ACP_NO_EXT

#include "HIE_EXT.h"
#include "AI_EXT.h"
#include "DNM_EXT.h"

#endif /* ACP_NO_EXT */
