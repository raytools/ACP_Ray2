#pragma once
#include "ACP_API.h"


////////////////////////////
//
// MMG - Memory Management
//
////////////////////////////


ACP_API extern void *(*fn_p_vGenAlloc)(unsigned int Size, unsigned int ChannelId);
ACP_API extern void *(*fn_p_vDynAlloc)(unsigned int Size);
ACP_API extern void (*fn_vDynFree)(void *Ptr);
