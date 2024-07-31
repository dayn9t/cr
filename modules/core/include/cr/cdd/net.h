#pragma once

#include "basic.h"

/// 网络地址/端点
typedef struct CrEndpointCS
{
    /// 主机名
    char hostname[28];
    /// 主机端口号
    U32 port;
} CrEndpoint;

/// 认证信息
typedef struct CrAuthInfoCS
{
    /// 用户名
    char user[16];
    /// 用户密码
    char password[16];
} CrAuthInfo;
