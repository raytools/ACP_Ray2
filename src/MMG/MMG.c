#include "MMG.h"


////////////////////////////
//
// MMG - Memory Management
//
////////////////////////////


ACP_API void *(*fn_p_vGenAlloc)( DWORD Size, DWORD ChannelId ) = 0x443120;
ACP_API void *(*fn_p_vDynAlloc)( DWORD Size ) = 0x442680;
ACP_API void (*fn_vDynFree)( void *Ptr ) = 0x442740;
