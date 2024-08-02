#pragma once

#include "basic.h"

/// 网络地址/端点
typedef struct
{
    /// 主机名
    char host[124];
    /// 主机端口号
    U32 port;
} CrEndpoint;

/// 认证信息
typedef struct
{
    /// 用户名
    char user[32];
    /// 用户密码
    char password[32];
} CrAuthInfo;
