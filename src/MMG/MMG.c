/****************************************************************************
 *
 * MMG - Memory Management module
 *
 ****************************************************************************/

#include "MMG.h"

tdstBlockInfoPriv** const (g_a_p_stMmgModuleBlocksInfo) = OFFSET(0x50ACC0);



size_t (*SNA_fn_ulFRead)(void* _p_vBuffer, size_t _ulSize, size_t _ulCount, void* _p_stFile) = OFFSET(0x450d90);

void* (*fn_p_vStaRealloc)(void* ptr, unsigned long Size, unsigned long ChannelId) = OFFSET(0x442b60);
void* (*fn_p_vDynRealloc)(void* ptr, unsigned long Size) = OFFSET(0x442770);
void* (*fn_p_vGenRealloc)(void* ptr, unsigned long Size, unsigned long ChannelId) = OFFSET(0x4431a0);

void *(*fn_p_vStaAlloc)( unsigned long Size, unsigned long ChannelId ) = OFFSET(0x442850);
void *(*fn_p_vDynAlloc)( unsigned long Size ) = OFFSET(0x442680);
void* (*fn_p_vGenAlloc)(unsigned long Size, unsigned long ChannelId) = OFFSET(0x443120);

void (*fn_vDynFree)( void *Ptr ) = OFFSET(0x442740);
void (*fn_vGenFree)( void *Ptr, unsigned char ucChannel) = OFFSET(0x443160);
void (*fn_vStaFree)( void *Ptr, unsigned char ucChannel) = OFFSET(0x442a70);

void (*Mmg_fn_v_InitMmg)( unsigned char ucModuleId, unsigned char ucMaxBlocksNb, unsigned long ulMaxNbDynamicMalloc ) = OFFSET(0x443490);
void (*Mmg_fn_vInitSpecificBlock)( unsigned char _ucBlockId, unsigned char _ucModuleId,
	struct tdstBlockInfoPriv_* _p_stMyBlocksInfo, unsigned long _ulSize, unsigned long _ulMaxNbStaticMalloc,
	unsigned char _ucAlignment, unsigned char _ucMode ) = OFFSET(0x442420);
