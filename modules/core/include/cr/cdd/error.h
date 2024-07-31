#pragma once

#include "basic.h"

/// CR错误代码 - 正常/无错
#define CRC_OK					        0x0000
/// CR错误代码 - 未知
#define CRC_UNKNOWN_ERR					0x0001
/// CR错误代码 - 违反契约
#define CRC_DBC_ERR					    0x0002

/// CR错误代码 - STL异常
#define CRC_STD_EXCEPTION				0x0011
/// CR错误代码 - 未知异常
#define CRC_UNKNOWN_EXCEPTION			0x0012

/// C接口返回的错误信息
typedef struct CrErrorImp {
    /// 错误编号
    U32 code;
    /// 错误程序所在行号
    U32 line;
    /// 错误相关数据
    I32 data[2];
    /// 错误程序所在文件
    const char *file;
    /// 错误相关文本信息, 必须是静态生命周期
    const char *message;
} CrError;

