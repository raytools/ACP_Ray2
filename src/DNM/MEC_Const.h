#pragma once

// Obstacle Types
#define MEC_C_WOT_ulError          0x80000000
#define MEC_C_WOT_ulNoObstacle     0x00000000
#define MEC_C_WOT_ulGround         0x00000001
#define MEC_C_WOT_ulWall           0x00000004
#define MEC_C_WOT_ulCeiling        0x00000010
#define MEC_C_WOT_ulWater          0x00000040
#define MEC_C_WOT_ulForceMobile    0x00000080
#define MEC_C_WOT_ulMobile         0x00010000
#define MEC_C_WOT_ulFather         0x00030000