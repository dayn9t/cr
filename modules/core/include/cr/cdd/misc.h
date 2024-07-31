#pragma once

#include "basic.h"

/// 颜色 - 字节
typedef struct CrColor_ {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} CrColor;


/// 缓冲区
typedef struct CrBuffer_ {
    U32t size;
    U8 *data;
} CrBuffer;


/// 缓冲区 - 只读产数据
typedef struct CrConstBuffer_ {
    U32t size;
    U8 *const data;

} CrConstBuffer;
