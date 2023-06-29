/****************************************************************************
 *
 * ACP_Ray2 - Library main include file
 *
 ****************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "apidef.h"
#include "basedef.h"


/****************************************************************************
 * CPA Modules
 ****************************************************************************/

#include "MTH.h"
#include "LST.h"
#include "POS/POS.h"
#include "MMG/MMG.h"
#include "GAM/GAM.h"
#include "HIE/HIE.h"
#include "AI/AI.h"
#include "ALW/ALW.h"
#include "DNM/DNM.h"
#include "GMT/GMT.h"
#include "GEO/GEO.h"
#include "PO/PO.h"
#include "SCT/SCT.h"
#include "GLI/GLI.h"
#include "GLI/GLD.h"
#include "IPT/IPT.h"
#include "SND/SND.h"
#include "ERM/ERM.h"
#include "TMR/TMR.h"
#include "FIL/FIL.h"
#include "FON/FON.h"
#include "AGO/AGO.h"
#include "JFFTXT/JFFTXT.h"


/****************************************************************************
 * Extensions
 ****************************************************************************/

/* These headers contain extra types and functions that extend the CPA engine. */
/* To disable extensions, define ACP_NO_EXT */
#if !defined(ACP_NO_EXT)

#include "HIE/HIE_Ext.h"
#include "AI/AI_Ext.h"
#include "DNM/DNM_Ext.h"
#include "IPT/IPT_Ext.h"
#include "SND/SND_Ext.h"

#endif /* !ACP_NO_EXT */

/* Include the ACP_Ray2x helper DLL headers. */
/* To disable, define ACP_NOX */
#if !defined(ACP_NOX)

#include "Ray2x/ACP_Ray2x.h"

#if defined(_MSC_VER) && !defined(ACPRAY2_EXPORTS)
#pragma comment(lib, "ACP_Ray2x.lib")
#endif

#endif /* !ACP_NOX */


#ifdef __cplusplus
} /* extern "C" */
#endif
