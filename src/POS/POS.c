/****************************************************************************
 *
 * POS - Position module
 *
 ****************************************************************************/

#include "POS.h"


void (*POS_fn_vSetIdentityMatrix)( POS_tdstCompletePosition *p_stMatrix ) = OFFSET(0x4447E0);
