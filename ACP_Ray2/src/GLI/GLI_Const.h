#pragma once

/**********************************
 * Constant values for GLI module
 **********************************/

#define GLI_C_lIsTextured								1
#define GLI_C_lIsGouraud								2 /* else is flat */
#define GLI_C_lIsNotWired								4 /* so is solid */
#define GLI_C_lIsNotGrided								8
#define GLI_C_lIsNotDotted								0x10 /* means draw only the points */
#define GLI_C_lIsNotOutlined							0x20 /* means draw only the points */
#define GLI_C_lIsNotDrawCollideInformation				0x40 /* means draw collision spheres & box */
#define GLI_C_lIsNotDrawCollideInformationLight			0x80 /* draw only periferical */
#define GLI_C_lIsNotForceDefaultMaterial				0x100 /* draw only periferical */
#define GLI_C_lIsNotForceColorMaterial					0x200 /* draw triangles with a single color set in the material */
#define GLI_C_lIsTestingBackface						0x400
#define GLI_C_lIsNotDrawingSuperObjectBoundingVolume	0x800
#define GLI_C_lIsUseRLI									0x1000
#define GLI_C_lIsNotComputeSpecular						0x2000
#define GLI_C_lHasNotPriority							0x4000 /* 14th bit: means this object has no priority */
#define GLI_C_lIsUseStaticLights						0x8000
#define GLI_C_lIsUseShadow								0x10000
#define GLI_C_lCameraIsUnderWater						0x20000
#define GLI_C_lNotForceZSorting							0x40000
#define GLI_C_lNotInvertBackfaces						0x80000
#define GLI_C_lNotHideWhatIsUnderWater					0x100000
#define GLI_C_lDrawNothing								0x200000
#define GLI_C_lIsNotChromed								0x400000
#define GLI_C_lIsNotVisibleInRealWorld					0x800000
#define GLI_C_lIsNotVisibleInSymetricWorld				0x1000000
#define GLI_C_lIsNotDrawingInMirror						0x2000000
#define GLI_C_lIsNotLightAlphaSensitive					0x4000000
#define GLI_C_lIsWriteZBuffer							0x8000000
#define GLI_C_lHasNoMirror								0x10000000
#define GLI_C_lIsNotSinusEffectOnRLI					0x20000000
#define GLI_C_lIsEnableZSorting							0x40000000
#define GLI_C_lHasNotSinusEffect						0x80000000

#define GLI_C_lIsSolid (								\
	GLI_C_lIsNotForceDefaultMaterial +					\
	GLI_C_lIsNotDrawCollideInformationLight +			\
	GLI_C_lIsNotDrawCollideInformation +				\
	GLI_C_lIsNotWired +									\
	GLI_C_lIsNotGrided +								\
	GLI_C_lIsNotForceColorMaterial +					\
	GLI_C_lIsNotDotted +								\
	GLI_C_lIsTestingBackface +							\
	GLI_C_lNotForceZSorting +							\
	GLI_C_lNotInvertBackfaces +							\
	GLI_C_lNotHideWhatIsUnderWater +					\
	GLI_C_lIsNotChromed +								\
	GLI_C_lIsNotOutlined +								\
	GLI_C_lIsNotVisibleInRealWorld +					\
	GLI_C_lIsNotLightAlphaSensitive +					\
	GLI_C_lIsNotVisibleInSymetricWorld +				\
	GLI_C_lIsEnableZSorting +							\
	GLI_C_lIsWriteZBuffer )
 
#define GLI_C_lAllIsEnable 0xFFFFFFFF

#define C_lMaxIndexInViewingList	20000
#define C_lGouraudLineElement		((GLI_C_lIsSolid | GLI_C_lIsGouraud) - GLI_C_lIsNotWired)
#define C_lGouraudElement			(GLI_C_lIsSolid | GLI_C_lIsGouraud)
#define C_lTexturedElement			(GLI_C_lIsSolid | GLI_C_lIsTextured | GLI_C_lIsGouraud)
#define C_lTexturedElementGrid		((GLI_C_lIsSolid | GLI_C_lIsTextured | GLI_C_lIsGouraud) - GLI_C_lIsNotGrided)
#define C_lBoldLineElement			(GLI_C_lIsNotDotted)
#define C_lBigDotsElement			(0)
