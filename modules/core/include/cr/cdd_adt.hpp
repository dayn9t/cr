#pragma once

///
/// @brief: C数据与C++类适配器
///
/// 实现了C数据与C++类的双向转换, 缺乏高级泛型技术支持, 丑:
/// - to_c: C++ => C
/// - from_c: C++ <= C, 大部分被 get_* 系列函数替代, 待定
///

#include <map>
#include <cr/cdd/geo.h>
#include <cr/cdd/image.h>
#include <cr/cdd/time.h>
#include <cr/cdd/net.h>

#include <cr/image/image.hpp>
#include <cr/system/time.hpp>

namespace cr {

    using StrMap = std::map<string, string>;

    /// 转化 CrTimePoint => TimePoint
    inline TimePoint get_time_point(const CrTimePoint& time_point)
    {
        return TimePoint(Duration(time_point.nsecs));
    }

    /// 转化 TimePoint => CrTimePoint
    inline CrTimePoint to_c(const TimePoint& time_point)
    {
        return CrTimePoint{ nsecs_since_epoch(time_point) };
    }

    /// 解析 URL 字符串
    bool parse_url(InString& url_str, CrEndpoint& endpoint, CrAuthInfo& auth, StrMap& params);


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


    /// 从C类型构造 - ImageChannel
    ImageChannel from_c(CrImageChannel &channel);

    /// ImageChannel 转化为C类型
    CrImageChannel to_c(ImageChannel &channel);

    /// 从C类型构造 -Image
    Image from_c(CrImage &image);

    /// 转化为C类型
    CrImage to_c(Image &channel);
}
