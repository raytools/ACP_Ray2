/****************************************************************************
 *
 * FHK - Function Hook module
 *
 ****************************************************************************/

#include "FHK.h"
#include "private/framework.h"
#include <detours.h>
//#include <intrin.h>

//#pragma intrinsic(_ReturnAddress)


long FHK_fn_lCreateHook( void **ppfnFunc, void *pfnHook )
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourAttach(ppfnFunc, pfnHook);

	return DetourTransactionCommit();
}

long FHK_fn_lDestroyHook( void **ppfnFunc, void *pfnHook )
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourDetach(ppfnFunc, pfnHook);

	return DetourTransactionCommit();
}
