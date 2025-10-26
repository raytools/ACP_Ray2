/****************************************************************************
 *
 * MMG - Memory Management module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"
#include <stddef.h>

#define MMG_C_ucNbOfMaxModule 255

typedef struct tdstBlockInfoPriv {
  char *p_cBeginBlock;
  char *p_cEndBlock;
  char *p_cFirstFree;
  char *p_cMaxMem;
} tdstBlockInfoPriv;

ACP_VAR tdstBlockInfoPriv ** const g_a_p_stMmgModuleBlocksInfo;

ACP_FUNC size_t (*SNA_fn_ulFRead)(void *_p_vBuffer, size_t _ulSize, size_t _ulCount, void *_p_stFile);
ACP_FUNC void *(*fn_p_vGenAlloc)( unsigned long Size, unsigned long ChannelId );
ACP_FUNC void *(*fn_p_vDynAlloc)( unsigned long Size );
ACP_FUNC void (*fn_vDynFree)( void *Ptr );
ACP_FUNC void (*Mmg_fn_v_InitMmg)(unsigned char ucModuleId, unsigned char ucMaxBlocksNb, unsigned long ulMaxNbDynamicMalloc);
ACP_FUNC void (*Mmg_fn_vInitSpecificBlock)(unsigned char _ucBlockId, unsigned char _ucModuleId,
	tdstBlockInfoPriv *_p_stMyBlocksInfo, unsigned long _ulSize, unsigned long _ulMaxNbStaticMalloc,
	unsigned char _ucAlignment, unsigned char _ucMode);