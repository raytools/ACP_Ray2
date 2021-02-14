#pragma once

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

typedef struct MTH_stVector
{
	float x;
	float y;
	float z;
} MTH_tdstVector;

typedef struct MTH_stVector4
{
	float x;
	float y;
	float z;
	float w;
} Mth_tdstVector4;

typedef struct MTH_stMatrix
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
} MTH_tdstMatrix;
