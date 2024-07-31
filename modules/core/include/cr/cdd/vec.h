#pragma once

///
/// @brief: C语言向量
///
/// 用C语言结构和宏模仿C++的泛型vector, 可以有两种操作模式:
/// - C模式, 用宏操作, 参见: cr/vec_op.h
/// - C++模式, 用泛型操作, 参见: cr/vec_op.hpp

#include "basic.h"

/// 定义指定类型的向量
#define cr_vec_def(T_, Name_) \
typedef struct { \
    U32 capacity; \
    U32 size; \
    T_ *data; \
} Name_



/// 无符号字节向量
cr_vec_def(U8, CrU8s);
