#pragma once

#include "vec.h"

/// 2D点 - int坐标
typedef struct CrPointC {
    int x;
    int y;
} CrPoint;

/// 2D点 - float坐标
typedef struct CrPointFC {
    float x;
    float y;
} CrPointF;

/// 2D点 - 浮点数坐标
typedef struct CrPointDC {
    double x;
    double y;
} CrPointD;


/// 2D尺寸 - int坐标
typedef struct CrSizeC {
    int width;
    int height;
} CrSize;


/// 2D尺寸 - float坐标
typedef struct CrSizeFC {
    float width;
    float height;
} CrSizeF;


/// 矩形 - double坐标
typedef struct CrSizeDC {
    double width;
    double height;
} CrSizeD;


/// 矩形 - int坐标
typedef struct CrRectC {
    int x;
    int y;
    int width;
    int height;
} CrRect;

/// 矩形 - float坐标
typedef struct CrRectFC {
    float x;
    float y;
    float width;
    float height;
} CrRectF;

/// 矩形 - double数坐标
typedef struct CrRectDC {
    double x;
    double y;
    double width;
    double height;
} CrRectD;


/// 点集合 - int坐标
cr_vec_def(CrPoint, CrPoints);

/// 点集合 - float坐标
cr_vec_def(CrPointF, CrPointFs);

/// 点集合 - double坐标
cr_vec_def(CrPointD, CrPointDs);
