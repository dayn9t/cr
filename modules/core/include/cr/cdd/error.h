#pragma once

#include "basic.h"


/// 没有错误
#define CXR_OK					        0x0000
/// 未知错误
#define CXR_UNKNOWN_ERR					0x0001
/// 违反契约错误
#define CXR_DBC_ERR					    0x0002

/// STL异常
#define CXR_STD_EXCEPTION				0x0011
/// 未知异常
#define CXR_UNKNOWN_EXCEPTION			0x0012

/// C接口返回的错误信息
typedef struct CrErrorImp {
    /// 错误编号
    int code;
    /// 错误程序所在行号
    int line;
    /// 错误相关数据
    int data[2];
    /// 错误程序所在文件
    const char *file;
    /// 错误相关文本信息, 必须是静态生命周期
    const char *message;
} CrError;
