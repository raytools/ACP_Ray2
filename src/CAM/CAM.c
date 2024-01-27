/****************************************************************************
*
* CAM - Camera module (technically part of GAM)
*
****************************************************************************/

#include "CAM.h"


void (*CAM_fn_vUpdateTargetPosition)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x413E30);

void (*CAM_fn_vInitCompleteCineinfo)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x413DB0);
void (*CAM_fn_vSetCineinfoWorkFromCurrent)( CAM_tdstCineinfo *hCineinfo ) = OFFSET(0x4140A0);
