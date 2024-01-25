/****************************************************************************
*
* GMT - Game material module
*
****************************************************************************/

#include "GMT.h"


GMT_tdstGameMaterial * (*GMT_fn_hCreateGameMaterial)( void ) = OFFSET(0x42DAF0);
void (*GMT_fn_vSetVisualMaterial)( GMT_tdstGameMaterial *hGameMat, GLI_tdstMaterial *hVisualMat ) = OFFSET(0x42DB20);
