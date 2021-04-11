#pragma once


//////////////////////
//
// MTH - Math Module
//
//////////////////////


#define NULL ((void*)0)

#define FALSE 0
#define TRUE 1

typedef int BOOL;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

typedef struct MTH_tdstVector MTH_tdstVector;
typedef struct MTH_tdstVector4 Mth_tdstVector4;
typedef struct MTH_tdstMatrix MTH_tdstMatrix;


struct MTH_tdstVector
{
	float x;
	float y;
	float z;
};

struct MTH_tdstVector4
{
	float x;
	float y;
	float z;
	float w;
};

struct MTH_tdstMatrix
{
	int lTransformType;
	MTH_tdstVector vcPosition;

	float m_1_1;
	float m_1_2;
	float m_1_3;
	float m_2_1;
	float m_2_2;
	float m_2_3;
	float m_3_1;
	float m_3_2;
	float m_3_3;

	float scale_1_1;
	float scale_1_2;
	float scale_1_3;
	float scale_2_1;
	float scale_2_2;
	float scale_2_3;
	float scale_3_1;
	float scale_3_2;
	float scale_3_3;
};
