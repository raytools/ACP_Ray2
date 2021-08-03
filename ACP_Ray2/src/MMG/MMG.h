#pragma once

#include "../MTH.h"
#include "../apidef.h"


////////////////////////////
//
// MMG - Memory Management
//
////////////////////////////


ACP_API extern void *(*fn_p_vGenAlloc)( DWORD Size, DWORD ChannelId );
ACP_API extern void *(*fn_p_vDynAlloc)( DWORD Size );
ACP_API extern void (*fn_vDynFree)( void *Ptr );
