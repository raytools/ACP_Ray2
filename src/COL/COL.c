/****************************************************************************
*
* COL - Collision module
*
****************************************************************************/

#include "COL.h"

/*
 * Variables
 */

COL_tdstCollisionCase* const COL_g_stCollisionCase = OFFSET(0x4F8C40); // Array with the size of COL_C_xMaxNumberOfCollisions
COL_tdstCollisionCase** const COL_g_stCollisionCaseReal = OFFSET(0x4A680C); // Usually points to the start of COL_g_stCollisionCase
long* const COL_g_lNbElementsInTable = OFFSET(0x4a6974);