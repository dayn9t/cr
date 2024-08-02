#pragma once

///
/// @brief: C数据与C++类适配器
///
/// 实现了C数据与C++类的双向转换, 缺乏高级泛型技术支持, 丑:
/// - to_c: C++ => C
/// - from_c: C++ <= C, 大部分被 get_* 系列函数替代, 待定
///

#include <cr/cdd/geo.h>
#include <cr/geo.hpp>

namespace cr
{
    inline Point get_point(CrPoint p) { return {p.x, p.y}; }

    inline PointF get_point(CrPointF p) { return {p.x, p.y}; }

    inline PointD get_point(CrPointD p) { return {p.x, p.y}; }

    inline CrPoint to_c(Point p) { return {p.x, p.y}; }

    inline CrPointF to_c(PointF p) { return {p.x, p.y}; }

    inline CrPointD to_c(PointD p) { return {p.x, p.y}; }

    inline Size get_size(CrSize s) { return {s.width, s.height}; }

    inline SizeF get_size(CrSizeF s) { return {s.width, s.height}; }

    inline SizeD get_size(CrSizeD s) { return {s.width, s.height}; }

    inline CrSize to_c(Size s) { return {s.width, s.height}; }

    inline CrSizeF to_c(SizeF s) { return {s.width, s.height}; }

    inline CrSizeD to_c(SizeD s) { return {s.width, s.height}; }


    inline Rect get_rect(CrRect r) { return {r.x, r.y, r.width, r.height}; }

    inline RectF get_rect(CrRectF r) { return {r.x, r.y, r.width, r.height}; }

    inline RectD get_rect(CrRectD r) { return {r.x, r.y, r.width, r.height}; }

    inline CrRect to_c(Rect r) { return {r.x, r.y, r.width, r.height}; }

    inline CrRectF to_c(RectF r) { return {r.x, r.y, r.width, r.height}; }

    inline CrRectD to_c(RectD r) { return {r.x, r.y, r.width, r.height}; }
}
