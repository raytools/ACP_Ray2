/****************************************************************************
 *
 * RND - Random module
 *
 ****************************************************************************/

#pragma once

#include "apidef.h"
#include "MTH.h"

#define RND_C_MaxIndex 50

typedef unsigned long RND_tdxHandleToRandomIndex;

typedef struct RND_tdstRandom
{
  unsigned long ulSizeOfTable;
  unsigned long a_ulIndex[RND_C_MaxIndex];
  RND_tdxHandleToRandomIndex hLastUsedIndex;
  unsigned long ulMaxValueInTable;
  MTH_tdxReal xInverseMaxValueInTable;
  unsigned long *p_ulTable;
} RND_tdstRandom;


ACP_VAR RND_tdstRandom *const RND_g_stRandomStructure;


ACP_FUNC void(*RND_fn_vComputeRandomTable)();
ACP_FUNC void(*RND_fn_vRemapRandomTable)();