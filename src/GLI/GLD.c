/****************************************************************************
*
* GLD - Graphics Library for Display
*
****************************************************************************/

#include "GLD.h"

/*
 * Variables
 */
char *const GLD_g_cEraseBackground = OFFSET(0x49F81C);

/*
 * Functions
 */
void (*GLD_bFlipDeviceWithSynchro)(void) = OFFSET(0x420f50);
