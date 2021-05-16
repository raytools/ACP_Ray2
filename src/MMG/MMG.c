#include "MMG.h"
#include <apidef.h>


////////////////////////////
//
// MMG - Memory Management
//
////////////////////////////


ACP_API void *(*fn_p_vGenAlloc)( unsigned int Size, unsigned int ChannelId ) = 0x443120;
ACP_API void *(*fn_p_vDynAlloc)( unsigned int Size ) = 0x442680;
ACP_API void (*fn_vDynFree)( void *Ptr ) = 0x442740;
