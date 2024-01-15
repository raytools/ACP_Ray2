/****************************************************************************
 *
 * IPT - Input module
 *
 ****************************************************************************/

#include "IPT.h"


IPT_tdstInput *const IPT_g_stInputStructure = OFFSET(0x509E60);

void (*IPT_fn_vResetInputEntry)( void ) = OFFSET(0x42E090);
