#pragma once

#include "basic.h"

/// 时间点
typedef struct
{
    /// 从时间纪元开始的到现在的时间长度(纳秒)
    I64 nsecs;
} CrTimePoint;

/// 时间长度
typedef struct
{
    /// 事件长度(纳秒)
    I64 nsecs;
} CrDuration;


/// 时间范围
typedef struct
{
    /// 开始时间
    CrTimePoint start;
    /// 结束时间
    CrTimePoint end;
} CrTimeRange;
