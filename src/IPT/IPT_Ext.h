/****************************************************************************
 *
 * IPT Extensions
 *
 ****************************************************************************/

#pragma once

#include "IPT.h"
#include "basedef.h"
#include "apidef.h"


#define IPT_M_bActionJustValidated( eAction ) (IPT_g_stInputStructure->d_stEntryElementArray[(eAction)].lState == 1)
#define IPT_M_bActionJustInvalidated( eAction ) (IPT_g_stInputStructure->d_stEntryElementArray[(eAction)].lState == -1)

#define IPT_M_bActionIsValidated( eAction ) (IPT_g_stInputStructure->d_stEntryElementArray[(eAction)].lState > 0)
#define IPT_M_bActionIsInvalidated( eAction ) (IPT_g_stInputStructure->d_stEntryElementArray[(eAction)].lState < 0)

#define IPT_M_xActionAnalogicValue( eAction ) (IPT_g_stInputStructure->d_stEntryElementArray[(eAction)].xAnalogicValue)
