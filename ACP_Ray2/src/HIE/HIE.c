#include "HIE.h"
#include "HIE_StdGame.h"


///////////////////////////
//
// HIE - Object Hierarchy
// 
///////////////////////////


ACP_API void (*HIE_fn_vChangeFather)(HIE_tdstSuperObject *p_stSpo, HIE_tdstSuperObject *p_stNewFather, BYTE bFirstChild) = 0x45C080;


/* Declared in HIE_StdGame.h */
ACP_API HIE_tdstObjectType *const HIE_g_stObjectTypes = (HIE_tdstObjectType *)0x5013E0;
