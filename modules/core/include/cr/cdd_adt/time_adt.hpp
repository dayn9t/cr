#pragma once

#include <cr/cdd/time.h>
#include <cr/system/time.hpp>

namespace cr {

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
}
