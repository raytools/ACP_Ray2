#pragma once
#include <ACP_Ray2.h>

typedef struct WP_tdstArc {
  LST_M_DynamicElementDecl(WP_tdstArc)
  struct WP_tdstGraphNode *m_hNode;
  unsigned int m_ulCapability;
  unsigned int m_ulCapabilityInit;
  int m_lWeight;
  int m_lWeightInit;
} WP_tdstArc;

LST_M_DynamicListDecl(WP_tdstArc);

typedef struct WP_tdstListOfArc {
  LST_M_DynamicAnchorTo(WP_tdstArc);
} WP_tdstListOfArc;

typedef struct WP_tdstWayPoint {
  struct MTH3D_tdstVector m_stVertex;
  float m_xRadius;
  struct HIE_tdstSuperObject *m_hSuperObject;
} WP_tdstWayPoint;

typedef struct WP_tdstGraphNode {
  LST_M_DynamicElementDecl(WP_tdstGraphNode)
  struct WP_tdstWayPoint *m_hWayPoint;
  int m_lTypeOfWP;
  int m_lTypeOfWPInit;
  struct WP_tdstListOfArc *m_hListOfArc;
} WP_tdstGraphNode;

LST_M_DynamicListDecl(WP_tdstGraphNode);

typedef struct WP_tdstGraph {
  LST_M_DynamicAnchorTo(WP_tdstGraphNode) m_hListOfNode;
} WP_tdstGraph;