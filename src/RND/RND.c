/****************************************************************************
 *
 * RND - Random module
 *
 ****************************************************************************/

#include "RND.h"

RND_tdstRandom* const RND_g_stRandomStructure = OFFSET(0x5114E0);


void(*RND_fn_vComputeRandomTable)() = OFFSET(0x449ae0);
void(*RND_fn_vRemapRandomTable)() = OFFSET(0x449b40);