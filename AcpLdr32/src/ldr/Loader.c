#include "Loader.h"
#include "../cfg/Config.h"
#include "../err/Errlog.h"
#include "../private/framework.h"


// Note: all paths are relative to the application directory

char const C_szAcpDir[] = ".\\ACP";
char const C_szModDir[] = ".\\ACP\\Mods";


LDR_API void LDR_fn_vInit( void )
{
	ERR_fn_vInit();

	if ( !CFG_fn_bReadCfgFile() )
		return;

	// TODO: load submodules etc
}
