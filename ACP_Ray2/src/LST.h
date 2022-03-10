#pragma once

#include "basedef.h"


/****************************************************************************
 *
 * LST - Linked List module
 *
 * Note: As in the original CPA implementation, "dynamic" lists
 * are double-linked, whereas "static" lists are single-linked.
 *
 ****************************************************************************/


/*
 * Dynamic (double linked) list declaration
 */

#define LST_M_AnchorTo(Type) struct LST_tdstAnchorTo_##Type

#define LST_M_DynamicAnchorDecl(Type) LST_M_AnchorTo(Type)

#define LST_M_DynamicParentDecl(Type)										   \
	Type hFirstElement;														   \
	Type hLastElement;														   \
	long lNbOfElements;

#define LST_M_DynamicChildDecl(Type, ParentType)							   \
	Type hNextBrother;														   \
	Type hPrevBrother;														   \
	ParentType hFather;

#define LST_M_DynamicElementDecl(Type)										   \
	Type hNextBrother;														   \
	Type hPrevBrother;														   \
	LST_M_AnchorTo(Type)* hFather;

#define LST_M_DynamicListDecl(Type)											   \
	LST_M_DynamicAnchorDecl(Type)											   \
	{																		   \
		LST_M_DynamicParentDecl(Type)										   \
	}


/*
 * Dynamic list access functions
 */

#define LST_M_DynamicGetNextElement( hElement ) ((hElement)->hNextElement)
#define LST_M_DynamicGetPrevElement( hElement ) ((hElement)->hPrevElement)
#define LST_M_DynamicGetFather( hElement ) ((hElement)->hFather)

#define LST_M_DynamicGetFirstElement( hAnchor ) ((hAnchor)->hFirstElement)
#define LST_M_DynamicGetLastElement( hAnchor ) ((hAnchor)->hLastElement)
#define LST_M_DynamicGetNbOfElements( hAnchor ) ((hAnchor)->lNbOfElements)

// Initialise anchor of list
#define LST_M_DynamicInitAnchor( hAnchor )									   \
do {																		   \
	LST_M_DynamicGetFirstElement(hAnchor) = NULL;							   \
	LST_M_DynamicGetLastElement(hAnchor) = NULL;							   \
	LST_M_DynamicGetNbOfElements(hAnchor) = 0;								   \
} while ( 0 )

// Initialise list element
#define LST_M_DynamicInitElement( hElement )								   \
do {																		   \
	LST_M_DynamicGetNextElement(hElement) = NULL;							   \
	LST_M_DynamicGetPrevElement(hElement) = NULL;							   \
	LST_M_DynamicGetFather(hElement) = NULL;								   \
} while ( 0 )

// Remove element from list
#define LST_M_DynamicIsolate( hElement )																			   \
do {																												   \
	if ( LST_M_DynamicGetNextElement(hElement) != NULL )															   \
		LST_M_DynamicGetPrevElement(LST_M_DynamicGetNextElement(hElement)) = LST_M_DynamicGetPrevElement(hElement)	   \
																													   \
	if ( LST_M_DynamicGetPrevElement(hElement) != NULL )															   \
		LST_M_DynamicGetNextElement(LST_M_DynamicGetPrevElement(hElement)) = LST_M_DynamicGetNextElement(hElement)	   \
																													   \
	if ( LST_M_DynamicGetFather(hElement) != NULL )																	   \
	{																												   \
		if ( LST_M_DynamicGetFirstElement(LST_M_DynamicGetFather(hElement)) == (hElement) )							   \
			LST_M_DynamicGetFirstElement(LST_M_DynamicGetFather(hElement)) = LST_M_DynamicGetNextElement(hElement);	   \
																													   \
		if ( LST_M_DynamicGetLastElement(LST_M_DynamicGetFather(hElement)) == (hElement) )							   \
			LST_M_DynamicGetLastElement(LST_M_DynamicGetFather(hElement)) = LST_M_DynamicGetPrevElement(hElement);	   \
																													   \
		LST_M_DynamicGetNbOfElements(LST_M_DynamicGetFather(hElement))--;											   \
	}																												   \
																													   \
	LST_M_DynamicInitElement(hElement);																				   \
} while ( 0 )

// Add element at the beginning of the list
#define LST_M_DynamicAddHead( hAnchor, hElement )																	   \
do {																												   \
	LST_M_DynamicIsolate(hElement);																					   \
																													   \
	LST_M_DynamicGetFather(hElement) = (hAnchor);																	   \
	LST_M_DynamicGetNextElement(hElement) = LST_M_DynamicGetFirstElement(hAnchor);									   \
																													   \
	if ( !LST_M_DynamicGetLastElement(hAnchor) )																	   \
		LST_M_DynamicGetLastElement(hAnchor) = (hElement);															   \
	else																											   \
		LST_M_DynamicGetPrevElement(LST_M_DynamicGetFirstElement(hAnchor)) = (hElement);							   \
																													   \
	LST_M_DynamicGetFirstElement(hAnchor) = (hElement);																   \
	LST_M_DynamicGetNbOfElements(hAnchor)++;																		   \
} while ( 0 )

// Add element at the end of the list
#define LST_M_DynamicAddTail( hAnchor, hElement )																	   \
do {																												   \
	LST_M_DynamicIsolate(hElement);																					   \
																													   \
	LST_M_DynamicGetFather(hElement) = (hAnchor);																	   \
	LST_M_DynamicGetPrevElement(hElement) = LST_M_DynamicGetLastElement(hAnchor);									   \
																													   \
	if ( !LST_M_DynamicGetFirstElement(hAnchor) )																	   \
		LST_M_DynamicGetFirstElement(hAnchor) = (hElement);															   \
	else																											   \
		LST_M_DynamicGetNextElement(LST_M_DynamicGetLastElement(hAnchor)) = (hElement);								   \
																													   \
	LST_M_DynamicGetLastElement(hAnchor) = (hElement);																   \
	LST_M_DynamicGetNbOfElements(hAnchor)++;																		   \
} while ( 0 )

// Iterate over all elements of the list
#define LST_M_DynamicForEach( hAnchor, hElement )							   \
for (																		   \
	(hElement) = LST_M_DynamicGetFirstElement(hAnchor);						   \
	(hElement);																   \
	(hElement) = LST_M_DynamicGetNextElement(hElement)						   \
)

// Iterate over all elements of the list, with index variable
#define LST_M_DynamicForEachIndex( hAnchor, hElement, i )					   \
for (																		   \
	(i) = 0, (hElement) = LST_M_DynamicGetFirstElement(hAnchor);			   \
	(hElement);																   \
	(i)++, (hElement) = LST_M_DynamicGetNextElement(hElement)				   \
)