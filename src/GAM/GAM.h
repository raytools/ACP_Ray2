/****************************************************************************
 *
 * GAM - Main engine module
 *
 ****************************************************************************/

#pragma once

#include "GAM_Def.h"
#include "GAM_StdGame.h"
#include "GAM_ZDx.h"
#include "GAM_3dData.h"

#include "HIE/HIE.h"
#include "GLI/GLI.h"
#include "GLI/GLD.h"
#include "FIL/FIL.h"
#include "TMR/TMR.h"
#include "LST.h"
#include "basedef.h"
#include "apidef.h"


#define MAX_NAME_LEVEL 30

/**
 * Engine modes specify if the game is running, or if some other initialization
 * or deinitialization step is taking place.
 * 
 * Note: Odd values are init steps, handled by GAM_fn_vChooseTheGoodInit()
 * Even values are handled by GAM_fn_vChooseTheGoodDesInit()
 */
typedef unsigned char GAM_tdeEngineMode;
enum GAM_tdeEngineMode_
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

typedef unsigned char GAM_tdeInputMode;
enum GAM_tdeInputMode_
{
	E_IM_Normal,
	E_IM_Commands,
	E_IM_NbOfMode
};

typedef unsigned char GAM_tdeDisplayFixMode;
enum GAM_tdeDisplayFixMode_
{
	E_DFM_DisplayAll			= 0xFF,
	E_DFM_DisplayHitPoints		= 0x01,
	E_DFM_DisplayGameSave		= 0x02,
	E_DFM_DisplayNothing		= 0x00
};

/**
 * Defines a list of languages used by the game.
 * For actual localized strings, see FON_tdstLanguage in FON.h
 */
typedef struct GAM_tdstLanguageStructure
{
	char szLanguageCode[20];
	char szLanguageText[20];
}
GAM_tdstLanguageStructure;

/**
 * Contains fundamental information about the engine and its current state.
 */
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

/** The engine structure */
ACP_VAR GAM_tdstEngineStructure *const GAM_g_stEngineStructure;

/** Commandline args passed to the game on startup */
ACP_VAR char const *const GAM_g_szCmdLine;

/** All currently active objects (within the active sectors) */
ACP_VAR HIE_tdstSuperObject **const GAM_g_p_stDynamicWorld;
/** All inactive objects (within inactive sectors of the map) */
ACP_VAR HIE_tdstSuperObject **const GAM_g_p_stInactiveDynamicWorld;
/** Static models, map geometry and collision */
ACP_VAR HIE_tdstSuperObject **const GAM_g_p_stFatherSector;

ACP_VAR unsigned char *const GAM_g_ucIsEdInGhostMode;
ACP_VAR char *const GAM_g_cIsLevelOk;

/*
 * Functions
 */

ACP_FUNC GAM_tdeEngineMode (*GAM_fn_ucGetEngineMode)( void );
ACP_FUNC void (*GAM_fn_vChangeEngineMode)( GAM_tdeEngineMode ucMode );

/** App init - reads config files and initializes all modules */
ACP_FUNC void (*GAM_fn_vInitEngineWhenInitApplication)( void );

/**
 * Called on E_EM_ModeStartingProgram. Initializes the engine structure,
 * graphics library, reads Game.dsb, loads Fix, etc.
 */
ACP_FUNC void (*GAM_fn_vFirstInitEngine)( void );
/** Called on E_EM_ModeEnterGame, initializes the first map. */
ACP_FUNC void (*GAM_fn_vInitGameLoop)( void );
/** Called on E_EM_ModeEnterLevel, loads the current map. */
ACP_FUNC void (*GAM_fn_vInitLevelLoop)( void );

/**
 * Handles all initialization modes.
 * Always executed at the beginning of the engine loop.
 */
ACP_FUNC void (*GAM_fn_vChooseTheGoodInit)( void );
/**
 * Handles all deinitialization modes.
 * Always executed at the end of the engine loop.
 */
ACP_FUNC void (*GAM_fn_vChooseTheGoodDesInit)( void );

/**
 * One step of the engine. Handles object hierarchy, AI scripts, etc.
 * Use this for any logic that needs to run on each frame.
 * 
 * Note: For the purpose of drawing overlays, use AGO_vDisplayGAUGES() instead
 */
ACP_FUNC void (*GAM_fn_vEngine)( void );

/** Pauses the engine. (also saves the engine timer and frame count) */
ACP_FUNC void (*GAM_fn_vSetEngineInPaused)( void );
/** Unpauses the engine. (also restores the engine timer and frame count) */
ACP_FUNC void (*GAM_fn_vResetEngineFromPaused)( void );

ACP_FUNC void (*GAM_fn_vSaveEngineClock)( void );
ACP_FUNC void (*GAM_fn_vLoadEngineClock)( void );
ACP_FUNC void (*GAM_fn_vActualizeEngineClock)( void );

ACP_FUNC char * (*GAM_fn_p_szGetLevelName)( void );
ACP_FUNC void (*GAM_fn_vSetLevelName)( char const *szName );
ACP_FUNC char * (*GAM_fn_p_szGetNextLevelName)( void );
ACP_FUNC void (*GAM_fn_vSetNextLevelName)( char const *szName );
ACP_FUNC char * (*GAM_fn_p_szGetFirstLevelName)( void );
ACP_FUNC void (*GAM_fn_vSetFirstLevelName)( char const *szName );

/**
 * Changes the current map.
 * 
 * @param szLevelName Name of the map (will parse section IDs)
 * @param bSaveGame Show the yes/no save prompt
 */
ACP_FUNC void (*GAM_fn_vAskToChangeLevel)( char const *szLevelName, ACP_tdxBool bSaveGame );

ACP_FUNC HANDLE (*GAM_fn_hGetWindowHandle)( void );
ACP_FUNC BOOL (*GAM_fn_bCreateMainWindow)( HANDLE hInstance, int nShowCmd );
ACP_FUNC long (CALLBACK *GAM_fn_WndProc)( HANDLE hWnd, unsigned int uMsg, unsigned int wParam, long lParam );