#pragma once

#include "basic.h"

/// 主机名最大长度
#define CR_HOST_MAX_LEN 124
/// 用户名最大长度
#define CR_USER_MAX_LEN 16
/// 密码最大长度
#define CR_PASSWORD_MAX_LEN 16

/// 网络地址/端点
typedef struct CrEndpointCS
{
    /// 主机名
    char host[CR_HOST_MAX_LEN];
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
