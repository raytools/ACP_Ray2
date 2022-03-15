#pragma once

#include "../HIE/HIE.h"
#include "../GLI/GLI.h"
#include "../GLI/GLD.h"
#include "../FIL/FIL.h"
#include "../TMR/TMR.h"
#include "../MTH.h"
#include "../apidef.h"


/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/


#define MAX_NAME_LEVEL 30

typedef struct GAM_tdstEngineStructure GAM_tdstEngineStructure;
typedef struct GAM_tdstLanguageStructure GAM_tdstLanguageStructure;

typedef enum GAM_tdeEngineMode
{
	EM_ModeInvalid = 0,
	EM_ModeStartingProgram,
	EM_ModeStoppingProgram,
	EM_ModeEnterGame,
	EM_ModeQuitGame,
	EM_ModeEnterLevel,
	EM_ModeChangeLevel,
	EM_ModeDeadLoop,
	EM_ModePlayerDead,
	EM_ModePlaying,
	EM_NbTotalEngineMode
} GAM_tdeEngineMode;

typedef enum GAM_tdeInputMode
{
	IM_Normal,
	IM_Commands,
	IM_NbOfMode
} GAM_tdeInputMode;

typedef enum GAM_tdeDisplayFixMode
{
	DFM_DisplayAll			= 0xFF,
	DFM_DisplayHitPoints	= 0x01,
	DFM_DisplayGameSave		= 0x02,
	DFM_DisplayNothing		= 0x00
} GAM_tdeDisplayFixMode;


// Engine structure
ACP_API extern GAM_tdstEngineStructure *const GAM_g_stEngineStructure;

ACP_API extern HIE_tdstSuperObject **const GAM_pp_stDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const GAM_pp_stInactiveDynamicWorld;
ACP_API extern HIE_tdstSuperObject **const GAM_pp_stFatherSector;


ACP_API extern BYTE (*GAM_fn_ucGetEngineMode)( void );
ACP_API extern void (*GAM_fn_vChangeEngineMode)( BYTE ucMode );
ACP_API extern char * (*GAM_fn_p_szGetLevelName)( void );
ACP_API extern void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, BYTE bSaveGame );
ACP_API extern HANDLE (*GAM_fn_hGetWindowHandle)( void );


struct GAM_tdstEngineStructure
{
	char eEngineMode;
	char szLevelName[MAX_NAME_LEVEL];
	char szNextLevelName[MAX_NAME_LEVEL];
	char szFirstLevelName[MAX_NAME_LEVEL];

	BYTE eInputMode;
	BYTE eDisplayFixMode;
	DWORD ulDisplayMode;

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

	LST_M_AnchorTo(GLI_tdstNodeCamera) hCameraList;
	HIE_tdstFamilyList hFamilyList;

	LST_M_AnchorTo(HIE_tdstAlwaysActiveCharacter) hAlwaysActiveCharactersList;
	HIE_tdstSuperObject *g_hMainActor;
	HIE_tdstSuperObject *g_hNextMainActor;

	HIE_tdstSuperObject *g_hStdCamCharacter;

	GAM_tdstLanguageStructure *p_stLanguageTable;
	LST_M_AnchorTo(FIL_tdstFileNameListElement) *hLevelNameList;

	POS_tdstCompletePosition stMainCharacterPosition;
	POS_tdstCompletePosition stMainCameraPosition;

	int lSubMapNumber;

	BYTE bEngineIsInPaused;
	BYTE bEngineHasInPaused;

	char a_szLevelName[80][MAX_NAME_LEVEL];
	BYTE ucNumberOfLevels;
	BYTE ucCurrentLevel;

	BYTE ucPreviousLevel;
	BYTE ucExitIdToQuitPrevLevel;
	BYTE ucLevelGlobalCounter;

	ACP_tdxBool xDemoMode;

	BYTE ucCurrentLanguage;
	BYTE ucNbLanguages;

	ACP_tdxBool bEngineFrozen; /* if true, unprotected characters are not treated in the engine loop */
	ACP_tdxBool bResurrection;

	char cCameraMode;
};

struct GAM_tdstLanguageStructure
{
	char szLanguageCode[20];
	char szLanguageText[20];
};
