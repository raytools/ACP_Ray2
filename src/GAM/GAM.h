/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/

#pragma once

#include "HIE/HIE.h"
#include "GLI/GLI.h"
#include "GLI/GLD.h"
#include "FIL/FIL.h"
#include "TMR/TMR.h"
#include "LST.h"
#include "basedef.h"
#include "apidef.h"


#define MAX_NAME_LEVEL 30

enum GAM_tdeEngineMode
{
	E_EM_ModeInvalid = 0,
	E_EM_ModeStartingProgram,
	E_EM_ModeStoppingProgram,
	E_EM_ModeEnterGame,
	E_EM_ModeQuitGame,
	E_EM_ModeEnterLevel,
	E_EM_ModeChangeLevel,
	E_EM_ModeDeadLoop,
	E_EM_ModePlayerDead,
	E_EM_ModePlaying,
	E_EM_NbTotalEngineMode
};
typedef unsigned char GAM_tdeEngineMode;

enum GAM_tdeInputMode
{
	E_IM_Normal,
	E_IM_Commands,
	E_IM_NbOfMode
};
typedef unsigned char GAM_tdeInputMode;

enum GAM_tdeDisplayFixMode
{
	E_DFM_DisplayAll			= 0xFF,
	E_DFM_DisplayHitPoints		= 0x01,
	E_DFM_DisplayGameSave		= 0x02,
	E_DFM_DisplayNothing		= 0x00
};
typedef unsigned char GAM_tdeDisplayFixMode;

typedef struct GAM_tdstLanguageStructure
{
	char szLanguageCode[20];
	char szLanguageText[20];
}
GAM_tdstLanguageStructure;

typedef struct GAM_tdstEngineStructure
{
	GAM_tdeEngineMode eEngineMode;
	char szLevelName[MAX_NAME_LEVEL];
	char szNextLevelName[MAX_NAME_LEVEL];
	char szFirstLevelName[MAX_NAME_LEVEL];

	GAM_tdeInputMode eInputMode;
	GAM_tdeDisplayFixMode eDisplayFixMode;
	unsigned long ulDisplayMode;

	TMR_tdstEngineTimerStructure stEngineTimer;

	GLD_tdhDevice hGLDDevice;
	GLD_tdhViewport hGLDViewport;

	GLD_tdstViewportAttributes stViewportAttr;
	GLI_tdstCamera *p_stGameViewportCamera;

	void *hDrawSem;
	GLD_tdhViewport hGLDFixViewport;
	GLD_tdstViewportAttributes stFixViewportAttr;
	GLI_tdstSpecificAttributesFor3D stFixAttributes3D;
	GLI_tdstCamera *p_stFixCamera;

	GLI_tdstViewportManagement *a_hViewportArray;

	LST_M_DynamicAnchorTo(GLI_tdstNodeCamera) hCameraList;
	LST_M_DynamicAnchorTo(HIE_tdstFamilyList) hFamilyList;

	LST_M_DynamicAnchorTo(HIE_tdstAlwaysActiveCharacter) hAlwaysActiveCharactersList;
	HIE_tdstSuperObject *g_hMainActor;
	HIE_tdstSuperObject *g_hNextMainActor;

	HIE_tdstSuperObject *g_hStdCamCharacter;

	GAM_tdstLanguageStructure *p_stLanguageTable;
	LST_M_DynamicAnchorTo(FIL_tdstFileNameListElement) *hLevelNameList;

	POS_tdstCompletePosition stMainCharacterPosition;
	POS_tdstCompletePosition stMainCameraPosition;

	long lSubMapNumber;

	ACP_tdxBool bEngineIsInPaused;
	ACP_tdxBool bEngineHasInPaused;

	char a_szLevelName[80][MAX_NAME_LEVEL];
	unsigned char ucNumberOfLevels;
	unsigned char ucCurrentLevel;

	unsigned char ucPreviousLevel;
	unsigned char ucExitIdToQuitPrevLevel;
	unsigned char ucLevelGlobalCounter;

	ACP_tdxBool xDemoMode;

	unsigned char ucCurrentLanguage;
	unsigned char ucNbLanguages;

	ACP_tdxBool bEngineFrozen; /* if true, unprotected characters are not treated in the engine loop */
	ACP_tdxBool bResurrection;

	char cCameraMode;
}
GAM_tdstEngineStructure;


/*
 * Variables
 */

/* Engine structure */
ACP_VAR GAM_tdstEngineStructure *const GAM_g_stEngineStructure;

ACP_VAR HIE_tdstSuperObject **const GAM_pp_stDynamicWorld;
ACP_VAR HIE_tdstSuperObject **const GAM_pp_stInactiveDynamicWorld;
ACP_VAR HIE_tdstSuperObject **const GAM_pp_stFatherSector;


/*
 * Functions
 */

ACP_FUNC GAM_tdeEngineMode (*GAM_fn_ucGetEngineMode)( void );
ACP_FUNC void (*GAM_fn_vChangeEngineMode)( GAM_tdeEngineMode ucMode );
ACP_FUNC char * (*GAM_fn_p_szGetLevelName)( void );
ACP_FUNC void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, ACP_tdxBool bSaveGame );
ACP_FUNC void * (*GAM_fn_hGetWindowHandle)( void );
