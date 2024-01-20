/****************************************************************************
 *
 * FON - Font and Language module
 *
 ****************************************************************************/

#pragma once

#include "basedef.h"
#include "apidef.h"


typedef struct FON_tdstLanguage
{
	char **d_pTextsArray;
	unsigned short uwMaxNumberOfTexts;
	unsigned short uwNumberOfTexts;
}
FON_tdstLanguage;

typedef struct FON_tdstGeneral
{
	unsigned long ulElapsedTime;
	unsigned long hRandomHandle;

	unsigned short uwNumberOfLanguages;
	FON_tdstLanguage *d_sLanguageArray;
	FON_tdstLanguage *p_stCommonLanguage;
}
FON_tdstGeneral;


ACP_VAR FON_tdstGeneral *const FON_g_stGeneral;
