#pragma once

#include "basic.h"

/// 时间点
typedef struct CrTimePointCS
{
    /// 从时间纪元开始的到现在的时间长度(纳秒)
    I64 nsecs;
} CrTimePoint;

/// 时间长度
typedef struct CrDurationCS
{
    /// 事件长度(纳秒)
    I64 nsecs;
} CrDuration;


/// 时间范围
typedef struct CrTimeRangeCS
{
    /// 开始时间
    CrTimePoint start;
    /// 结束时间
    CrTimePoint end;
} CrTimeRange;
