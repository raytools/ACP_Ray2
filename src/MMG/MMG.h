/****************************************************************************
 *
 * MMG - Memory Management module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"


ACP_FUNC void *(*fn_p_vGenAlloc)( unsigned long Size, unsigned long ChannelId );
ACP_FUNC void *(*fn_p_vDynAlloc)( unsigned long Size );
ACP_FUNC void (*fn_vDynFree)( void *Ptr );
