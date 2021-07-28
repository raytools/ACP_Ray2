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

#include <MTH.h>
#include <MMG/MMG.h>
#include <GAM/GAM.h>
#include <HIE/HIE.h>
#include <AI/AI.h>
#include <POS/POS.h>
#include <DNM/DNM.h>
#include <GLI/GLI.h>
#include <JFFTXT/JFFTXT.h>


///////////////
// Extensions
///////////////

// These headers contain extra types and functions not present in the original engine.
// To disable extensions, define ACP_NO_EXT.

#ifndef ACP_NO_EXT

#include <HIE/HIE_Ext.h>
#include <AI/AI_Ext.h>
#include <DNM/DNM_Ext.h>

#include <SPTXT/SPTXT.h>

#endif /* ACP_NO_EXT */
