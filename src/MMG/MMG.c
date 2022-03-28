/****************************************************************************
 *
 * MMG - Memory Management module
 *
 ****************************************************************************/

#include "MMG.h"


void *(*fn_p_vGenAlloc)( unsigned long Size, unsigned long ChannelId ) = OFFSET(0x443120);
void *(*fn_p_vDynAlloc)( unsigned long Size ) = OFFSET(0x442680);
void (*fn_vDynFree)( void *Ptr ) = OFFSET(0x442740);
