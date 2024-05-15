#pragma once

///
/// @brief: C语言向量操作
///
/// 用宏模仿C++的泛型操作
///

#include "cr/cdd/vec.h"
#include "assert.h"

/// 创建一个向量
#define cr_vec_new(T_, capacity_) { (capacity_), 0, (T_*)malloc(capacity_) }

/// 释放向量
#define cr_vec_release(arr_) do { free(arr_.data); arr_ = {}; } while (0)

/// 判断向量是否为空
#define cr_vec_empty(arr_) (arr_.size == 0)

/// 判断向量是否为空
#define cr_vec_free_space(arr_) (arr_.capacity - arr_.size)

/// 判断向量是否为满
#define cr_vec_full(arr_) (arr_.size == arr_.capacity)

/// 获取向量第i个元素
#define cr_vec_at(arr_, i_) (arr_.data[(i_)])

/// 获取向量第一个元素
#define cr_vec_first(arr_) cr_vec_at(arr_, 0)

/// 获取向量最后一个元素
#define cr_vec_last(arr_) cr_vec_at(arr_, arr_.size - 1)

/// 往向量中放入数据
#define cr_vec_put(arr_, data_, size_) do { \
    assert(size_ <= arr_.capacity); \
    memcpy(arr_.data, data_, size_); \
    arr_.size = size_; \
} while (0)

/// 复制向量
#define cr_vec_copy(arr1_, arr2_) cr_vec_put(arr2_, arr1_.data, arr1_.size);

/// 从向量中取出数据
#define cr_vec_get(arr_, data_, size_) do { \
    assert(size_ <= arr_.capacity); \
    memcpy(arr_.data, data_, size_); \
    arr_.size = size_; \
} while (0)

/// 向量中数据全部填充到目标缓冲区
#define cr_vec_fill(arr_, data_) cr_vec_get(arr_, data_, arr_.size)

/// 往向量尾部压入一个元素
#define cr_vec_push(arr_, element_) do { \
    assert(arr_.size < arr_.capacity);   \
    arr_.data[arr_.size] = element_; \
    arr_.size++; \
} while (0)

/// 从向量尾部弹出一个元素
#define cr_vec_pop(arr_) do { \
    assert(arr_.size > 0); \
    arr_.size--; \
} while (0)

/// 清除向量全部元素
#define cr_vec_clear(arr_) do { \
    arr_.size = 0; \
} while (0)

/// 用指定的值填充向量
#define cr_vec_set(arr_, value_) do { \
    for(SizeT i_ = 0; i_ < arr_.size; ++i_) cr_vec_at(arr_, i_) = value_; \
} while (0)
