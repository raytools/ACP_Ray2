/****************************************************************************
 *
 * LST - Linked List module
 *
 ****************************************************************************/

/*
 * Note: As in the original CPA implementation, "dynamic" lists
 * are double-linked, whereas "static" lists are single-linked.
 */

#pragma once

#include "basedef.h"


#define LST_M_AnchorTo(Type, x) struct LST_tdstAnchorTo_##Type##_##x


/****************************************************************************
 * Dynamic (double linked) list
 ****************************************************************************/

#define LST_M_DynamicAnchorTo(Type) LST_M_AnchorTo(Type, Dyn)

#define LST_M_DynamicParentDecl(Type)										   \
	Type * hFirstElementDyn;												   \
	Type * hLastElementDyn;													   \
	long lNbOfElementsDyn;

#define LST_M_DynamicChildDecl(Type, ParentType)							   \
	Type * hNextBrotherDyn;													   \
	Type * hPrevBrotherDyn;													   \
	ParentType * hFatherDyn;

#define LST_M_DynamicElementDecl(Type)										   \
	Type * hNextBrotherDyn;													   \
	Type * hPrevBrotherDyn;													   \
	LST_M_DynamicAnchorTo(Type) * hFatherDyn;

#define LST_M_DynamicListDecl(Type)											   \
	LST_M_DynamicAnchorTo(Type)												   \
	{																		   \
		LST_M_DynamicParentDecl(Type)										   \
	}

/*
 * Dynamic list access macros
 */

#define LST_M_DynamicGetNextBrother( hElement ) ((hElement)->hNextBrotherDyn)
#define LST_M_DynamicGetPrevBrother( hElement ) ((hElement)->hPrevBrotherDyn)
#define LST_M_DynamicGetFather( hElement ) ((hElement)->hFatherDyn)

#define LST_M_DynamicGetFirstElement( hAnchor ) ((hAnchor)->hFirstElementDyn)
#define LST_M_DynamicGetLastElement( hAnchor ) ((hAnchor)->hLastElementDyn)
#define LST_M_DynamicGetNbOfElements( hAnchor ) ((hAnchor)->lNbOfElementsDyn)

/* Initialise anchor of list */
#define LST_M_DynamicInitAnchor( hAnchor )									   \
do {																		   \
	LST_M_DynamicGetFirstElement(hAnchor) = NULL;							   \
	LST_M_DynamicGetLastElement(hAnchor) = NULL;							   \
	LST_M_DynamicGetNbOfElements(hAnchor) = 0;								   \
} while ( 0 )

/* Initialise list element */
#define LST_M_DynamicInitElement( hElement )								   \
do {																		   \
	LST_M_DynamicGetNextBrother(hElement) = NULL;							   \
	LST_M_DynamicGetPrevBrother(hElement) = NULL;							   \
	LST_M_DynamicGetFather(hElement) = NULL;								   \
} while ( 0 )

/* Remove element from list */
#define LST_M_DynamicIsolate( hElement )																			   \
do {																												   \
	if ( LST_M_DynamicGetNextBrother(hElement) != NULL )															   \
		LST_M_DynamicGetPrevBrother(LST_M_DynamicGetNextBrother(hElement)) = LST_M_DynamicGetPrevBrother(hElement);	   \
																													   \
	if ( LST_M_DynamicGetPrevBrother(hElement) != NULL )															   \
		LST_M_DynamicGetNextBrother(LST_M_DynamicGetPrevBrother(hElement)) = LST_M_DynamicGetNextBrother(hElement);	   \
																													   \
	if ( LST_M_DynamicGetFather(hElement) != NULL )																	   \
	{																												   \
		if ( LST_M_DynamicGetFirstElement(LST_M_DynamicGetFather(hElement)) == (hElement) )							   \
			LST_M_DynamicGetFirstElement(LST_M_DynamicGetFather(hElement)) = LST_M_DynamicGetNextBrother(hElement);	   \
																													   \
		if ( LST_M_DynamicGetLastElement(LST_M_DynamicGetFather(hElement)) == (hElement) )							   \
			LST_M_DynamicGetLastElement(LST_M_DynamicGetFather(hElement)) = LST_M_DynamicGetPrevBrother(hElement);	   \
																													   \
		LST_M_DynamicGetNbOfElements(LST_M_DynamicGetFather(hElement))--;											   \
	}																												   \
																													   \
	LST_M_DynamicInitElement(hElement);																				   \
} while ( 0 )

/* Add element at the beginning of the list */
#define LST_M_DynamicAddHead( hAnchor, hElement )																	   \
do {																												   \
	LST_M_DynamicIsolate(hElement);																					   \
																													   \
	LST_M_DynamicGetFather(hElement) = (hAnchor);																	   \
	LST_M_DynamicGetNextBrother(hElement) = LST_M_DynamicGetFirstElement(hAnchor);									   \
																													   \
	if ( !LST_M_DynamicGetLastElement(hAnchor) )																	   \
		LST_M_DynamicGetLastElement(hAnchor) = (hElement);															   \
	else																											   \
		LST_M_DynamicGetPrevBrother(LST_M_DynamicGetFirstElement(hAnchor)) = (hElement);							   \
																													   \
	LST_M_DynamicGetFirstElement(hAnchor) = (hElement);																   \
	LST_M_DynamicGetNbOfElements(hAnchor)++;																		   \
} while ( 0 )

/* Add element at the end of the list */
#define LST_M_DynamicAddTail( hAnchor, hElement )																	   \
do {																												   \
	LST_M_DynamicIsolate(hElement);																					   \
																													   \
	LST_M_DynamicGetFather(hElement) = (hAnchor);																	   \
	LST_M_DynamicGetPrevBrother(hElement) = LST_M_DynamicGetLastElement(hAnchor);									   \
																													   \
	if ( !LST_M_DynamicGetFirstElement(hAnchor) )																	   \
		LST_M_DynamicGetFirstElement(hAnchor) = (hElement);															   \
	else																											   \
		LST_M_DynamicGetNextBrother(LST_M_DynamicGetLastElement(hAnchor)) = (hElement);								   \
																													   \
	LST_M_DynamicGetLastElement(hAnchor) = (hElement);																   \
	LST_M_DynamicGetNbOfElements(hAnchor)++;																		   \
} while ( 0 )

/* Iterate over all elements of the list */
#define LST_M_DynamicForEach( hAnchor, hElement )							   \
for (																		   \
	(hElement) = LST_M_DynamicGetFirstElement(hAnchor);						   \
	(hElement);																   \
	(hElement) = LST_M_DynamicGetNextBrother(hElement)						   \
)

/* Iterate over all elements of the list, with index variable */
#define LST_M_DynamicForEachIndex( hAnchor, hElement, i )					   \
for (																		   \
	(i) = 0, (hElement) = LST_M_DynamicGetFirstElement(hAnchor);			   \
	(hElement);																   \
	(i)++, (hElement) = LST_M_DynamicGetNextBrother(hElement)				   \
)

#define LST_M_DynamicGetNthElement( hAnchor, N, hElement, i )				   \
do {																		   \
	for (																	   \
		(i) = 0, (hElement) = LST_M_DynamicGetFirstElement(hAnchor);		   \
		(i) < (N);															   \
		(i)++, (hElement) = LST_M_DynamicGetNextBrother(hElement)			   \
	) ;																		   \
} while ( 0 )

#define LST_M_DynamicGetNthBrother( hFirstElement, N, hElement, i )			   \
do {																		   \
	for (																	   \
		(i) = 0, (hElement) = (hFirstElement);								   \
		(i) < (N);															   \
		(i)++, (hElement) = LST_M_DynamicGetNextBrother(hElement)			   \
	) ;																		   \
} while ( 0 )


/****************************************************************************
 * Static (single linked) list
 ****************************************************************************/

#define LST_M_StaticAnchorTo(Type) LST_M_AnchorTo(Type, Sta)

#define LST_M_StaticParentDecl(Type)										   \
	Type * hFirstElementSta;												   \
	Type * hLastElementSta;													   \
	long lNbOfElementsSta;

#define LST_M_StaticChildDecl(Type, ParentType)								   \
	Type * hNextBrotherSta;

#define LST_M_StaticElementDecl(Type)										   \
	Type * hNextBrotherSta;

#define LST_M_StaticListDecl(Type)											   \
	LST_M_StaticAnchorTo(Type)												   \
	{																		   \
		LST_M_StaticParentDecl(Type)										   \
	}

/*
 * Static list access macros
 */

#define LST_M_StaticGetNextBrother( hElement ) ((hElement)->hNextBrotherSta)

#define LST_M_StaticGetFirstElement( hAnchor ) ((hAnchor)->hFirstElementSta)
#define LST_M_StaticGetLastElement( hAnchor ) ((hAnchor)->hLastElementSta)
#define LST_M_StaticGetNbOfElements( hAnchor ) ((hAnchor)->lNbOfElementsSta)

/* Initialise anchor of list */
#define LST_M_StaticInitAnchor( hAnchor )									   \
do {																		   \
	LST_M_StaticGetFirstElement(hAnchor) = NULL;							   \
	LST_M_StaticGetLastElement(hAnchor) = NULL;								   \
	LST_M_StaticGetNbOfElements(hAnchor) = 0;								   \
} while ( 0 )

/* Initialise list element */
#define LST_M_StaticInitElement( hElement )									   \
do {																		   \
	LST_M_StaticGetNextBrother(hElement) = NULL;							   \
} while ( 0 )

/* TODO: Static list add/remove/foreach/nth macros */


/****************************************************************************
 * Static optimized list
 ****************************************************************************/

#define LST_M_OptAnchorTo(Type) LST_M_AnchorTo(Type, Opt)

#define LST_M_OptParentDecl(Type)											   \
	Type * hFirstElementOpt;												   \
	long lNbOfElementsOpt;

#define LST_M_OptChildDecl(Type, ParentType)
#define LST_M_OptElementDecl(Type)

#define LST_M_OptListDecl(Type)												   \
	LST_M_OptAnchorTo(Type)													   \
	{																		   \
		LST_M_OptParentDecl(Type)											   \
	}

/*
 * Optimized list access functions
 */

#define LST_M_OptGetNextBrother( hElement ) ((hElement)+1)
#define LST_M_OptGetPrevBrother( hElement ) ((hElement)-1)

#define LST_M_OptGetFirstElement( hAnchor ) ((hAnchor)->hFirstElementOpt)
#define LST_M_OptGetNbOfElements( hAnchor ) ((hAnchor)->lNbOfElementsOpt)

/* Initialise anchor of list */
#define LST_M_OptInitAnchor( hAnchor )										   \
do {																		   \
	LST_M_OptGetFirstElement(hAnchor) = NULL;								   \
	LST_M_OptGetNbOfElements(hAnchor) = 0;									   \
} while ( 0 )

/* Initialise list element */
#define LST_M_OptInitElement( hElement )

/* TODO: Optimized list add/remove/foreach/nth macros */

