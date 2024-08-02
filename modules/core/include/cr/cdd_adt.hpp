#pragma once

///
/// @brief: C数据与C++类适配器
///
/// 实现了C数据与C++类的双向转换, 缺乏高级泛型技术支持, 丑:
/// - to_c: C++ => C
/// - from_c: C++ <= C, 大部分被 get_* 系列函数替代, 待定
///

#include "cdd_adt/geo_adt.hpp"
#include "cdd_adt/image_adt.hpp"
#include "cdd_adt/str_adt.hpp"
#include "cdd_adt/time_adt.hpp"
#include "cdd_adt/net_adt.hpp"

