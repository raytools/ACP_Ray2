#pragma once

#include <HIE/HIE.h>
#include <GLI/GLI.h>
#include <GLI/GLD.h>
#include <FIL/FIL.h>
#include <TMR/TMR.h>
#include <MTH.h>
#include <apidef.h>


///////////////////////
//
// GAM - Game Library
// 
///////////////////////


typedef struct GAM_tdstEngineStructure GAM_tdstEngineStructure;
typedef struct GAM_tdstLanguageStructure GAM_tdstLanguageStructure;

typedef enum GAM_tdeEngineMode
{
	e_EM_Preload = 1,
	e_EM_Shutdown = 2,
	e_EM_FilesLoaded = 3,
	// state 4?
	e_EM_LoadingScreen = 5,
	e_EM_ChangeLevel = 6,
	e_EM_DesinitDeathLoop = 7,
	e_EM_SnifThePlayerIsDead = 8,
	e_EM_Play = 9
} GAM_tdeEngineMode;


// Engine structure
ACP_API extern GAM_tdstEngineStructure *const GAM_g_stEngineStructure;


ACP_API extern BYTE (*GAM_fn_ucGetEngineMode)( void );
ACP_API extern void (*GAM_fn_vChangeEngineMode)( BYTE ucMode );
ACP_API extern char * (*GAM_fn_p_szGetLevelName)( void );
ACP_API extern void (*GAM_fn_vAskToChangeLevel)( char *szLevelName, BYTE bSaveGame );
ACP_API extern HANDLE (*GAM_fn_hGetWindowHandle)( void );


struct GAM_tdstEngineStructure
{
	char eEngineMode;
	char szLevelName[30];
	char szNextLevelName[30];
	char szFirstLevelName[30];
	BYTE eInputMode;
	BYTE eDisplayFixMode;
	DWORD ulDisplayMode;
	TMR_tdstEngineTimerStructure stEngineTimer;
	WORD hGLDDevice;
	WORD hGLDViewport;
	GLD_tdstViewportAttributes stViewportAttr;
	GLI_tdstCamera *p_stGameViewportCamera;
	int hDrawSem;
	WORD hGLDFixViewport;
	GLD_tdstViewportAttributes stFixViewportAttr;
	GLI_tdstSpecificAttributesFor3D stFixAttributes3D;
	GLI_tdstCamera *p_stFixCamera;
	GLI_tdstViewportManagement *a_hViewportArray;
	GLI_tdstNodeCameraList hCameraList;
	HIE_tdstFamilyList hFamilyList;
	HIE_tdstAlwaysActiveCharacterList hAlwaysActiveCharactersList;
	HIE_tdstSuperObject *g_hMainActor;
	HIE_tdstSuperObject *g_hNextMainActor;
	HIE_tdstSuperObject *g_hStdCamCharacter;
	GAM_tdstLanguageStructure *p_stLanguageTable;
	FIL_tdstFileNameList *hLevelNameList;
	MTH_tdstTransformation stMainCharacterPosition;
	MTH_tdstTransformation stMainCameraPosition;
	int lSubMapNumber;
	BYTE bEngineIsInPaused;
	BYTE bEngineHasInPaused;
	char a_szLevelName[80][30];
	BYTE ucNumberOfLevels;
	BYTE ucCurrentLevel;
	BYTE ucPreviousLevel;
	BYTE ucExitIdToQuitPrevLevel;
	BYTE ucLevelGlobalCounter;
	BYTE xDemoMode;
	BYTE ucCurrentLanguage;
	BYTE ucNbLanguages;
	BYTE bEngineFrozen;
	BYTE bResurrection;
	char cCameraMode;
};

struct GAM_tdstLanguageStructure
{
	char szLanguageCode[20];
	char szLanguageText[20];
};
