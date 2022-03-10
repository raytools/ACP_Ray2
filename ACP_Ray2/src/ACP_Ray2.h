#pragma once

#include "apidef.h"
#include "basedef.h"


////////////////////////////////////
//
// ACP_Ray2 - library include file
//
////////////////////////////////////


////////////
// Modules
////////////

#include "MTH.h"
#include "LST.h"
#include "POS/POS.h"
#include "MMG/MMG.h"
#include "GAM/GAM.h"
#include "HIE/HIE.h"
#include "AI/AI.h"
#include "DNM/DNM.h"
#include "GLI/GLI.h"
#include "GLI/GLD.h"
#include "ERM/ERM.h"
#include "TMR/TMR.h"
#include "FIL/FIL.h"
#include "JFFTXT/JFFTXT.h"


///////////////
// Extensions
///////////////

// These headers contain extra types and functions not present in the original engine.
// To disable extensions, define ACP_NO_EXT.

#ifndef ACP_NO_EXT

#include "HIE/HIE_Ext.h"
#include "AI/AI_Ext.h"
#include "DNM/DNM_Ext.h"

#include "SPTXT/SPTXT.h"

#endif /* ACP_NO_EXT */
