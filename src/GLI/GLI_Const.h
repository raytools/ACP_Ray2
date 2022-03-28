/****************************************************************************
 * Constant values for GLI module
 ****************************************************************************/

#pragma once


#define GLI_C_TEXIsUnallocated 0xC0DE0005
#define GLI_C_lNBMaxOfTextures 1024

/*
 * Material flags
 */

#define GLI_C_Mat_lIsTextured								1
#define GLI_C_Mat_lIsGouraud								2 /* else is flat */
#define GLI_C_Mat_lIsNotWired								4 /* so is solid */
#define GLI_C_Mat_lIsNotGrided								8
#define GLI_C_Mat_lIsNotDotted								0x10 /* means draw only the points */
#define GLI_C_Mat_lIsNotOutlined							0x20 /* means draw only the points */
#define GLI_C_Mat_lIsNotDrawCollideInformation				0x40 /* means draw collision spheres & box */
#define GLI_C_Mat_lIsNotDrawCollideInformationLight			0x80 /* draw only periferical */
#define GLI_C_Mat_lIsNotForceDefaultMaterial				0x100 /* draw only periferical */
#define GLI_C_Mat_lIsNotForceColorMaterial					0x200 /* draw triangles with a single color set in the material */
#define GLI_C_Mat_lIsTestingBackface						0x400
#define GLI_C_Mat_lIsNotDrawingSuperObjectBoundingVolume	0x800
#define GLI_C_Mat_lIsUseRLI									0x1000
#define GLI_C_Mat_lIsNotComputeSpecular						0x2000
#define GLI_C_Mat_lHasNotPriority							0x4000 /* 14th bit: means this object has no priority */
#define GLI_C_Mat_lIsUseStaticLights						0x8000
#define GLI_C_Mat_lIsUseShadow								0x10000
#define GLI_C_Mat_lCameraIsUnderWater						0x20000
#define GLI_C_Mat_lNotForceZSorting							0x40000
#define GLI_C_Mat_lNotInvertBackfaces						0x80000
#define GLI_C_Mat_lNotHideWhatIsUnderWater					0x100000
#define GLI_C_Mat_lDrawNothing								0x200000
#define GLI_C_Mat_lIsNotChromed								0x400000
#define GLI_C_Mat_lIsNotVisibleInRealWorld					0x800000
#define GLI_C_Mat_lIsNotVisibleInSymetricWorld				0x1000000
#define GLI_C_Mat_lIsNotDrawingInMirror						0x2000000
#define GLI_C_Mat_lIsNotLightAlphaSensitive					0x4000000
#define GLI_C_Mat_lIsWriteZBuffer							0x8000000
#define GLI_C_Mat_lHasNoMirror								0x10000000
#define GLI_C_Mat_lIsNotSinusEffectOnRLI					0x20000000
#define GLI_C_Mat_lIsEnableZSorting							0x40000000
#define GLI_C_Mat_lHasNotSinusEffect						0x80000000

#define GLI_C_Mat_lIsSolid (								\
	GLI_C_Mat_lIsNotForceDefaultMaterial +					\
	GLI_C_Mat_lIsNotDrawCollideInformationLight +			\
	GLI_C_Mat_lIsNotDrawCollideInformation +				\
	GLI_C_Mat_lIsNotWired +									\
	GLI_C_Mat_lIsNotGrided +								\
	GLI_C_Mat_lIsNotForceColorMaterial +					\
	GLI_C_Mat_lIsNotDotted +								\
	GLI_C_Mat_lIsTestingBackface +							\
	GLI_C_Mat_lNotForceZSorting +							\
	GLI_C_Mat_lNotInvertBackfaces +							\
	GLI_C_Mat_lNotHideWhatIsUnderWater +					\
	GLI_C_Mat_lIsNotChromed +								\
	GLI_C_Mat_lIsNotOutlined +								\
	GLI_C_Mat_lIsNotVisibleInRealWorld +					\
	GLI_C_Mat_lIsNotLightAlphaSensitive +					\
	GLI_C_Mat_lIsNotVisibleInSymetricWorld +				\
	GLI_C_Mat_lIsEnableZSorting +							\
	GLI_C_Mat_lIsWriteZBuffer )
 
#define GLI_C_lAllIsEnable				0xFFFFFFFF
#define GLI_C_lMaxIndexInViewingList	20000


/*
 * Texture flags
 */

#define GLI_C_Mat_lGouraudLineElement		((GLI_C_Mat_lIsSolid | GLI_C_Mat_lIsGouraud) - GLI_C_Mat_lIsNotWired)
#define GLI_C_Mat_lGouraudElement			(GLI_C_Mat_lIsSolid | GLI_C_Mat_lIsGouraud)
#define GLI_C_Mat_lTexturedElement			(GLI_C_Mat_lIsSolid | GLI_C_Mat_lIsTextured | GLI_C_Mat_lIsGouraud)
#define GLI_C_Mat_lTexturedElementGrid		((GLI_C_Mat_lIsSolid | GLI_C_Mat_lIsTextured | GLI_C_Mat_lIsGouraud) - GLI_C_Mat_lIsNotGrided)
#define GLI_C_Mat_lBoldLineElement			(GLI_C_Mat_lIsNotDotted)
#define GLI_C_Mat_lBigDotsElement			(0)


#define GLI_C_Tex_lTiledTexture             0x00000001
#define GLI_C_Tex_lNZTexture                0x00000002
#define GLI_C_Tex_lMipMapTexture            0x00000004
#define GLI_C_Tex_lAlphaTexture             0x00000008
#define GLI_C_Tex_lNZFilteredTexture        0x00000010
#define GLI_C_Tex_lAddTransparencyTexture   0x00000020
#define GLI_C_Tex_lNoZBufferWriteTexture    0x00000040
#define GLI_C_Tex_lPaletteTexture           0x00000080
#define GLI_C_Tex_lAlphaTest                0x00000100
#define GLI_C_Tex_lAAATexture				0x00000200
#define GLI_C_Tex_lMAATexture               0x00000400

#define GLI_C_Tex_lProceduralTexture        0x00000800
 
#define GLI_C_Tex_lTGATexture               0x80000000
#define GLI_C_Tex_lBMPTexture               0x40000000


/*
 * Cycling mode (clamp and mirror)
 */

#define GLI_C_lCyclingU					 1
#define GLI_C_lCyclingV					 2
#define GLI_C_lCyclingUV				 3

#define GLI_C_lMirrorU					 4
#define GLI_C_lMirrorV					 8
#define GLI_C_lMirrorUV					12
#define GLI_C_lSpecialMirrorForShadow	16


/*
 * Texture quality
 */

#define GLI_C_TEX_QNORMAL       20
#define GLI_C_TEX_QHIGH         30
#define GLI_C_TEX_QLOW          10
